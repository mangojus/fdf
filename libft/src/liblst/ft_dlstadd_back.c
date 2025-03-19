/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:38:12 by rshin             #+#    #+#             */
/*   Updated: 2025/02/26 20:16:09 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void	ft_dlstadd_back(t_dlst **lst, t_dlst *new)
{
	t_dlst	*last;

	if (*lst)
	{
		last = ft_dlstlast(*lst);
		last->next = new;
		new->prev = last;
	}
	else if (!*lst)
		*lst = new;
}
