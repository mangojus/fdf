/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:16:45 by rshin             #+#    #+#             */
/*   Updated: 2025/03/10 22:28:51 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h> // remove

void	ft_bresenham(t_env *img)
{
	int	dx;
	int	dy;
	int x;
	int	y;
	int	i;
	int p;

	dx = x1 - x0;
	dy = y1 - y0;
	if	(dx != 0);
	{
		y = y0;
		p = 2*dy - dx;
		while (i <= dx)
		{
			set_pixel(x0 + i, y);
			i++;
			if (p >= 0)
			{
				y += 1;
				p = p - 2*dx;
			}
			else
				p = p + 2*dy;
		}
	}
}

void	set_pixel(int x, int y, int color, t_env *img)
{
	int	offset;

	offset = (y * img->size_line) + (x * (img->bpp / 8));

	img->addr[offset] = color & 0xFF;
	img->addr[offset + 1] = (color >> 8) & 0xFF;
	img->addr[offset + 2] = (color >> 16) & 0xFF;
	img->addr[offset + 3] = (color >> 24) & 0xFF;
}

void	ft_render_map(int **map, int row, int col, t_env *img)
{
	int	x;
	int y;
	int color;

	y = 0;
	while (y < row)
	{
		x = 0;
		while (x < col)
		{
			if (map[y][x] == 0)
				color = 0xFF0000;
			else
				color = 0xFFFFFF;
			ft_bresenham(x , y * 60, color, img);
			x++;
		}
		y++;	
	}
}
/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
*/

int	**ft_map_fill(char *str, int *row, int *col)
{
	int		**map;
	char	**tab;
	char	**tmp;
	int		y;
	int		x;

	y = 0;
	map = malloc(*(row) * sizeof(int *));
	tab = ft_split(str, '\n');
	while (tab[y])
	{
		map[y] = malloc(10 * sizeof(int)); // hardcoded size
		tmp = ft_split(tab[y], ' ');
		x = 0;
		while (tmp[x])
		{
			map[y][x] = ft_atoi(tmp[x]);
//			free(tmp[x]);
			x++;
		}
//		free(tmp);
		y++;
	}
	*col = x;
	free(tab);
	free(str);
	return (map);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_env	*img;
	char	*str;
	int		fd;
	char	*line;
	int		**map;
	int		row;
	int		col;
//	int		x;
//	int		y;

	fd = open("maps/10-2.fdf", O_RDONLY);
	str = "";
	line = "";
	row = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			str = ft_strjoin(str, line); //free problem
			row++;
			free(line);
			line = "";
		}
	}
	close(fd);
	map = ft_map_fill(str, &row, &col);
/*	x = 0;
	y = 0;
	while (y < row)
	{
		x = 0;
		while (x < col)
		{
			printf("%d ", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}*/
	mlx = mlx_init();
/*	if (mlx == NULL)
		return (NULL);*/
	mlx_win = mlx_new_window(mlx, 600, 600, "test");
	img = malloc(sizeof(t_data));
	if (!img)
		return (1);
	img->img = mlx_new_image(mlx, 600, 600);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
	ft_render_map(map, row, col, img);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
	free(map);
	return (0);
}
/*
int	main(void)
{
	char	*line;
	int		fd;

	fd = open("tests/file.txt", O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free(line);
//			printf(GREEN"main : MEM free at %p\n"RESET, line);
			line = "";
		}
	}
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return (0);
}*/
