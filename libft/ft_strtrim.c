/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:36:07 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/16 16:32:37 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int				fin;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	fin = (int)ft_strlen(s) - 1;
	while (ft_isspace(s[i]) && s[i])
		i++;
	while (ft_isspace(s[fin]) && s[fin] && fin > (int)i)
		fin--;
	return (ft_strsub(s, i, (fin - i + 1)));
}
