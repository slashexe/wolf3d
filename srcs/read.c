/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:14:35 by avinas            #+#    #+#             */
/*   Updated: 2018/05/01 15:04:40 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			create_map(int fd, t_env *e, int *y, char *line)
{
	e->sizetmp = 0;
	e->cpt = 0;
	while (--*y)
	{
		if (get_next_line(fd, &line) == 1)
		{
			if (*y == 3)
			{
				e->sizetmp = ft_atoi(line);
				if (e->sizetmp < 3)
					return (0);
			}
			else if (*y == 2)
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
	return (1);
}

static int	del_line(char **line)
{
	ft_strdel(line);
	return (0);
}

static int	check_it(int y, int cptmp, t_env *e, char *line)
{
	if (y == e->sizetmp)
		return (0);
	e->cpt = -1;
	while (line[++e->cpt] != '\0')
	{
		if (!(line[e->cpt] == '0' || line[e->cpt] == '1'))
			return (del_line(&line));
		if (y == 0 && line[e->cpt] != '1')
			return (del_line(&line));
		if (y == e->sizetmp - 1 && line[e->cpt] != '1')
			return (del_line(&line));
	}
	if ((e->cpt != cptmp && cptmp != -1) || e->cpt == 0)
		return (0);
	return (1);
}

int			read_file(int fd, t_env *e, int y, char *line)
{
	int			cptmp;

	if (!create_map(fd, e, &y, line))
		return (0);
	cptmp = -1;
	if (!(e->worldmap = (char**)malloc(sizeof(char*) * e->sizetmp)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		if (!check_it(y, cptmp, e, line))
			return (0);
		cptmp = e->cpt;
		if (line[e->cpt - 1] == '0' || line[0] == '0')
			return (0);
		e->worldmap[y++] = ft_strdup(line);
		ft_strdel(&line);
	}
	if (!(e->posy < e->sizetmp && e->posy > 0
				&& e->posx < e->cpt && e->posx > 0))
		return (0);
	if (e->worldmap[(int)e->posx][(int)e->posy] != '0')
		return (0);
	return (1);
}

int			open_file(t_env *e, char *file)
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
