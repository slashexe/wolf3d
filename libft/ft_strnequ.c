/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:11:21 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/16 17:25:03 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((n == 0) || !s1 || !s2)
		return (1);
	while (*s1 == *s2)
	{
		if (*s1 == 0 || --n == 0)
			return (1);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2 == 0);
}
