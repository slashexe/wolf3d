/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:54:25 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/13 17:13:33 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*in1;
	const unsigned char	*in2;

	in1 = s1;
	in2 = s2;
	while (n--)
	{
		if (*in1 != *in2)
			return (*in1 - *in2);
		in1++;
		in2++;
	}
	return (0);
}
