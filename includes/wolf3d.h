/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:33:37 by avinas            #+#    #+#             */
/*   Updated: 2018/06/24 19:06:31 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"
# include "math.h"
# include "stdio.h"
# include "libft.h"
# include "../libft/get_next_line.h"
# include "../includes/mlx.h"
# define HEIGHT 1200
# define WIDTH 2000

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	char				**worldmap;
	uint32_t			buffer[500][500];

	void				*img;
	int					*imgpointer;
	int					size_line;
	int					bpp;
	int					endian;
	void				*skybox;
	int					*imgsky;
	void				*wall;
	int					*imgwall;
	int					*imgwall_e;
	int					*imgwall_o;
	int					*imgwall_s;
	int					*imgwall_n;

	int					sky_sl;
	int					sky_bpp;
	int					sky_end;
	int					sky_h;
	int					sky_w;
	int					wall_sl;
	int					wall_bpp;
	int					wall_end;
	int					wall_h;
	int					wall_w;

	double				wall_x;
	double				camerax;
	double				rayposx;
	double				rayposy;
	double				raydirx;
	double				raydiry;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				deltadistx;
	double				deltadisty;
	double				sidedistx;
	double				sidedisty;
	double				perpwalldist;
	int					stepx;
	int					stepy;
	int					mapx;
	int					mapy;
	int					mapx_tmp;
	int					mapy_tmp;
	int					hit;
	int					side;
	int					lineheight;
	double				wallwidth;
	int					textheight;
	int					drawstart;
	int					drawend;

	double				movespeed;
	double				rotspeed;
	double				olddirx;
	double				olddiry;
	double				oldplanex;
	double				oldplaney;
	int					upkey;
	int					downkey;
	int					leftkey;
	int					rightkey;

	double				tex_x;
	double				tex_y;
	int					x;
	int					y;
	int					w;
	int					h;

	int					color;
	int					sizetmp;
	int					cpt;

}						t_env;

typedef	struct			s_color
{
	unsigned char		col[3];
}						t_color;

void					colorpick(t_env *e);
void					init_draw(t_env *e);
void					init_env(t_env *e);
void					draw(t_env *e);
void					ver_line(t_env *e);
int						close_win(t_env *e);
int						keyhooks(int key, t_env *e);
unsigned int			ft_getcolor(int i, double x, double y);
void					texturing(t_env *e);
void					key_up(t_env *e);
void					key_down(t_env *e);
void					key_right(t_env *e);
void					key_left(t_env *e);
void					revival(t_env *e);
int						open_file(t_env *e, char *file);
void					lepivert(int a, t_env *e);

#endif
