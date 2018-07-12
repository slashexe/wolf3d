/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:42:21 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/13 17:37:33 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	n;

	n = ft_strlen(s1);
	ret = ft_strnew(n);
	if (!ret)
		return (NULL);
	while (n--)
		ret[n] = s1[n];
	return (ret);
}
