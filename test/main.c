/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:14:35 by avinas            #+#    #+#             */
/*   Updated: 2018/04/01 15:14:37 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
**valeur pour mur = autre texture
*/
void	lepivert(int a, t_env *e)
{
	if (a == 2)
    {
        free(e->worldmap);
        e->worldmap = NULL;
        free(e);
        e = NULL;
        exit(1);
    }
	else
		ft_putendl("Controls:\nArrow Keys to Move\n");
}

int		close_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
    free(e->worldmap);
    e->worldmap = NULL;
    free(e);
    e = NULL;
	exit(EXIT_SUCCESS);
}

void	gestion_win(t_env *e)
{
	init_env(e);
	init_draw(e);
	draw(e);

	mlx_put_image_to_window(e->mlx, e->win, e->skybox, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_hook(e->win, 17, 0, close_win, e);
	mlx_hook(e->win, 2, 1L<<0, keyhooks, e);
	//mlx_loop_hook(e->mlx, loop, e);
	mlx_loop(e->mlx);
}

int		main(int argc, char **argv)
{
	t_env		*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
			return (0);
	if (argc < 2)
	{
		ft_putendl("error: Not Enough Arguments");
		lepivert(2, e);
	}
	if (argc > 2)
	{
		ft_putendl("error: Too much Arguments");
		lepivert(2, e);
	}
	if (open_file(e, argv[1]) == 0)
	{
		ft_putendl("error Map");
		lepivert(2, e);
	}
	if (argc == 2)
	{
		lepivert(1, e);
		gestion_win(e);
	}
	return (0);
}
