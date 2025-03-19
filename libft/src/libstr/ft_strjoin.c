/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:39:39 by rshin             #+#    #+#             */
/*   Updated: 2025/03/19 16:29:39 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*start;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	dst = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	start = dst;
	if (s1)
	{
		while (*s1)
			*dst++ = *s1++;
	}
	if (s2)
	{
		while (*s2)
			*dst++ = *s2++;
	}
	*dst = '\0';
	return (start);
}
