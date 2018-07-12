/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:44:05 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/13 18:28:31 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*ret;

	ret = dest;
	while (*src != '\0' && n > 0)
	{
		*ret++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*ret++ = '\0';
		n--;
	}
	return (dest);
}
