/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:44:15 by rshin             #+#    #+#             */
/*   Updated: 2025/03/19 15:10:14 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_swap_point(t_point *a, t_point *b)
{
	t_point	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_scale_coordinates(t_point *p, t_cam *cam)
{
	t_point	tmp;

	ft_init_point(&tmp);
	p->x *= cam->scale;
	p->y *= cam->scale;
	p->z *= cam->z_factor;
	p->x -= W_WIDTH / 2;
	p->y -= W_HEIGHT / 2;
	tmp.x = p->x;
	tmp.y = p->y;
	tmp.z = p->z;
	p->x = cos(cam->yaw) * tmp.x + sin(cam->yaw) * tmp.z;
	p->z = -sin(cam->yaw) * tmp.x + cos(cam->yaw) * tmp.z;
	tmp.y = cos(cam->pitch) * p->y - sin(cam->pitch) * p->z;
	tmp.z = sin(cam->pitch) * p->y + cos(cam->pitch) * p->z;
	tmp.x = cos(cam->roll) * p->x - sin(cam->roll) * p->y;
	p->y = sin(cam->roll) * p->x + cos(cam->roll) * tmp.y;
	p->x = tmp.x;
	p->x *= cam->zoom;
	p->y *= cam->zoom;
	p->x += W_WIDTH / 2;
	p->y += W_HEIGHT / 2;
	p->x += cam->x;
	p->y += cam->y;
}

static void	ft_bresenham_h(t_point a, t_point b, t_env *env)
{
	int	d;
	int	dir;
	int	dx;
	int	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	dir = 1;
	if (dy < 0)
		dir = -1;
	dy *= dir;
	if (dx != 0)
	{
		d = 2 * dy - dx;
		while (a.x <= b.x)
		{
			ft_set_pixel(a, env);
//			mlx_pixel_put(env->mlx, env->win, a.x, a.y, a.color);
			a.x++;
			if (d >= 0)
			{
				a.y += dir;
				d -= 2 * dx;
			}
			d += 2 * dy;
		}
	}
}

static void	ft_bresenham_v(t_point a, t_point b, t_env *env)
{
	int	d;
	int	dir;
	int	dx;
	int	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	dir = 1;
	if (dx < 0)
		dir = -1;
	dx *= dir;
	if (dy != 0)
	{
		d = 2 * dx - dy;
		while (a.y <= b.y)
		{
			ft_set_pixel(a, env);
//			mlx_pixel_put(env->mlx, env->win, a.x, a.y, a.color);
			a.y++;
			if (d >= 0)
			{
				a.x += dir;
				d -= 2 * dy;
			}
			d += 2 * dx;
		}
	}
}

void	ft_line_algo(t_point a, t_point b, t_env *env)
{
	ft_scale_coordinates(&a, env->cam);
	ft_scale_coordinates(&b, env->cam);
	if (abs(b.x - a.x) > abs(b.y - a.y))
	{
		if (a.x > b.x)
			ft_swap_point(&a, &b);
		ft_bresenham_h(a, b, env);
	}
	else
	{
		if (a.y > b.y)
			ft_swap_point(&a, &b);
		ft_bresenham_v(a, b, env);
	}
}
