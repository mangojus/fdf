/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:16:33 by rshin             #+#    #+#             */
/*   Updated: 2025/03/19 15:58:29 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_read_map(t_map *map, int fd)
{
	char	*line;
	char	*dst;
	char	*tmp;

	line = "";
	dst = NULL;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			tmp = dst;
			dst = ft_strjoin(tmp, line);
			if (dst == NULL)
			{
				free(line);
				free(tmp);
				return (NULL);
			}
			free(tmp);
			map->row++;
			free(line);
			line = "";
		}
	}
	return (dst);
}

static t_map	*ft_convert_map(t_map *map, char *str)
{
	char	**tmp;
	char	**num;
	int		x;
	int		y;
	
	tmp = ft_split(str, '\n');
	if (tmp == NULL)
		return (NULL); //free to figure
	free(str);
	map->col = ft_count_word(tmp[0]);
	map->matrix = malloc(map->row * sizeof(int *));
	if (map->matrix == NULL)
		return (NULL);
	y = 0;
	while (tmp[y])
	{
		x = 0;
		map->matrix[y] = malloc(map->col * sizeof(int));
		if (map->matrix[y] == NULL)
			return (ft_free_pptr((void **)map->matrix, map->row), NULL);
			 // maybe y + 1 instead of row
		num = ft_split(tmp[y], ' ');
		while (num[x])
		{
			map->matrix[y][x] = ft_atoi(num[x]);
			x++;
		}
		y++;
		ft_free_pptr((void **)num, map->col + 1); //improper free when wrong
	}
	ft_free_pptr((void **)tmp, map->row + 1); //improper free when wrong
	return (map);
}

static void	ft_compute_range(t_map *map)
{
	int		value;
	int		x;
	int		y;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			value = map->matrix[y][x];
			if (value > map->max)
				map->max = value;
			if (value < map->min)
				map->min = value;
			x++;
		}
		y++;
	}
}

t_map	*ft_parse_map(t_env *env, int fd)
{
	char	*buf;

	buf = ft_read_map(env->map, fd);
	close(fd);
	if (buf == NULL)
		return (ft_free_all(env), NULL);
	env->map = ft_convert_map(env->map, buf);
	if (env->map == NULL)
		return (ft_free_all(env), NULL);
	ft_compute_range(env->map);
	return (env->map);
}
