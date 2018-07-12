/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:40:06 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/23 14:40:07 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**renvoie le n-ième élément de la liste
**
**@params *begin_list
**		liste fournie
**@params nbr
**		numéro a delete
**
**@return la list a jour
*/

t_liste	*ft_list_at(t_liste *begin_list, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	if (begin_list == 0)
		return (0);
	while (i < nbr)
	{
		begin_list = begin_list->next;
		if (begin_list == 0)
			return (0);
		i++;
	}
	return (begin_list);
}
