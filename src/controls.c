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
	if (*keycode == TOP)
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
	if (*keycode == ARROW_LEFT)
		cam->x -= 100;
	if (*keycode == ARROW_RIGHT)
		cam->x += 100;
	if (*keycode == ARROW_UP)
		cam->y -= 100;
	if (*keycode == ARROW_DOWN)
		cam->y += 100;
	if (*keycode == NUM_4)
		cam->y_ax -= 5;
	if (*keycode == NUM_6)
		cam->y_ax += 5;
	if (*keycode == NUM_7)
		cam->z_ax += 5;
	if (*keycode == NUM_9)
		cam->z_ax -= 5;
	if (*keycode == NUM_8)
		cam->x_ax += 5;
	if (*keycode == NUM_2)
		cam->x_ax -= 5;
	if (*keycode == ZOOM_IN && cam->zoom < 100)
		cam->zoom *= 1.5;
	if (*keycode == ZOOM_OUT && cam->zoom > 0.1)
		cam->zoom /= 1.5;
}

int	ft_key_controls(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keycode == PG_UP)
		env->cam->z_factor -= 1;
	if (keycode == PG_DOWN)
		env->cam->z_factor += 1;
	printf("%d\n", keycode);
	ft_view_presets(&keycode, env->cam);
	ft_movement_controls(&keycode, env->cam);
	if (keycode == ESC_KEY)
	{
		ft_free_all(env);
		exit(0);
	}
	ft_render_map(env);
	return (0);
}

int	ft_mouse_controls(int button, int x, int y, void *param)
{
	t_env	*env;

	(void)x;
	(void)y;
	env = (t_env *)param;
	if (button == 5)
	{
		if (env->cam->zoom > 0.1)
		env->cam->zoom /= 1.5;
	}
	if (button == 4)
		env->cam->zoom *= 1.5;
	ft_render_map(env);
	return (0);
}

void	ft_hook_controls(t_env *env)
{
	mlx_key_hook(env->win, ft_key_controls, (void *)env);
	mlx_mouse_hook(env->win, ft_mouse_controls, (void *)env);
	mlx_hook(env->win, 17, 0, ft_close_win, (void *)env);
}
