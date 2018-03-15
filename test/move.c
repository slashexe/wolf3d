#include "../includes/wolf3d.h"

void	key_up(t_env *e)
{
	int x;
	int y;

	x = (int)(e->posx + e->dirx * e->movespeed);
	y = (int)(e->posy + e->diry * e->movespeed);
	printf("case: %d||%d\n", x, y);
	if (e->upkey == 1)
	{
		if (e->worldmap[x][y] == '0')
		{
			ft_putendl("up");
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
	printf("case: %d||%d\n", x, y);
	if (e->downkey == 1)
	{
		if (e->worldmap[x][y] == '0')
		{
			ft_putendl("down");
			e->posx -= e->dirx * e->movespeed;
			e->posy -= e->diry * e->movespeed;
			revival(e);
		}
	}
}

void	key_right(t_env *e)
{

	
	e->movespeed = 2;
}

void	key_left(t_env *e)
{
	e->movespeed = 2;
}

void	revival(t_env *e)
{
	//mlx_destroy_image(e->mlx, e->img);
	

	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);

	e->skybox = mlx_xpm_file_to_image(e->mlx, "./texture/skybox.xpm",
		&(e->sky_w), &(e->sky_h));
	e->imgsky = (int*)mlx_get_data_addr(e->skybox, &(e->sky_bpp),
		&(e->sky_sl), &(e->sky_end));

	e->floors = mlx_xpm_file_to_image(e->mlx, "./texture/floor.xpm",
		&(e->floor_w), &(e->floor_h));
	e->imgfloor = (int*)mlx_get_data_addr(e->floors, &(e->floor_bpp),
		&(e->floor_sl), &(e->floor_end));

	e->wall = mlx_xpm_file_to_image(e->mlx, "./texture/mossy.xpm",
		&(e->wall_w), &(e->wall_h));
	e->imgwall = (int*)mlx_get_data_addr(e->wall, &(e->wall_bpp),
		&(e->wall_sl), &(e->wall_end));

	e->imgpointer = (int*)mlx_get_data_addr(e->img, 
		&(e->bpp), &(e->size_line), &(e->endian));

	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->skybox, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->floors, 0, 300);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}