/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:54:39 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/04 17:54:42 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_pop(t_list **list)
{
	void *content;

	if (!*list)
		return (NULL);
	temp = *list;
	if (*list->next)
	{
		pop = list;
		*list = *list->next;

	}
	return (*list);
}
