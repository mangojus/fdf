/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:44:15 by rshin             #+#    #+#             */
/*   Updated: 2025/03/12 19:32:52 by rshin            ###   ########.fr       */
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
void	ft_draw_line_h(t_point p1, t_point p2, t_env *env)
{
	int	dx;
	int	dy;
	int	d;
	int	tmp;
	int	dir;

	ft_scale_coordinates(&p1, env);
	ft_scale_coordinates(&p2, env);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dy < 0)
		dir = -1;
	else
		dir = 1;
	dy *= dir;
	if (dx != 0)
	{
		tmp = p1.y;
		d = 2*dy - dx;;
		while (p1.x <= p2.x)
		{
			ft_set_pixel(p1, env);
			p1.x++;
			if (d >= 0)
			{
				p1.y += dir;
				d = d - 2*dx;
			}
			d = d + 2*dy;
		}
		p1.y = tmp;
	}
}

void	ft_draw_line_v(t_point p1, t_point p2, t_env *env)
{
	int	dx;
	int	dy;
	int	d;
	int	tmp;
	int	dir;

	ft_scale_coordinates(&p1, env);
	ft_scale_coordinates(&p2, env);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dx < 0)
		dir = -1;
	else
		dir = 1;
	dx *= dir;
	if (dy != 0)
	{
		tmp = p1.x;
		d = 2*dx - dy;;
		while (p1.y <= p2.y)
		{
			ft_set_pixel(p1, env);
			p1.y++;
			if (d >= 0)
			{
				p1.x += dir;
				d = d - 2*dy;
			}
			d = d + 2*dx;
		}
		p1.y = tmp;
	}
}
