/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:59:32 by rshin             #+#    #+#             */
/*   Updated: 2025/02/03 20:04:19 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include "libstr.h"
# include <stdarg.h>

// FT_PRINTF

enum e_type
{
	CHAR_TYPE,
	STR_TYPE,
	INT_TYPE,
	UINT_TYPE,
	LONG_UINT_TYPE,
	HEX_LOW_TYPE,
	HEX_UPP_TYPE
};

int	ft_printf(const char *format, ...);

// TYPES

int	ft_print_char(enum e_type type, va_list *args);
int	ft_print_num(enum e_type type, va_list *args);
int	ft_print_ptr(va_list *args);
int	ft_print_hex(enum e_type type, va_list *args);

#endif
