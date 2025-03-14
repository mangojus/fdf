/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:30:46 by rshin             #+#    #+#             */
/*   Updated: 2025/03/14 14:41:34 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fd_close_win(t_env *env)
{
	int		x;
	int		y;
	env
}

void	ft_hook_controls(t_env *env)
{
	mlx_key_hook(env->win, ft_key_hook ,env->mlx); 
}
