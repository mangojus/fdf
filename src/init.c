/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:22:52 by rshin             #+#    #+#             */
/*   Updated: 2025/03/19 18:36:24 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	*ft_init_env(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (env == NULL)
		return (NULL);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "fdf");
	if (env->mlx == NULL || env->win == NULL)
		ft_free_all(env);
	env->img = NULL;
	env->addr = NULL;
	env->bpp = 0;
	env->size_line = 0;
	env->endian = 0;
	env->map = ft_init_map();
	env->cam = ft_init_cam();
	if (env->map == NULL || env->cam == NULL)
		ft_free_all(env);
	return (env);
}

t_map	*ft_init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->matrix = NULL;
	map->row = 0;
	map->col = 0;
	map->max = 0;
	map->min = 0;
	return (map);
}

t_cam	*ft_init_cam(void)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (cam == NULL)
		return (NULL);
	if (W_WIDTH > W_HEIGHT)
		cam->scale = (W_WIDTH / 2);
	else
		cam->scale = (W_HEIGHT / 2);
	cam->x = 0;
	cam->y = 0;
	cam->z_factor = 5;
	cam->x_ax = 30;
	cam->y_ax = 0;
	cam->z_ax = 30;
	cam->yaw = cam->y_ax * M_PI / 180;
	cam->pitch = cam->x_ax * M_PI / 180;
	cam->roll = cam->z_ax * M_PI / 180;
	cam->zoom = 0.5f;
	return (cam);
}

void	ft_init_point(t_point *p)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->color = 0xFFFFFF;
}
