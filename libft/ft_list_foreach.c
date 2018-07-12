/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:39:47 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/23 14:39:50 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**applique une fonction donnée  à l'info  de chaque maillon
**
**@params *begin_list
**		liste fournie
**@params (*f)
**		fonction
*/

void	ft_list_foreach(t_liste *begin_list, void (*f)(void *))
{
	t_liste	*current;

	current = begin_list;
	while (current)
	{
		f(current->data);
		current = current->next;
	}
}
