/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tagrad.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 12:05:02 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 12:54:31 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_point	setp(int x, int y)
{
	t_point	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_cplx	setc(double r, double i)
{
	t_cplx	ret;

	ret.r = r;
	ret.i = i;
	return (ret);
}

void	ft_reset(t_env *e)
{
	e->f.init(e);
	ft_bzero(e->i.data, (WIDTH * e->i.bpp) * HEIGHT);
	e->f.draw(e);
}

void	ft_quit(t_env *e)
{
	mlx_destroy_image(e->pmlx, e->pimg);
	mlx_destroy_window(e->pmlx, e->pwin);
	exit(EXIT_SUCCESS);
}

double	ft_abs(double x)
{
	return (x >= 0 ? x : -x);
}
