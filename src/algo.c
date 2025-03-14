/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:44:15 by rshin             #+#    #+#             */
/*   Updated: 2025/03/14 20:22:38 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static void	ft_swap_point(t_point *a, t_point *b)
{
	t_point	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
*/
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
		d = 2*dy - dx;
		while (a.x <= b.x)
		{
			ft_set_pixel(a, env);
			mlx_pixel_put(env->mlx, env->win, a.x, a.y, a.color);
			a.x++;
			if (d >= 0)
			{
				a.y += dir;
				d -= 2*dx;
			}
			d += 2*dy;
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
		d = 2*dx - dy;
		while (a.y <= b.y)
		{
			ft_set_pixel(a, env);
			mlx_pixel_put(env->mlx, env->win, a.x, a.y, a.color);
			a.y++;
			if (d >= 0)
			{
				a.x += dir;
				d -= 2*dy;
			}
			d += 2*dx;
		}
	}
}

void	ft_line_algo(t_point a, t_point b, t_env *env)
{
	ft_scale_coordinates(&a, env);
	ft_scale_coordinates(&b, env);
	if (abs(b.x - a.x) > abs(b.y - a.y))
	{
		if (a.x > b.x)
		{
//			ft_swap_point(&a, &b);
			ft_swap_value(&a.x, &b.x);
			ft_swap_value(&a.y, &b.y);
		}
		ft_bresenham_h(a, b, env);
	}
	else
	{
		if (a.y > b.y)
		{
//			ft_swap_point(&a, &b);
			ft_swap_value(&a.x, &b.x);
			ft_swap_value(&a.y, &b.y);
		}
		ft_bresenham_v(a, b, env);
	}
}

