/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:37:47 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/16 15:52:23 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int found_last_char_pos;

	found_last_char_pos = ft_strstr(s1, s2) - s1 + ft_strlen(s2);
	if (found_last_char_pos > (int)n)
		return (NULL);
	return (ft_strstr(s1, s2));
}
