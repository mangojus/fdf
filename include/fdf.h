/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:55:07 by rshin             #+#    #+#             */
/*   Updated: 2025/03/10 18:25:34 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "mlx.h"
# include "mlx_int.h"
//# include "./lib/libft/include/libft.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		**map;
	int		row;
	int		col;
	int		bpp; //bits_per_pixel
	int		size_line;
	int		endian;
}				t_data;

#endif
