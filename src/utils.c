/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:04:52 by rshin             #+#    #+#             */
/*   Updated: 2025/03/17 18:18:11 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_all(void **str, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

size_t	ft_count_char(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

size_t	ft_count_word(char const *str)
{
	size_t	i;
	size_t	count;
	size_t	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (ft_iswhitespace(str[i]) == 0 && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}
