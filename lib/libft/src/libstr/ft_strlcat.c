/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:02:01 by rshin             #+#    #+#             */
/*   Updated: 2024/11/30 13:05:09 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	keep_len;

	if (size == 0)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	keep_len = len;
	if (size <= len)
		return (ft_strlen(src) + size);
	i = 0;
	while (src[i] && len < (size - 1))
	{
		dst[len] = src[i];
		len++;
		i++;
	}
	dst[len] = '\0';
	return (ft_strlen(src) + keep_len);
}
