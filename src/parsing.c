/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:16:33 by rshin             #+#    #+#             */
/*   Updated: 2025/03/11 23:57:38 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_read_map(t_map *map, int fd)
{
	char	*line;
	char	*dst;

	line = "";
	dst = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			dst = ft_strjoin(dst, line);
			if (dst == NULL)
				return (free(dst), NULL);
			map->row++;
			free(line);
			line = "";
		}
	}
//	map->row = ft_count_char(dst, '\n'); (if map->row++ works!)
	return (dst);
}

static void	ft_convert_map(t_map *map, char *str)
{
	char	**tmp;
	char	**num;
	int		x;
	int		y;
	
	tmp = ft_split(str, '\n');
	free(str);
	map->col = ft_count_word(tmp[0]);
	map->matrix = malloc(map->row * sizeof(int *));
	y = 0;
	while (tmp[y])
	{
		x = 0;
		map->matrix[y] = malloc(map->col * sizeof(int));
		num = ft_split(tmp[y], ' ');
		while (num[x])
		{
			map->matrix[y][x] = ft_atoi(num[x]);
			x++;
		}
		y++;
	}
	ft_free_all(tmp);
	ft_free_all(num);
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

void	ft_parse_map(t_map *map, int fd)
{
	char	*str;

	ft_init_map(map);
	str = ft_read_map(map, fd);
	close(fd);
	if (str == NULL)
		return ;
	ft_convert_map(map, str);
	ft_compute_range(map);
}

