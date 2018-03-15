/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:28:29 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/16 16:22:49 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ret;

	if (!s || (int)len < 0)
		return (NULL);
	ret = malloc(sizeof(char) * (len + 1));
	if (ret)
	{
		while (start--)
			s++;
		ft_strncpy(ret, s, len);
		ret[len] = '\0';
	}
	return (ret);
}
