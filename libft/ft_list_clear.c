/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:40:18 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/23 14:40:19 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_liste **begin_list)
{
	while (*begin_list)
	{
		free(*begin_list);
		(*begin_list) = (*begin_list)->next;
	}
	*begin_list = NULL;
}
