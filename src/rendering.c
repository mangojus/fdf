/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:55:07 by rshin             #+#    #+#             */
/*   Updated: 2025/03/14 20:29:29 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scale_coordinates(t_point *p, t_env *env)
{
	double	scale_factor;
	double	scale_x;
	double	scale_y;
	int	tmp;
	int	angle;

	angle = 30;
	env->cam->cos_angle = cos(angle * M_PI / 180);
	env->cam->sin_angle = sin(angle * M_PI / 180);
	scale_x = W_WIDTH / env->map->col;
	scale_y = W_HEIGHT / env->map->row;
	if (scale_x < scale_y)
		scale_factor = scale_x;
	else
		scale_factor = scale_y;
	p->x *= scale_factor;
	p->y *= scale_factor;
	p->z *= 2;
	tmp = p->x;
	if (env->cam->angle != 0)
	{
		p->x = (tmp - p->y) * env->cam->cos_angle;
		p->y = (tmp + p->y) * env->cam->sin_angle - p->z;
	}
	p->x *= env->cam->zoom;
	p->y *= env->cam->zoom;
	p->x += (W_WIDTH / 2);
	p->y += (W_HEIGHT / 2);
}

void	ft_set_pixel(t_point p, t_env *env)
{
	int	offset;
	
	offset = (p.y * env->size_line) + (p.x * (env->bpp / 8));
	if (offset < env->size_line * W_HEIGHT)
    {
		env->addr[offset] = p.color & 0xFF;
		env->addr[offset + 1] = (p.color >> 8) & 0xFF;
		env->addr[offset + 2] = (p.color >> 16) & 0xFF;
	}
	else
		printf("Offset out of bounds!\n");
}

static t_point	ft_set_point(int x, int y, t_env *env)
{
	t_point	p;

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
	t_point	a;
	t_point b;

	ft_init_point(&a);
	while (a.y < map->row)
	{
		a.x = 0;
		while (a.x < map->col)
		{
			a = ft_set_point(a.x, a.y, env);
			if (a.x < map->col - 1)
			{
				b = ft_set_point(a.x + 1, a.y, env);
				ft_line_algo(a, b, env);
			}
			if (a.y < map->row - 1)
			{
				b = ft_set_point(a.x, a.y + 1, env);
				ft_line_algo(a, b, env);
			}
			a.x++;
		}
		a.y++;
	}
}

void	ft_render_map(t_env *env)
{
	env->img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
	if (!env->img)
		return ;
	env->addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line, &env->endian);
	ft_render_line(env, env->map);
//	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
