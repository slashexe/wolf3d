/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:14:35 by avinas            #+#    #+#             */
/*   Updated: 2018/05/01 16:41:26 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_draw(t_env *e)
{
	e->dirx = -1;
	e->diry = 0;
	e->planex = 0;
	e->planey = 0.66;
	e->w = WIDTH;
	e->h = HEIGHT;
	e->textheight = 64;
	e->upkey = 0;
	e->downkey = 0;
	e->leftkey = 0;
	e->rightkey = 0;
	e->rotspeed = .1;
	e->movespeed = .2;
}

void	init_env(t_env *e)
{
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Wolf3D");
	e->skybox = mlx_xpm_file_to_image(e->mlx, "./texture/skybox.xpm",
			&(e->sky_w), &(e->sky_h));
	e->imgsky = (int*)mlx_get_data_addr(e->skybox, &(e->sky_bpp),
			&(e->sky_sl), &(e->sky_end));
	e->wall = mlx_xpm_file_to_image(e->mlx, "./texture/colorstone.xpm",
			&(e->wall_w), &(e->wall_h));
	e->imgwall_s = (int*)mlx_get_data_addr(e->wall, &(e->wall_bpp),
			&(e->wall_sl), &(e->wall_end));
	e->wall = mlx_xpm_file_to_image(e->mlx, "./texture/greystone.xpm",
			&(e->wall_w), &(e->wall_h));
	e->imgwall_n = (int*)mlx_get_data_addr(e->wall, &(e->wall_bpp),
			&(e->wall_sl), &(e->wall_end));
	e->wall = mlx_xpm_file_to_image(e->mlx, "./texture/purplestone.xpm",
			&(e->wall_w), &(e->wall_h));
	e->imgwall_e = (int*)mlx_get_data_addr(e->wall, &(e->wall_bpp),
			&(e->wall_sl), &(e->wall_end));
	e->wall = mlx_xpm_file_to_image(e->mlx, "./texture/redbrick.xpm",
			&(e->wall_w), &(e->wall_h));
	e->imgwall_o = (int*)mlx_get_data_addr(e->wall, &(e->wall_bpp),
			&(e->wall_sl), &(e->wall_end));
	e->imgpointer = (int*)mlx_get_data_addr(e->img,
			&(e->bpp), &(e->size_line), &(e->endian));
}
