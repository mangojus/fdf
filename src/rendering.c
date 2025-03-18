/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:55:07 by rshin             #+#    #+#             */
/*   Updated: 2025/03/18 01:03:57 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_pixel(t_point p, t_env *env)
{
	int	offset;
	
	offset = (p.y * env->size_line) + (p.x * (env->bpp / 8));
	if (p.x < 0 || p.y < 0)
		return ;
	else if (offset < env->size_line * W_HEIGHT)
    {
		env->addr[offset] = p.color & 0xFF;
		env->addr[offset + 1] = (p.color >> 8) & 0xFF;
		env->addr[offset + 2] = (p.color >> 16) & 0xFF;
	}
//	else
//		printf("Offset out of bounds!\n"); //remove
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

static void	ft_scale_img(t_env *env, t_cam *cam)
{
	if (cam->scale_x < cam->scale_y)
		cam->scale = cam->scale_x;
	else
		cam->scale = cam->scale_y;
	cam->cx = env->map->col / 2;
	cam->cy = env->map->row / 2;
	cam->yaw = cam->y_ax * M_PI / 180;
	cam->pitch = cam->x_ax * M_PI / 180;
	cam->roll = cam->z_ax * M_PI / 180;
//	cam->scale = (W_HEIGHT * env->size_line / 4);
}

void	ft_render_map(t_env *env)
{
	ft_bzero(env->addr, W_WIDTH * W_HEIGHT * (env->bpp / 8));
	if (env->img)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_clear_window(env->mlx, env->win);
	}
	env->img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
	if (!env->img)
		return ;
	env->addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line, &env->endian);
	ft_scale_img(env, env->cam);
	ft_render_line(env, env->map);
//	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
