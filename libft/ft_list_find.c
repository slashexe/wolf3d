/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:40:31 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/23 14:40:34 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**@params *begin_list
**			liste fournie
**@params (*cmp)
**			fonction de comparaison
**@params *data_ref
**			data a comparer
**
**@return	l'adresse du premier maillon dont la donnée est égale a la
**			donné de référence
*/

t_liste	*ft_list_find(t_liste *begin_list, void *data_ref, int (*cmp)())
{
	t_liste	*current;

	current = begin_list;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
