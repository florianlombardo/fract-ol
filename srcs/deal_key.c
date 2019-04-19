/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dfD.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 16:36:47 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 12:56:12 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		incr_imax(t_env *e)
{
	e->f.i_max += 10;
	e->f.draw(e);
}

static void		decr_imax(t_env *e)
{
	if (e->f.i_max > 10)
	{
		e->f.i_max -= 10;
		ft_bzero(e->i.data, (WIDTH * e->i.bpp) * HEIGHT);
		e->f.draw(e);
	}
}

static void		ft_fractal(t_env *e, short frctl)
{
	if (frctl == 1)
		init_mandelbrot(e);
	else if (frctl == 2)
		init_julia(e);
	else
		init_burningships(e);
	ft_bzero(e->i.data, (WIDTH * e->i.bpp) * HEIGHT);
	e->f.draw(e);
}

int				deal_key(int key, t_env *e)
{
	if (key == K_NUM_1)
		ft_fractal(e, 1);
	else if (key == K_NUM_2)
		ft_fractal(e, 2);
	else if (key == K_NUM_3)
		ft_fractal(e, 3);
	else if (key == K_PLUS)
		incr_imax(e);
	else if (key == K_MINUS)
		decr_imax(e);
	else if (key == K_R)
		ft_reset(e);
	if (key == K_ESCAPE)
		ft_quit(e);
	return (0);
}
