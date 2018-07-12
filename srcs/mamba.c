/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mamba.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:14:35 by avinas            #+#    #+#             */
/*   Updated: 2018/06/24 20:32:02 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			colorpick(t_env *e)
{
	char tmp;

	tmp = e->worldmap[e->mapx][e->mapy];
	if (tmp == '1')
		e->color = 0x00FFFF;
	else if (tmp == '2')
	{
		e->color = 0x0000FF;
	}
	else if (tmp == '3')
		e->color = 0x9400D3;
	else if (tmp == '4')
		e->color = 0xFF8C00;
	else if (tmp == '0')
		e->color = 0x008080;
}

void			set_texture(t_env *e)
{
	e->tex_y = 0;
	if (e->side == 0)
		e->wall_x = e->posy + e->perpwalldist * e->raydiry;
	else
		e->wall_x = e->posx + e->perpwalldist * e->raydirx;
	e->wall_x -= floor(e->wall_x);
	if (e->mapx_tmp != e->mapx || e->mapy_tmp != e->mapy)
	{
		e->tex_x = 0;
	}
	if (e->tex_x > e->wall_w)
		e->tex_x = 0;
	if (e->drawstart < 0)
		e->tex_y = abs(e->drawstart) * (1 / (double)(e->lineheight)) * 256;
	e->tex_x = e->wall_x * (double)(e->wall_w);
}

void			ver_line(t_env *e)
{
	int		x;
	int		y;

	if (e->drawend > HEIGHT)
		e->drawend = HEIGHT - 1;
	y = 0;
	x = -1;
	while (++x < (HEIGHT / 2))
		e->imgpointer[e->x + (x * e->size_line / 4)] = 0xC00000AA;
	x = 0;
	set_texture(e);
	while (++y < e->drawend)
	{
		if (y > e->drawstart)
		{
			e->color = e->imgwall[(int)(e->tex_x) + (int)(e->tex_y) * 256];
			e->imgpointer[e->x + (y * e->size_line / 4)] = e->color;
			e->tex_y = e->tex_y + (1 / (double)(e->lineheight)) * 256;
		}
	}
	x = e->drawend - 1;
	e->mapx_tmp = e->mapx;
	e->mapy_tmp = e->mapy;
}

void			texturing(t_env *e)
{
	if (e->side)
	{
		if (e->posy < e->mapy)
			e->imgwall = e->imgwall_s;
		else
			e->imgwall = e->imgwall_n;
	}
	else
	{
		if (e->posx < e->mapx)
			e->imgwall = e->imgwall_e;
		else
			e->imgwall = e->imgwall_o;
	}
}
