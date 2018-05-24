/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:14:35 by avinas            #+#    #+#             */
/*   Updated: 2018/04/30 19:01:15 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	key_up(t_env *e)
{
	int x;
	int y;

	x = (int)(e->posx + e->dirx * e->movespeed);
	y = (int)(e->posy + e->diry * e->movespeed);
	if (e->upkey == 1)
	{
		if (e->worldmap[x][y] == '0')
		{
			e->posx += e->dirx * e->movespeed;
			e->posy += e->diry * e->movespeed;
			revival(e);
		}
	}
}

void	key_down(t_env *e)
{
	int x;
	int y;

	x = (int)(e->posx - e->dirx * e->movespeed);
	y = (int)(e->posy - e->diry * e->movespeed);
	if (e->downkey == 1)
	{
		if (e->worldmap[x][y] == '0')
		{
			e->posx -= e->dirx * e->movespeed;
			e->posy -= e->diry * e->movespeed;
			revival(e);
		}
	}
}

void	key_right(t_env *e)
{
	if (e->rightkey == 1)
	{
		e->olddirx = e->dirx;
		e->dirx = e->dirx * cos(-e->rotspeed) - e->diry * sin(-e->rotspeed);
		e->diry = e->olddirx * sin(-e->rotspeed) + e->diry * cos(-e->rotspeed);
		e->oldplanex = e->planex;
		e->planex = e->planex * cos(-e->rotspeed) -
		e->planey * sin(-e->rotspeed);
		e->planey = e->oldplanex * sin(-e->rotspeed) +
		e->planey * cos(-e->rotspeed);
		revival(e);
	}
}

void	key_left(t_env *e)
{
	if (e->leftkey == 1)
	{
		e->olddirx = e->dirx;
		e->dirx = e->dirx * cos(e->rotspeed) - e->diry * sin(e->rotspeed);
		e->diry = e->olddirx * sin(e->rotspeed) + e->diry * cos(e->rotspeed);
		e->oldplanex = e->planex;
		e->planex = e->planex * cos(e->rotspeed) - e->planey * sin(e->rotspeed);
		e->planey = e->oldplanex * sin(e->rotspeed) +
		e->planey * cos(e->rotspeed);
		revival(e);
	}
}

void	revival(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->imgpointer = (int*)mlx_get_data_addr(e->img,
	&(e->bpp), &(e->size_line), &(e->endian));
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->skybox, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
