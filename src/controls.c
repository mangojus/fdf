/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:30:46 by rshin             #+#    #+#             */
/*   Updated: 2025/03/11 16:53:07 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fd_close_win(t_env *env)
{
	int		x;
	int		y;
	env
}

void	ft_key_hooks(t_env *env)
{
	if (keycode == ESCAPE)
		ft_close_win(env);
	mlx_key_hook(env->win, ft_key_hook ,env->mlx); 
}
