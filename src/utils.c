/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:04:52 by rshin             #+#    #+#             */
/*   Updated: 2025/03/19 15:27:38 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_all(t_env *env)
{
	if (env->cam)
		free(env->cam);
	if (env->map)
	{
		ft_free_pptr((void **)env->map->matrix, env->map->row);
		free(env->map);
	}
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	env->cam = NULL;
	env->map = NULL;
	env->img = NULL;
	env->win = NULL;
	env->mlx = NULL;
	env->win = NULL;
	free(env);
}

int	ft_close_win(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	ft_free_all(env);
	exit (0);
}

size_t	ft_count_char(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

size_t	ft_count_word(char const *str)
{
	size_t	i;
	size_t	count;
	size_t	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (ft_iswhitespace(str[i]) == 0 && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}
