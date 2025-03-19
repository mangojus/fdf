/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:28:52 by rshin             #+#    #+#             */
/*   Updated: 2025/03/19 18:25:55 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_view_top(t_cam *cam)
{
	cam->x_ax = 0;
	cam->y_ax = 0;
	cam->z_ax = 0;
	cam->yaw = cam->y_ax * M_PI / 180;
	cam->pitch = cam->x_ax * M_PI / 180;
	cam->roll = cam->z_ax * M_PI / 180;
}

void	ft_view_front(t_cam *cam)
{
	cam->x_ax = 90;
	cam->y_ax = 0;
	cam->z_ax = 0;
	cam->yaw = cam->y_ax * M_PI / 180;
	cam->pitch = cam->x_ax * M_PI / 180;
	cam->roll = cam->z_ax * M_PI / 180;

}

void	ft_view_side(t_cam *cam)
{
	cam->x_ax = 0;
	cam->y_ax = 90;
	cam->z_ax = 0;
	cam->yaw = cam->y_ax * M_PI / 180;
	cam->pitch = cam->x_ax * M_PI / 180;
	cam->roll = cam->z_ax * M_PI / 180;
}

void	ft_view_iso(t_cam *cam)
{
	cam->x_ax = 30;
	cam->y_ax = 0;
	cam->z_ax = 30;
	cam->yaw = cam->y_ax * M_PI / 180;
	cam->pitch = cam->x_ax * M_PI / 180;
	cam->roll = cam->z_ax * M_PI / 180;
}

void	ft_view_reset(t_cam *cam)
{
	free(cam);
	cam = ft_init_cam();
}
