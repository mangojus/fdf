/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:19:56 by rshin             #+#    #+#             */
/*   Updated: 2025/02/27 19:00:02 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_dlst	*ft_dlstnew(int content)
{
	t_dlst	*new;

	new = malloc(sizeof(t_dlst));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
