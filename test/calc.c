#include "../includes/wolf3d.h"
/*
**calculate ray position and direction
**-x = coordinate in camera space
**-mapx/mapy = which box of the map we're in
**-delta = length of ray from one x or y-side to next x or y-side (pas le droit a abs())
**-hit = wall hit
*/
void	calc_ray(t_env *e)
{
	e->camerax = 2 * e->x / (double)e->w - 1;
	e->rayposx = e->posx;
	e->rayposy = e->posy;
	e->raydirx = e->dirx + e->planex * e->camerax;
	e->raydiry = e->diry + e->planey * e->camerax;
	e->mapx = (int)e->rayposx;
	e->mapy = (int)e->rayposy;
	e->deltadistx = sqrt(1 + (e->raydiry *
				e->raydiry) / (e->raydirx * e->raydirx));
	e->deltadisty = sqrt(1 + (e->raydirx *
				e->raydirx) / (e->raydiry * e->raydiry));
	e->hit = 0;
}

/*
**calculate step and initial sideDist
*/
void	calc_step(t_env *e)
{
	if (e->raydirx < 0)
	{
		e->stepx = -1;
		e->sidedistx = (e->rayposx - e->mapx) * e->deltadistx;
	}
	else
	{
		e->stepx = 1;
		e->sidedistx = (e->mapx + 1.0 - e->rayposx) * e->deltadistx;
	}
	if (e->raydiry < 0)
	{
		e->stepy = -1;
		e->sidedisty = (e->rayposy - e->mapy) * e->deltadisty;
	}
	else
	{
		e->stepy = 1;
		e->sidedisty = (e->mapy + 1.0 - e->rayposy) * e->deltadisty;
	}
}

/*
**perform DDA (digital diffential analyzer)
**loop increment square by square
*/
void	DDA(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->deltadistx;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->sidedisty += e->deltadisty;
			e->mapy += e->stepy;
			e->side = 1;
		}
		if (e->worldmap[e->mapx][e->mapy] != '0')
			e->hit = 1;
	}
}

/*
**1) calc distance from wall (Euclidean distance will give fisheye effect!)
**2) lineheight height of line to draw on screen
**3) pick a color
**4) x and y sides get different brightness
**5) draw the pixels of the stripe as a vertical line
*/
void	calc_other(t_env *e)
{
	if (e->side == 0)
	{
		e->perpwalldist = (e->mapx - e->rayposx +
				(1 - e->stepx) / 2) / e->raydirx;
	}
	else
	{
		e->perpwalldist = (e->mapy - e->rayposy +
				(1 - e->stepy) / 2) / e->raydiry;
		e->imgwall = e->imgwall_o;	
	}
	e->lineheight = (int)(e->h / e->perpwalldist);
	e->drawstart = -(e->lineheight) / 2 + e->h / 2;
	if (e->drawstart < 0)
		e->drawstart = 0;
	e->drawend = e->lineheight / 2 + e->h / 2;
	if (e->drawend >= e->h)
		e->drawend = e->h - 1;
	
	colorpick(e);
	if (e->side == 1)
	{
		e->color = e->color / 2;
	}
	texturing(e);
	ver_line(e);
}


void	draw(t_env *e)
{
	e->x = -1;
	while (++e->x < e->w)
	{
		calc_ray(e);
		calc_step(e);
		DDA(e);
		calc_other(e);
	}
}
