/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:37:55 by rshin             #+#    #+#             */
/*   Updated: 2025/02/05 16:55:58 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void	ft_dlstadd_front(t_dlst **lst, t_dlst *new)
{
	if (lst)
	{
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}
	else if (!lst)
		*lst = new;
}
