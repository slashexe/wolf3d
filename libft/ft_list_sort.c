/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:41:36 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/23 14:41:38 by rlauret          ###   ########.fr       */
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

void	ft_list_sort(t_liste **begin_list, int (*cmp)())
{
	t_liste	*current;
	int		link;

	link = 1;
	if (*begin_list == NULL)
		return ;
	current = *begin_list;
	while (link)
	{
		link = 0;
		current = *begin_list;
		while (current->next)
		{
			if (cmp(current->data, current->next->data) > 0)
			{
				ft_ptrswap(&current->data, &current->next->data);
				link = 1;
			}
			current = current->next;
		}
	}
}
