/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:24:01 by rshin             #+#    #+#             */
/*   Updated: 2025/03/19 18:24:32 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <stdio.h> //remove
# include <math.h>

# define W_WIDTH 1600
# define W_HEIGHT 900

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362

# define NUM_4 65430
# define NUM_6 65432
# define NUM_8 65431
# define NUM_2 65433
# define NUM_7 65429
# define NUM_9 65434

# define TOP 49
# define FRONT 50
# define SIDE 51
# define ISO 52
# define RESET 114

# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ZOOM_IN 65451
# define ZOOM_OUT 65453

# define ESC_KEY 65307
# define DESTROY 17

# define PG_UP 65365
# define PG_DOWN 65366

typedef struct s_map
{
	int		**matrix;
	int		row;
	int		col;
	int		max;
	int		min;
}	t_map;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_point;

typedef struct s_cam
{
	double	x;
	double	y;
	double	scale;
	double	z_factor;
	double	x_ax;
	double	y_ax;
	double	z_ax;
	double	yaw;
	double	pitch;
	double	roll;
	float	zoom;
}	t_cam;

typedef struct s_env
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
}	t_env;

t_env	*ft_init_env(void);
t_map	*ft_init_map(void);
t_cam	*ft_init_cam(void);
void	ft_init_point(t_point *p);
t_map	*ft_parse_map(t_env *env, int fd);
void	ft_render_map(t_env *env);
void	ft_line_algo(t_point p1, t_point p2, t_env *env);
void	ft_hook_controls(t_env *env);
void	ft_scale_coordinates(t_point *p, t_cam *cam);
void	ft_set_pixel(t_point p, t_env *env);
void	ft_view_top(t_cam *cam);
void	ft_view_front(t_cam *cam);
void	ft_view_side(t_cam *cam);
void	ft_view_iso(t_cam *cam);
void	ft_view_reset(t_cam *cam);
int		ft_key_controls(int keycode, void *param);
int		ft_mouse_controls(int button, int x, int y, void *param);
void	ft_free_all(t_env *env);
int		ft_close_win(void *param);
size_t	ft_count_char(char const *str, char c);
size_t	ft_count_word(char const *str);
#endif
