/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:31:46 by rshin             #+#    #+#             */
/*   Updated: 2025/03/13 18:57:03 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(void)
{
	t_env	*env;
	int	fd;

	fd = open("./4x4.fdf", O_RDONLY);
	if (fd == -1)
		return (1);
	env = malloc(sizeof(t_env));
	if (env == NULL)
		return (1);
	ft_init_env(env);
	ft_parse_map(env->map, fd);
	env->mlx = mlx_init();
	if (env->mlx == NULL)
		return (1);
	env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "fdf");
	if (env->win == NULL)
		return (1);
	ft_render_map(env);
	mlx_loop(env->mlx);
	return (0);
}
/*
int		main(int argc, char **argv)
{
	t_env	*env;
	int	fd;

	if (argc != 2)
		return (1);
//	fd = open(argv[1], O_RDONLY);
	fd = open("./maps/10-2.fdf", O_RDONLY);
	if (fd == -1)
		return (1);
	env = NULL;
	ft_init_env(env);
	ft_parse_map(env->map, fd);
	env->mlx = mlx_init();
	if (env->mlx == NULL)
		return (1);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "fdf");
	if (env->win == NULL)
		return (1);
	ft_render_map(env);
//	ft_controls(env)
	mlx_loop(env->mlx);
//	ft_destroy_all(t_env *env);
	return (0);
}*/
