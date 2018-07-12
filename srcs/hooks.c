/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:14:35 by avinas            #+#    #+#             */
/*   Updated: 2018/04/30 17:30:14 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		keyhooks(int key, t_env *e)
{
	if (!(e->win))
		return (0);
	if (key == 53)
		close_win(e);
	else if (key == 126 && e->hit)
	{
		e->upkey = 1;
		key_up(e);
	}
	else if (key == 125)
	{
		e->downkey = 1;
		key_down(e);
	}
	else if (key == 124)
	{
		e->rightkey = 1;
		key_right(e);
	}
	else if (key == 123)
	{
		e->leftkey = 1;
		key_left(e);
	}
	return (0);
}
