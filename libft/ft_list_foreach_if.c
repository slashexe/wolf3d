/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:39:54 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/23 14:39:56 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**applique une fonction donnée  à l'info  dans certain maillon
**
**@params *begin_list
**		liste fournie
**@params (*f)
**		fonction
*/

void	ft_list_foreach_if(t_liste *begin_list,
		void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_liste	*current;

	current = begin_list;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
			f(current->data);
		current = current->next;
	}
}
