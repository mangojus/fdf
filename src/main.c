/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:31:46 by rshin             #+#    #+#             */
/*   Updated: 2025/03/19 18:29:55 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
int	main(void)
{
	int fd;
	char *line;
	char *dst;

	line = "";
	dst = "";
	fd = open("./maps/42.fdf", O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			dst = ft_strjoin(dst, line);
			free (line);
			line = "";
		}
	}
	free (dst);
	return (0);
}
*//*
int		main(void)
{
	t_env	*env;
	int	fd;

	fd = open("./maps/42.fdf", O_RDONLY);
	if (fd == -1)
		return (1);
	env = ft_init_env();
	if (env == NULL)
		return (1);
	env->map = ft_parse_map(env, fd);
	if (env->map == NULL)
		return (1);
	mlx_key_hook(env->win, ft_key_controls, (void *)env);
//	mlx_mouse_hook(env->win, ft_mouse_controls, (void *)env);
	mlx_hook(env->win, 17, 0, ft_close_win, (void *)env);
	ft_render_map(env);
	mlx_loop(env->mlx);
	return (0);
}
*/
int		main(int argc, char **argv)
{
	t_env	*env;
	int	fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	env = ft_init_env();
	if (env == NULL)
		return (1);
	env->map = ft_parse_map(env, fd);
	if (env->map == NULL)
		return (1);
	mlx_key_hook(env->win, ft_key_controls, (void *)env);
//	mlx_mouse_hook(env->win, ft_mouse_controls, (void *)env);
	mlx_hook(env->win, 17, 0, ft_close_win, (void *)env);
	ft_render_map(env);
	mlx_loop(env->mlx);
	return (0);
}
