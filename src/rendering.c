/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:55:07 by rshin             #+#    #+#             */
/*   Updated: 2025/03/12 00:43:06 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_set_pixel(t_point p, t_cam *cam, t_env *env)
{
	size_t	offset;

	p.y *= cam->zoom;
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

static void	ft_render_point(t_env *env, t_map *map)
{
	t_point	p;

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
			ft_set_pixel(p, env->cam, env);
			p.x++;
		}
		p.y++;
	}
}

void	ft_render_map(t_env *env)
{
	env->img = mlx_new_image(env->mlx, 800, 600);
	if (!env->img)
		return ;
	env->addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line, &env->endian);
	ft_render_point(env, env->map);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
