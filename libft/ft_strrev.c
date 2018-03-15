/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:35:57 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/12 17:43:57 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

char		*ft_strrev(char *s)
{
	int	c;
	int	n;

	if (s[0] == '-' || s[0] == '+')
		c = 1;
	else
		c = 0;
	n = (ft_strlen(s) - 1);
	while (s[c])
	{
		if (c == n)
			return (s);
		swap(&s[c], &s[n]);
		if (n == c + 1)
			return (s);
		c++;
		n--;
	}
	return (s);
}
