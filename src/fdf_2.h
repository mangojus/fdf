typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
	int	width;
	int	height;
	int	color;
	t_map	*point;
	t_map	*map;
	t_cam	*cam;	
}				t_env;

typedef struct	s_cam
{
	float	x;
	float	y;
	float	zoom;
}				t_cam;

typedef struct	s_map;
{
	int	**matrix;
	int	row;
	int	col;
	int	max;
	int	min;
}				t_map;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;
