/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:34:00 by rshin             #+#    #+#             */
/*   Updated: 2025/03/03 22:44:37 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

static int	ft_count_nbr(long n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_ltoa(long n)
{
	char	*dst;
	size_t	count;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	count = ft_count_nbr(n);
	dst = ft_calloc((count + 1), sizeof(char));
	if (dst == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		dst[0] = '-';
	}
	while (n > 0)
	{
		dst[--count] = (n % 10) + '0';
		n = n / 10;
	}
	return (dst);
}
