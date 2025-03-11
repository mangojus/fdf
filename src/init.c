/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:22:52 by rshin             #+#    #+#             */
/*   Updated: 2025/03/12 00:43:44 by rshin            ###   ########.fr       */
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
	env->width = 0;
	env->height = 0;
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
	cam->x = 0;
	cam->y = 0;
	cam->zoom = 50;
}

void	ft_init_point(t_point *p)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->color = 0xFFFFFF;
}
