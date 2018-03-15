#include "../includes/libft.h"
#include "../includes/get_next_line.h"

/*
**gestion de cam a faire plus tard si possible.
*/
static	int	read_opt(int argc, char **argv, t_env *e)
{
	if (argc < 2)
	{
		ft_putendl("not enought file");
		return (1);
	}
	if (open_file(e, argv[1]) == 0)
	{
		ft_putendl("error Map");
		return (1);
	}
	//gestion couleur parametre 3 verif bon encodage
	if (argc >= 3)
	{
		ft_putendl("error color");
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_env		*e;

	e = init_env();
	if (read_opt(argc, argv), e)
		return (0);



	
	mlx_expose_hook(e->win, expose_hook, &e);
	mlx_key_hook(e->win, my_key_func, e->mlx);
	
	draw(e);
	mlx_loop(e->mlx);
	return (0);
}
