/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:41:20 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/23 14:41:21 by rlauret          ###   ########.fr       */
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

static	void	ft_list_rev(t_liste *current, t_liste *prev, t_liste **list)
{
	t_liste *next;

	if (!current->next)
	{
		*list = current;
		current->next = prev;
		return ;
	}
	next = current->next;
	current->next = prev;
	ft_list_rev(next, current, list);
}

void			ft_list_reverse(t_liste **begin_list)
{
	if (!*begin_list)
		return ;
	ft_list_rev(*begin_list, NULL, begin_list);
}
