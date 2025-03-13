/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:44:15 by rshin             #+#    #+#             */
/*   Updated: 2025/03/13 20:29:25 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void	ft_isometric_projection(t_point *p, t_env *env)
{
	p->iso_x = (p->x - p->y) * cos(M_PI / 6);
	p->iso_y = (p->x + p->y) * sin(M_PI / 6) - p->z;
}
*/
void	ft_draw_line_h(t_point p0, t_point p1, t_env *env)
{
	int	dx;
	int	dy;
	int	d;
	int	i;
	int	y;
	int	dir;

	ft_scale_coordinates(&p0, env);
	ft_scale_coordinates(&p1, env);
	if (p0.x > p1.x)
	{
		ft_swap_value(&p0.x, &p1.x);
		ft_swap_value(&p0.y, &p1.y);
	}
	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	if (dy < 0)
		dir = -1;
	else
		dir = 1;
	dy *= dir;
	if (dx != 0)
	{
		y = p0.y;
		d = 2*dy - dx;
		i = 0;
		while (i <= dx)
		{
//			ft_set_pixel(p1, env);
			mlx_pixel_put(env->mlx, env->win, p0.x + i, y, p0.color);
			i++;
			if (d >= 0)
			{
				y += dir;
				d -= 2*dx;
			}
			d += 2*dy;
		}
	}
}

void	ft_draw_line_v(t_point p0, t_point p1, t_env *env)
{
	int	dx;
	int	dy;
	int	d;
	int	i;
	int	x;
	int	dir;

	ft_scale_coordinates(&p0, env);
	ft_scale_coordinates(&p1, env);
	if (p0.y > p1.y)
	{
		ft_swap_value(&p0.x, &p1.x);
		ft_swap_value(&p0.y, &p1.y);
	}
	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	if (dx < 0)
		dir = -1;
	else
		dir = 1;
	dx *= dir;
	if (dy != 0)
	{
		x = p0.x;
		d = 2*dx - dy;
		i = 0;
		while (i <= dy)
		{
//			ft_set_pixel(p1, env);
			mlx_pixel_put(env->mlx, env->win, x, p0.y + i, p0.color);
			i++;
			if (d >= 0)
			{
				x += dir;
				d -= 2*dy;
			}
			d += 2*dx;
		}
	}
}
