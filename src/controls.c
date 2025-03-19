/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:30:46 by rshin             #+#    #+#             */
/*   Updated: 2025/03/19 18:26:59 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_view_presets(int *keycode, t_cam *cam)
{
	if (*keycode == TOP) // || button == something
		ft_view_top(cam);
	if (*keycode == FRONT)
		ft_view_front(cam);
	if (*keycode == SIDE)
		ft_view_side(cam);
	if (*keycode == ISO)
		ft_view_iso(cam);
	if (*keycode == RESET)
		ft_view_reset(cam);
}

void	ft_movement_controls(int *keycode, t_cam *cam)
{
	if (*keycode == ARROW_LEFT || *keycode == KEY_A)
		cam->x -= 100;
	if (*keycode == ARROW_RIGHT || *keycode == KEY_D)
		cam->x += 100;
	if (*keycode == ARROW_UP || *keycode == KEY_W)
		cam->y -= 100;
	if (*keycode == ARROW_DOWN || *keycode == KEY_S)
		cam->y += 100;
	if (*keycode == NUM_4)
		cam->y_ax -= 5;
	if (*keycode == NUM_6)
		cam->y_ax += 5;
	if (*keycode == KEY_Q || *keycode == NUM_7)
		cam->z_ax += 5;
	if (*keycode == KEY_E || *keycode == NUM_9)
		cam->z_ax -= 5;
	if (*keycode == PG_UP || *keycode == NUM_8)
		cam->x_ax += 5;
	if (*keycode == PG_DOWN || *keycode == NUM_2)
		cam->x_ax -= 5;
	if (*keycode == ZOOM_IN && cam->zoom < 100)
		cam->zoom *= 1.5;
	if (*keycode == ZOOM_OUT && cam->zoom > 0.1)
		cam->zoom /= 1.5;
}

int	ft_close_win(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	ft_free_all(env);
	exit(0);
}

int	ft_key_controls(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keycode == KEY_X)
		env->cam->z_factor -= 1;
	if (keycode == KEY_C)
		env->cam->z_factor += 1;
	printf("%d\n", keycode);
	ft_view_presets(&keycode, env->cam);
	ft_movement_controls(&keycode, env->cam);
	if (keycode == ESC_KEY || keycode == DESTROY)
		ft_close_win(env);
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
