#include "../includes/wolf3d.h"

/*
**valeur pour mur = autre texture
*/
void			map(t_env *e)
{
	e->worldmap[0] = "1111111111";
	e->worldmap[1] = "1003000201";
	e->worldmap[2] = "1003000201";
	e->worldmap[3] = "1100000001";
	e->worldmap[4] = "1000330001";
	e->worldmap[5] = "1000033001";
	e->worldmap[6] = "1004004001";
	e->worldmap[7] = "1104444001";
	e->worldmap[8] = "1000000001";
	e->worldmap[9] = "1111111111";
}

void	lepivert(int a)
{
	if (a == 2)
		exit(1);
	else
		ft_putendl("Controls:\nArrow Keys & WASD to Move\n");
}

int		close_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(EXIT_SUCCESS);
}

void	gestion_win(t_env *e)
{
	init_env(e);
	init_draw(e);
	draw(e);

	mlx_put_image_to_window(e->mlx, e->win, e->skybox, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->floors, 0, 300);
	mlx_put_image_to_window(e->mlx, e->win, e->wall, 150, 250);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);

	mlx_hook(e->win, 2, 1L<<0, keyhooks, e);
	//mlx_loop_hook(e->mlx, loop, e);
	mlx_loop(e->mlx);
}

int		main(int argc, char **argv)
{
	t_env		*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
			return (0);
	argv = NULL;
	if (argc < 1)
	{
		ft_putendl("error: Not Enough Arguments");
		lepivert(2);
	}
	if (argc > 1)
	{
		ft_putendl("error: Too Enough Arguments");
		lepivert(2);
	}
	if (argc == 1)
	{
		init_env(e);
		map(e);
		lepivert(1);
		gestion_win(e);
	}
	return (0);
}
