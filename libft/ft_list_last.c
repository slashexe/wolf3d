/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:40:39 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/23 14:40:41 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_liste	*ft_list_last(t_liste *begin_list)
{
	while (begin_list->next != 0)
		begin_list = begin_list->next;
	return (begin_list);
}
