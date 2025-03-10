/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:52:07 by rshin             #+#    #+#             */
/*   Updated: 2024/12/04 13:10:59 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

static size_t	ft_check_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	j = 0;
	while (set[j] && i != 0)
	{
		if (s1[i - 1] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static size_t	ft_check_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_check_start(s1, set);
	end = ft_check_end(s1, set);
	if (end <= start)
		return (ft_calloc(1, sizeof(char)));
	dst = malloc((end - start + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		dst[i] = ((char *)s1)[start];
		i++;
		start++;
	}
	dst[i] = 0;
	return (dst);
}
