#include "../includes/wolf3d.h"

void			colorpick(t_env *e)
{
	char tmp;

	tmp = e->worldmap[e->mapx][e->mapy];
	if (tmp == '1')
		e->color = 0x00FFFF;
	else if (tmp == '2')
	{
		e->color = 0x0000FF;
	}
	else if (tmp == '3')
		e->color = 0x9400D3;
	else if (tmp == '4')
		e->color = 0xFF8C00;
	else if (tmp == '0')
		e->color = 0x008080;
}

unsigned int	ft_getcolor(int i, double x, double y)
{
	unsigned int	color;
	double			tmp;
	double			a;
	t_color			str_color;

	tmp = sqrt(x * x + y * y);
	a = i + 1 - (log(2) / tmp) / log(2);
	str_color.col[0] = (unsigned char)(sin(0.026 * a + 4) * 230 + 25);
	str_color.col[1] = (unsigned char)(sin(0.023 * a + 2) * 230 + 25);
	str_color.col[2] = (unsigned char)(sin(0.01 * a + 1) * 230 + 25);
	color = (str_color.col[0] << 16) + (str_color.col[1] << 8) + (str_color.col[2] + 255);
	return (color);
}

void			ver_line(t_env *e)
{
	int		y;
	int		roger;
	int		x;

	roger = e->drawend;
	if (roger > HEIGHT)
		roger = HEIGHT - 1;
	y = e->drawstart;
	if (y < 0)
		y = 0;
	x = -1;
	while (++x < (HEIGHT / 2))
		e->imgpointer[e->x + (x * e->size_line / 4)] = 0xC00000AA;
	while (++y < roger)
		e->imgpointer[e->x + (y * e->size_line / 4)] = ft_getcolor(e->
				color, e->x, y);
	x = roger - 1;
	while (++x < (HEIGHT - 1))
		e->imgpointer[e->x + (x * e->size_line / 4)] = 0xC00000AA;
}

void			texturing(t_env *e)
{
	int		textnum;
	int		textx;
	int		texty;
	int		y;
	int		d;
	double	wallx;
	uint32_t color;

	textnum = e->worldmap[e->mapx][e->mapy] - 1;
	if (e->side == 0) 
		wallx = e->posy + e->perpwalldist * e->raydiry;
	else           
		wallx = e->posx + e->perpwalldist * e->raydirx;
	wallx -= floor((wallx));

	textx = (int)(wallx * (double)(e->textheight));
	if(e->side == 0 && e->raydirx > 0) 
		textx = e->textheight - textx - 1;
	if(e->side == 1 && e->raydiry < 0) 
		textx = e->textheight - textx - 1;

	y = e->drawstart;
	while (y < e->drawend)
	{
		d = y * 256 - e->h * 128 + e->lineheight * 128;
		texty = ((d * e->textheight) / e->textheight) / 256;
		color = 0xC00000AA;
		if(e->side == 1) 
			color = (color >> 1) & 8355711;
        e->buffer[y][e->x] = color;

		y++;
	}
}




























