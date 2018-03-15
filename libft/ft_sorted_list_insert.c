/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:42:33 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/23 14:42:35 by rlauret          ###   ########.fr       */
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

void	ft_sorted_list_insert(t_liste **begin_list, void *data, int (*cmp)())
{
	t_liste	*current;

	ft_list_push_back(begin_list, data);
	current = *begin_list;
	ft_list_sort(&current, cmp);
}
