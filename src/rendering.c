/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:55:07 by rshin             #+#    #+#             */
/*   Updated: 2025/03/12 19:52:13 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_scale_img(t_env *env, t_cam *cam)
{
	env->img_width = WIDTH * 1 / 3;
	env->img_height = HEIGHT * 1 / 3;
	cam->angle = 30;
	cam->cos_angle = cos(cam->angle * M_PI / 180);
	cam->sin_angle = sin(cam->angle * M_PI / 180);
	cam->x_shift = (WIDTH - env->img_width) / 2;
	cam->y_shift = (HEIGHT - env->img_height) / 2;
}

void	ft_scale_coordinates(t_point *p, t_env *env)
{
	double	scale_factor;
	double	scale_x;
	double	scale_y;

	scale_x = (env->img_width / env->map->col);
	scale_y = (env->img_height / env->map->row);
	if (scale_x < scale_y)
		scale_factor = scale_x;
	else
		scale_factor = scale_y;
//	p->x *= (env->img_width / env->map->col);
//	p->y *= (env->img_height / env->map->row);
	p->x *= scale_factor;
	p->y *= scale_factor;
	p->x = (p->x - p->y) * env->cam->cos_angle;
	p->y = (p->x + p->y) * env->cam->sin_angle - p->z;
	p->x += (env->img_width / 2);
	p->y += (env->img_height / 2);
	if (p->y < 0)
		p->y = 0;
}

void	ft_set_pixel(t_point p, t_env *env)
{
	size_t	offset;

//	p.y *= cam->zoom;
	offset = (p.y * env->size_line) + (p.x * (env->bpp / 8));

	env->addr[offset] = p.color & 0xFF;
	env->addr[offset + 1] = (p.color >> 8) & 0xFF;
	env->addr[offset + 2] = (p.color >> 16) & 0xFF;
}
/*
int	ft_interpolate_color(t_map *map, int min_color, int max_color, )
{
	int	range;
//	int	step; 

	range = map->max - map->min;
	if (range == 0)
		return (0x000000);
	int	red = 
	
}
*/
static t_point	ft_set_point(int x, int y, t_env *env)
{
	t_point	p;

	ft_init_point(&p);
	p.x = x;
	p.y = y;
	p.z = env->map->matrix[y][x];
	if (p.z == 0)
		p.color = 0xFF0000;
	else
		p.color = 0xFFFFFF;
	return (p);
}

static void	ft_render_line(t_env *env, t_map *map)
{
	t_point	p1;
	t_point	p2;

	ft_init_point(&p1);
	while (p1.y < map->row)
	{
		p1.x = 0;
		while (p1.x < map->col)
		{
			p1 = ft_set_point(p1.x, p1.y, env);
			if (p1.x < map->col - 1)
			{
				p2 = ft_set_point(p1.x + 1, p1.y, env);
				ft_draw_line_h(p1, p2, env);
			}
			if (p1.y < map->row - 1)
			{
				p2 = ft_set_point(p1.x, p1.y + 1, env);
				ft_draw_line_v(p1, p2, env);
			}
			p1.x++;
		}
		p1.y++;
	}
}
/*
static void	ft_render_point(t_env *env, t_map *map)
{
	t_point	p1;
	t_point	p2;

	ft_init_point(&p);
	while (p.y < map->row)
	{
		p.x = 0;
		while (p.x < map->col)
		{
			p.z = map->matrix[p.y][p.x];
//			color = ft_interpolate_color(map, 0x0000FF, 0xFF0000)
			if (p.z == 0)
				p.color = 0xFF0000;
			else
				p.color = 0xFFFFFF;
//			ft_set_pixel(p, env);
			if (map->matrix[p.y][p.x + 1])
				ft_bresenham(p1, p2, env);
			p.x++;
		}
		p.y++;
	}
}
*/
void	ft_render_map(t_env *env)
{
	ft_scale_img(env, env->cam);
	env->img = mlx_new_image(env->mlx, env->img_width, env->img_height);
	if (!env->img)
		return ;
	env->addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line, &env->endian);
	ft_render_line(env, env->map);
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->cam->x_shift, env->cam->y_shift);
}
