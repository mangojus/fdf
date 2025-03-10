/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlsthead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:57:53 by rshin             #+#    #+#             */
/*   Updated: 2025/02/05 16:59:19 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_dlst	*ft_dlsthead(t_dlst *lst)
{
	t_dlst	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}
