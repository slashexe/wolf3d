/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:40:47 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/25 16:03:10 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Trie liste en comparant par ordre croissant
**le contenu de la liste,
**
**@params **begin_list
**      liste fournie
**@params (*cmp)
**      fonction compare
*/

t_liste	*ft_list_merge(t_liste **list1, t_liste *list2)
{
	t_liste	*current;
	t_liste	*ret;

	if (list1 == NULL && list2 == NULL)
		return (*list1);
	if (*list1 == NULL)
		return (list2);
	if (list2 == NULL)
		return (*list1);
	current = *list1;
	ret = current;
	while (current->next)
	{
		current = current->next;
	}
	current->next = list2;
	ret = current;
	return (ret);
}
