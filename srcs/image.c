/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ta.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 16:12:33 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 12:55:27 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_env *e, int x, int y, int color)
{
	if (e->f.i_max == 0 || x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	*(int*)(e->i.data + ((y * WIDTH + x) * e->i.bpp)) = color;
}

void	init_mandelbrot(void *p)
{
	t_env	*ret;

	ret = p;
	ret->move = 0;
	ret->isjulia = 0;
	ret->f.x1 = -2.1;
	ret->f.y1 = -1.2;
	ret->f.zoom = 200;
	ret->f.h = 0;
	ret->f.i_max = 50;
	ret->f.color = 0;
	ret->f.draw = mandelbrot;
	ret->f.init = init_mandelbrot;
}

void	init_burningships(void *p)
{
	t_env	*ret;

	ret = p;
	ret->move = 0;
	ret->isjulia = 0;
	ret->f.x1 = -2.1;
	ret->f.y1 = -1.8;
	ret->f.zoom = 180;
	ret->f.i_max = 50;
	ret->f.color = 0;
	ret->f.draw = burningships;
	ret->f.init = init_burningships;
}

void	init_julia(void *p)
{
	t_env	*ret;

	ret = p;
	ret->move = 0;
	ret->isjulia = 1;
	ret->f.x1 = -3;
	ret->f.y1 = -2;
	ret->f.zoom = 110;
	ret->f.i_max = 50;
	ret->f.c = setc(0.285, 0.01);
	ret->f.color = 0;
	ret->f.draw = julia;
	ret->f.init = init_julia;
}

void	draw_image(t_env *e, char *str)
{
	e->isjulia = 0;
	if (!ft_strcmp(str, "mandelbrot"))
		init_mandelbrot(e);
	else if (!ft_strcmp(str, "julia"))
		init_julia(e);
	else
		init_burningships(e);
	e->f.draw(e);
}
