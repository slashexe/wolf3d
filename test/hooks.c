#include "../includes/wolf3d.h"
/*
** *NUM	67
** +NUM	69
** /NUM	75
** -NUM	78
**
** LEFT	123
** RIGH 124
** DOWN	125
** UP	126
**
**
*/
/*int		mousehook(int mousekey, int x, int y, t_env *e)
{
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		if (mousekey == 5)
			zoomin(x, y, e);
		else if (mousekey == 4)
			zoomout(x, y, e);
		else if (mousekey == 1)
			e->maxinter += 5;
		else if (mousekey == 2)
		{
			if (exp->movemouse == 1)
				e->mouse = 0;
			else
				e->mouse = 1;
		}
		choice_fractol(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		revival(e);
	}
	return (0);
}*/


//up 	= 126
//down 	= 125
//right = 124
//left 	= 123
int		keyhooks(int key, t_env *e)
{
	if (!(e->win))
		return (0);
	if (key == 53)
	{
		ft_putstr("Closing");
		sleep(1);
		ft_putstr(".");
		sleep(1);
		ft_putstr(".");
		sleep(1);
		ft_putendl(".");
		close_win(e);
	}
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
	/*else if (key = 69)
		e->zoom *= pow(1.001, 70);
	else if (key = 78)
		e->zoom /= pow(1.001, 70);
	else if (key = 67)
		e->maxinter += 5;
	else if (key = 69)
		e->maxinter -= 5;
	////////////////////////////
	else if (key == 123)
		e->movex -= .2 / e->zoom;
	else if (key == 124)
		e->movex += .2 / e->zoom;
	else if (key == 125)
		e->movey -= .2 / e->zoom;
	else if (key == 126)
		e->movey += .2 / e->zoom;
	////////////////////////////
	if (key == 0)
	{
		e->color = 0x000000;
		revival(exp);
	}
	if (key == 0)
	{
		e->color = 5000;
		revival(e);
	}
	if (key == 0)
	{
		e->color += 50;
		revival(e);
	}
	if (key == 0)
	{
		e->color -= 10;
		revival(e);
	}
	whichfractol(e);*/
}
/*

void			revival(t_env *e)
	{
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_destroy_image(e->mlx, e->img);
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->imgpointer = mlx_get_data_addr(e->img, 
			&(e->bpp), &(e->size_line), &(e->endian));
		init_env(e);
		choice_fractol(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		toString(e);
	}*/