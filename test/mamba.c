/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mamba.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:14:35 by avinas            #+#    #+#             */
/*   Updated: 2018/05/16 18:06:24 by avinas           ###   ########.fr       */
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

unsigned int	ft_getcolor(int i, double x, double y)
{
	unsigned int	color;
	double			tmp;
	double			a;
	t_color			str_color;

	tmp = sqrt(x * x + y * y);
	a = i + 1 - (log(2) / tmp) / log(2);
	str_color.col[0] = (unsigned char)(sin(0.026 * a + 4) * 230 + 25);
	str_color.col[1] = (unsigned char)(sin(0.023 * a + 2) * 230 + 25);
	str_color.col[2] = (unsigned char)(sin(0.01 * a + 1) * 230 + 25);
	color = (str_color.col[0] << 16) + (str_color.col[1] << 8) +
	(str_color.col[2] + 255);
	return (color);
}

void			ver_line(t_env *e)
{
	int		y;
	int		x;

	if (e->drawend > HEIGHT)
		e->drawend = HEIGHT - 1;
	y = e->drawstart;
	if (y < 0)
		y = 0;
	x = -1;
	while (++x < (HEIGHT / 2))
		e->imgpointer[e->x + (x * e->size_line / 4)] = 0xC00000AA;
	x = 0;
	while (++y < e->drawend)
	{
		e->imgpointer[e->x + (y * e->size_line / 4)] = e->imgwall
		[(int)(((int)(e->x) % e->wall_sl) + ((int)(y) * e->wall_sl % 3600))];
	}
	x = e->drawend - 1;
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
