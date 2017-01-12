/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:48:49 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/04 16:48:52 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strappchr(char *src, char c)
{
	char *dest;
	size_t len;

	if (!src || !*src)
	{
		dest = ft_strnew(1);
		dest[1] = c;
		return (dest);
	}
	len = ft_strlen(src);
	dest = ft_strnew(len + 1);
	dest = ft_strcpy(dest, src);
	dest[len] = c;
	ft_strdel(src);
	return (dest);
}
