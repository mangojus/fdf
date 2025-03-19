/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:33:54 by rshin             #+#    #+#             */
/*   Updated: 2025/02/03 19:28:46 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libalgo.h"

long	ft_fibonacci(size_t i)
{
	long	res;

	if (i == 0)
		return (0);
	if (i == 1)
		return (1);
	res = ft_fibonacci(i - 1) + ft_fibonacci(i - 2);
	return (res);
}
