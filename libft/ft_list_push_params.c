/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:41:07 by rlauret           #+#    #+#             */
/*   Updated: 2017/11/23 14:41:10 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**@params ac
**		nombre de av
**@params **av
**	chaine de caractere a passer dans la liste
**
**@return la nouvelle list cree
*/

t_liste	*ft_list_push_params(int ac, char **av)
{
	t_liste	*list;
	int		i;

	i = 1;
	if (ac < 1)
		return (NULL);
	list = ft_create_elem(av[0]);
	while (i < ac)
		ft_list_push_front(&list, av[i++]);
	return (list);
}
