#include "../includes/wolf3d.h"

int		read_file(int fd, t_env *e, int y, char *line)
{
	int			cpt;
	int			cptmp;
	int			size;
    
    size = 0;
    cpt = 0;
	while (--y)
	{
		if (get_next_line(fd, &line) == 1)
		{
			if (y == 3)
			{
				size = ft_atoi(line);
				if (size < 3)
					return (0);
			}
			else if (y == 2)
				e->posx = ft_atoi(line) + 0.1;
			else
				e->posy = ft_atoi(line) + 0.1;
		}
		else
        {
            ft_strdel(&line);
			return (0);
        }
        ft_strdel(&line);
	}
	cptmp = -1;
	e->worldmap = (char**)malloc(sizeof(char*) * size);
	while (get_next_line(fd, &line) == 1)
	{
		if (y == size)
			return (0);
		cpt = 0;
		while (line[cpt] != '\0')
		{
			if (!(line[cpt] == '0' || line[cpt] == '1'))
            {
                ft_strdel(&line);
				return (0);
            }
			if (y == 0 && line[cpt] != '1')
            {
                ft_strdel(&line);
                return (0);
            }
			if (y == size - 1 && line[cpt] != '1')
            {
                ft_strdel(&line);
                return (0);
            }
			cpt++;
		}
		if ((cpt != cptmp && cptmp != -1) || cpt == 0)
			return (0);
		cptmp = cpt;
		if (line[cpt - 1] == '0' || line[0] == '0')
			return (0);
		e->worldmap[y] = ft_strdup(line);
        ft_strdel(&line);
		y++;
	}
	if (!(e->posy < size && e->posy > 0 && e->posx < cpt && e->posx > 0))
		return (0);
	printf("posx: %f ||\nposy: %f ||\n pos: %c ||\n", e->posx, e->posy, e->worldmap[(int)e->posy][(int)e->posx]);
	if (e->worldmap[(int)e->posx][(int)e->posy] != '0')
		return (0);
	return (1);
}

int		open_file(t_env *e, char *file)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	return (read_file(fd, e, 4, ""));
}
