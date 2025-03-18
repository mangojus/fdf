/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:24:01 by rshin             #+#    #+#             */
/*   Updated: 2025/03/17 23:46:20 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <stdio.h> //remove
# include <math.h>

# define W_WIDTH 1920
# define W_HEIGHT 1080

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ZOOM_IN 65451
# define ZOOM_OUT 65453

# define ESC_KEY 65307

# define KEY_X 120
# define KEY_C 99
# define KEY_Q 113
# define KEY_E 101
# define PG_UP 65365
# define PG_DOWN 65366

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
	double	cx;
	double	cy;
	double	x;
	double	y;
	double	scale;
	double	scale_x;
	double	scale_y;
	double	z_factor;
	double	pitch;
	double	x_ax;
	double	y_ax;
	double	z_ax;
	double	yaw;
	double	roll;
	double	angle;
	double	cos_angle;
	double	sin_angle;
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
	t_map	*map;
	t_cam	*cam;	
}				t_env;

int		ft_key_controls(int keycode, void *param);
void	ft_close_win(t_env *env);
void	ft_scale_coordinates(t_point *p, t_cam *cam);
void	ft_set_pixel(t_point p, t_env *env);
void	ft_init_env(t_env *env);
void	ft_init_map(t_map *map);
void	ft_init_point(t_point *p);
void	ft_init_cam(t_cam *cam);
void	ft_parse_map(t_env *env, int fd);
void	ft_line_algo(t_point p1, t_point p2, t_env *env);
void	ft_render_map(t_env *env);
void	ft_free_all(void **str, int row);
size_t	ft_count_char(char const *str, char c);
size_t	ft_count_word(char const *str);
#endif
