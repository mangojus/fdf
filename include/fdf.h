/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:24:01 by rshin             #+#    #+#             */
/*   Updated: 2025/03/12 19:35:02 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <stdio.h> //remove
# include <math.h>

# define WIDTH 900
# define HEIGHT 900

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
	double	x;
	double	y;
	double	z;
	int	x_shift;
	int	y_shift;
	double	angle;
	double	cos_angle;
	double	sin_angle;
	
	double	zoom;
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
	int		img_width;
	int		img_height;
	t_map	*map;
	t_cam	*cam;	
}				t_env;

void	ft_scale_coordinates(t_point *p, t_env *env);
void	ft_set_pixel(t_point p, t_env *env);
void	ft_init_env(t_env *env);
void	ft_init_map(t_map *map);
void	ft_init_point(t_point *p);
void	ft_init_cam(t_cam *cam);
void	ft_parse_map(t_map *map, int fd);
void	ft_draw_line_h(t_point p1, t_point p2, t_env *env);
void	ft_draw_line_v(t_point p1, t_point p2, t_env *env);
void	ft_render_map(t_env *env);
void	ft_free_all(char **str);
size_t	ft_count_char(char const *str, char c);
size_t	ft_count_word(char const *str);
#endif
