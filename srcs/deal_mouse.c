/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   deal_mouse.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 15:00:21 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 17:24:42 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_update(t_env *e, int x, int y, char c)
{
	if (c == '+')
	{
		F.x1 = (x / F.zoom + F.x1) - (x / (F.zoom * 1.1));
		F.y1 = (y / F.zoom + F.y1) - (y / (F.zoom * 1.1));
		F.zoom *= 1.1;
		ft_bzero(e->i.data, (WIDTH * e->i.bpp) * HEIGHT);
		e->f.draw(e);
	}
	else
	{
		F.x1 = (x / F.zoom + F.x1) - (x / (F.zoom * 0.9));
		F.y1 = (y / F.zoom + F.y1) - (y / (F.zoom * 0.9));
		F.zoom *= 0.9;
		ft_bzero(e->i.data, (WIDTH * e->i.bpp) * HEIGHT);
		e->f.draw(e);
	}
}

int			deal_mouse(int button, int x, int y, t_env *e)
{
	if (button == M_LEFT)
		e->move = REV(e->move);
	else if (button == M_UP)
		ft_update(e, x, y, '+');
	else if (button == M_DOWN)
		ft_update(e, x, y, '-');
	return (0);
}

int			deal_hook(int x, int y, t_env *e)
{
	if (e->isjulia == 1 && e->move == 1
		&& x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		F.c.r = (double)x / WIDTH * 4 - 2;
		F.c.i = (double)y / HEIGHT * 4 - 2;
		ft_bzero(e->i.data, (WIDTH * e->i.bpp) * HEIGHT);
		e->f.draw(e);
	}
	return (0);
}
