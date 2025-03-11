/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:24:01 by rshin             #+#    #+#             */
/*   Updated: 2025/03/11 23:29:54 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <stdio.h> //remove

# define WIDTH 800
# define HEIGHT 600

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ESC_KEY 53

typedef struct	s_map
{
	int	**matrix;
	int	row;
	int	col;
	int	max;
	int	min;
}				t_map;

typedef struct	s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}				t_point;

typedef struct	s_cam
{
	float	x;
	float	y;
	float	zoom;
}				t_cam;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	t_map	*map;
	t_cam	*cam;	
}				t_env;

void	ft_init_env(t_env *env);
void	ft_init_map(t_map *map);
void	ft_init_point(t_point *p);
void	ft_init_cam(t_cam *cam);
void	ft_parse_map(t_map *map, int fd);
void	ft_render_map(t_env *env);
void	ft_free_all(char **str);
size_t	ft_count_char(char const *str, char c);
size_t	ft_count_word(char const *str);
#endif
