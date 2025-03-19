/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:30:46 by rshin             #+#    #+#             */
/*   Updated: 2025/03/18 01:09:24 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_close_win(t_env *env)
{
	if (env->img)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = NULL;
	}
	if (env->win)
	{
		mlx_destroy_window(env->mlx, env->win);
		env->win = NULL;
	}
	ft_free_all((void **)env->map->matrix, env->map->row);
	free(env->map);
	free(env->cam);
	free(env);
	exit(0);
}

int	ft_key_controls(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	printf("%d\n", keycode);
	if (keycode == ESC_KEY)
		ft_close_win(env);
	if (keycode == ARROW_LEFT || keycode == KEY_A)
		env->cam->x -= 100;
	if (keycode == ARROW_RIGHT || keycode == KEY_D)
		env->cam->x += 100;
	if (keycode == ARROW_UP || keycode == KEY_W)
		env->cam->y -= 100;
	if (keycode == ARROW_DOWN || keycode == KEY_S)
		env->cam->y += 100;
	if (keycode == KEY_X)
		env->cam->z_factor -= 1;
	if (keycode == KEY_C)
		env->cam->z_factor += 1;
	if (keycode == NUM_4)
		env->cam->y_ax -= 5;
	if (keycode == NUM_6)
		env->cam->y_ax += 5;
	if (keycode == KEY_Q || keycode == NUM_7)
		env->cam->z_ax += 5;
	if (keycode == KEY_E || keycode == NUM_9)
		env->cam->z_ax -= 5;
	if (keycode == PG_UP || keycode == NUM_8)
		env->cam->x_ax += 5;
	if (keycode == PG_DOWN || keycode == NUM_2)
		env->cam->x_ax -= 5;
	if (keycode == ZOOM_IN && env->cam->zoom < 100)
		env->cam->zoom *= 1.5;
	if (keycode == ZOOM_OUT && env->cam->zoom > 0.1)
			env->cam->zoom /= 1.5;
	ft_render_map(env);
	return (0);
}



/*
int	ft_mouse_controls(int button, int x, int y, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (button == 1)
	{
		
	}
	if (button == 5)
	{
		if (env->cam->zoom > 2)
		env->cam->zoom /= 1.5;
	}
	if (button == 4)
	{
		env->cam->zoom *= 1.5;
	}
}*/
