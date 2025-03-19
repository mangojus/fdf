/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:22:52 by rshin             #+#    #+#             */
/*   Updated: 2025/03/18 00:26:26 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_env(t_env *env)
{
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	env->addr = NULL;
	env->bpp = 0;
	env->size_line = 0;
	env->endian = 0;
	env->map = malloc(sizeof(t_map));
	ft_init_map(env->map);
	env->cam = malloc(sizeof(t_cam));
	ft_init_cam(env->cam);
}

void	ft_init_map(t_map *map)
{
	map->matrix = 0;
	map->row = 0;
	map->col = 0;
	map->max = 0;
	map->min = 0;
}

void	ft_init_cam(t_cam *cam)
{
	if (W_WIDTH > W_HEIGHT)
		cam->scale = (W_WIDTH / 2);
	else
		cam->scale = (W_HEIGHT / 2);
	cam->x = 0;
	cam->y = 0;
	cam->z_factor = 2;
	cam->x_ax = 30;
	cam->y_ax = 45;
	cam->z_ax = 45;
	cam->yaw = cam->y_ax * M_PI / 180;
	cam->pitch = cam->x_ax * M_PI / 180;
	cam->roll = cam->z_ax * M_PI / 180;
	cam->zoom = 0.5f;
	cam->cos_angle = cos(cam->angle * M_PI / 180); 
	cam->sin_angle = sin(cam->angle * M_PI / 180); 
}

void	ft_init_point(t_point *p)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->color = 0xFFFFFF;
}
