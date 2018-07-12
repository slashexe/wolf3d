/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:14:35 by avinas            #+#    #+#             */
/*   Updated: 2018/06/24 19:22:03 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	calc_init(t_env *e)
{
	e->cam = 2 * e->x / (double)e->w - 1;
	e->raydirx = e->dirx + e->planex * e->cam;
	e->raydiry = e->diry + e->planey * e->cam;
	e->mapx = (int)e->posx;
	e->mapy = (int)e->posy;
	e->pointdistx = sqrt(1 + (e->raydiry *
				e->raydiry) / (e->raydirx * e->raydirx));
	e->pointdisty = sqrt(1 + (e->raydirx *
				e->raydirx) / (e->raydiry * e->raydiry));
	e->hit = 0;
}

static void	calc_dir(t_env *e)
{
	if (e->raydirx < 0)
	{
		e->yesx = -1;
		e->oridistx = (e->posx - e->mapx) * e->pointdistx;
	}
	else
	{
		e->yesx = 1;
		e->oridistx = (e->mapx + 1.0 - e->posx) * e->pointdistx;
	}
	if (e->raydiry < 0)
	{
		e->yesy = -1;
		e->oridisty = (e->posy - e->mapy) * e->pointdisty;
	}
	else
	{
		e->yesy = 1;
		e->oridisty = (e->mapy + 1.0 - e->posy) * e->pointdisty;
	}
}

static void	crash_test(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->oridistx < e->oridisty)
		{
			e->oridistx += e->pointdistx;
			e->mapx += e->yesx;
			e->side = 0;
		}
		else
		{
			e->oridisty += e->pointdisty;
			e->mapy += e->yesy;
			e->side = 1;
		}
		if (e->worldmap[e->mapx][e->mapy] != '0')
			e->hit = 1;
	}
}

static void	calc_other(t_env *e)
{
	if (e->side == 0)
	{
		e->walldist = (e->mapx - e->posx +
				(1 - e->yesx) / 2) / e->raydirx;
	}
	else
	{
		e->walldist = (e->mapy - e->posy +
				(1 - e->yesy) / 2) / e->raydiry;
		e->imgwall = e->imgwall_o;
	}
	e->lineheight = (int)(e->h / e->walldist);
	e->drawstart = -(e->lineheight) / 2 + e->h / 2;
	e->drawend = e->lineheight / 2 + e->h / 2;
	if (e->drawend >= e->h)
		e->drawend = e->h - 1;
	texturing(e);
	ver_line(e);
}

void		draw(t_env *e)
{
	e->x = -1;
	while (++e->x < e->w)
	{
		calc_init(e);
		calc_dir(e);
		crash_test(e);
		calc_other(e);
	}
}
