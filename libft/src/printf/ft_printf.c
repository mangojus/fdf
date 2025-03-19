/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:59:26 by rshin             #+#    #+#             */
/*   Updated: 2025/02/27 14:15:35 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_parsing_format(int len, const char *format, va_list *args)
{
	int	check_err;

	check_err = len;
	if (*format == 'c')
		len += ft_print_char(CHAR_TYPE, args);
	else if (*format == 's')
		len += ft_print_char(STR_TYPE, args);
	else if (*format == 'p')
		len += ft_print_ptr(args);
	else if (*format == 'd' || *format == 'i')
		len += ft_print_num(INT_TYPE, args);
	else if (*format == 'u')
		len += ft_print_num(UINT_TYPE, args);
	else if (*format == 'x')
		len += ft_print_hex(HEX_LOW_TYPE, args);
	else if (*format == 'X')
		len += ft_print_hex(HEX_UPP_TYPE, args);
	else if (*format == '%')
		len += write(1, "%", 1);
	else
		return (-1);
	if (len < check_err)
		return (-1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	if (!format)
		return (-1);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			len = ft_parsing_format(len, ++format, &args);
			if (len == -1)
				return (-1);
		}
		else
			len += write(1, &format[0], 1);
		format++;
	}
	va_end(args);
	return (len);
}
