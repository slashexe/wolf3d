/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:37:14 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/13 20:46:00 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	size;

	if (!*s2)
		return ((char*)s1);
	size = ft_strlen(s2);
	while (*s1)
	{
		if (ft_memcmp(s1++, s2, size) == 0)
			return ((char*)(s1 - 1));
	}
	return (NULL);
}
