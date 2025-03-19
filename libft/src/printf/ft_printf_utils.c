/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:24:14 by rshin             #+#    #+#             */
/*   Updated: 2025/03/03 23:11:10 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_char(enum e_type type, va_list *args)
{
	size_t	len;
	char	c;
	char	*str;

	len = 0;
	if (type == CHAR_TYPE)
	{
		c = va_arg(*args, int);
		len = write(1, &c, 1);
	}
	else if (type == STR_TYPE)
	{
		str = va_arg(*args, char *);
		if (str == NULL)
			return (len = write(1, "(null)", 6));
		len = write(1, str, ft_strlen(str));
	}
	return (len);
}

int	ft_print_ptr(va_list *args)
{
	void	*ptr;
	char	*str;
	int		len;

	len = 0;
	ptr = va_arg(*args, void *);
	if (ptr == NULL)
		return (len = write(1, "(nil)", 5));
	str = ft_ultoa_base((unsigned long)ptr, "0123456789abcdef");
	if (str == NULL)
		return (0);
	len += write(1, "0x", 2);
	len += write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	ft_print_num(enum e_type type, va_list *args)
{
	long long	nbr;
	char		*str;
	int			len;

	len = 0;
	if (type == INT_TYPE)
	{
		nbr = va_arg(*args, int);
		str = ft_itoa(nbr);
		len = write(1, str, ft_strlen(str));
		free(str);
	}
	else if (type == UINT_TYPE)
	{
		nbr = va_arg(*args, unsigned int);
		str = ft_ultoa(nbr);
		len = write(1, str, ft_strlen(str));
		free(str);
	}
	return (len);
}

int	ft_print_hex(enum e_type type, va_list *args)
{
	long long	res;
	char		*str;
	int			len;

	len = 0;
	res = va_arg(*args, unsigned int);
	if (type == HEX_LOW_TYPE)
	{
		str = ft_ultoa_base(res, "0123456789abcdef");
		len = write(1, str, ft_strlen(str));
		free(str);
	}
	else if (type == HEX_UPP_TYPE)
	{
		str = ft_ultoa_base(res, "0123456789ABCDEF");
		len = write(1, str, ft_strlen(str));
		free(str);
	}
	return (len);
}
