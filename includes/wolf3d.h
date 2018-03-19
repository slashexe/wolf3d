#ifndef WOLF3D_H
# define WOLF3D_H

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"
# include "math.h"
# include "stdio.h"
# include "libft.h"
# include "../minilibx_macos/mlx.h"

# define HEIGHT 500
# define WIDTH 500

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	char				*worldmap[10];
	uint32_t			buffer[500][500];

	/*
	**gestion image
	*/
	void				*img;
	int					*imgpointer;
	int					size_line;
	int					bpp;
	int					endian;
	/*
	**gestion texture
	*/
	void				*skybox;
	int					*imgsky;
	void				*floors;
	int					*imgfloor;
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
////////////////////////////////////
	int					floor_sl;
	int					floor_bpp;
	int					floor_end;
	int					floor_h;
	int					floor_w;
////////////////////////////////////
	int					wall_sl;
	int					wall_bpp;
	int					wall_end;
	int					wall_h;
	int					wall_w;

	/*
	**calcul
	*/
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
	int					hit;
	int					side;
	int					lineheight;
	int					textheight;
	int					drawstart;
	int					drawend;

	/*
	**calcul
	*/
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

	int					x;
	int					y;
	int					w;
	int					h;

	int					color;
}						t_env;

typedef	struct 			s_color
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
void	key_up(t_env *e);
void	key_down(t_env *e);
void	key_right(t_env *e);
void	key_left(t_env *e);
void	revival(t_env *e);

#endif
