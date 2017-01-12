/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:41:49 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/04 17:41:53 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pushback(t_list **list, t_list *new)
{
	t_list *current;
	current = *list;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	current->next->next = NULL;
}
