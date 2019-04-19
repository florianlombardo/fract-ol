/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 13:32:28 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 17:02:49 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(void *p)
{
	t_env	*e;
	t_point	pos;
	double	tmp;
	int		i;

	e = p;
	pos.x = -1;
	while (++pos.x < WIDTH && (pos.y = -1))
		while (++pos.y < HEIGHT)
		{
			F.z = setc(pos.x / F.zoom + F.x1, pos.y / F.zoom + F.y1);
			i = 0;
			while (F.z.r * F.z.r + F.z.i * F.z.i < 4 && i < F.i_max)
			{
				tmp = F.z.r;
				F.z.r = F.z.r * F.z.r - F.z.i * F.z.i + F.c.r;
				F.z.i = 2 * F.z.i * tmp + F.c.i;
				i++;
			}
			if (i != F.i_max && i > 3)
				img_pixel_put(e, pos.x, pos.y, (i * 255 / F.i_max) * 550000);
		}
	mlx_put_image_to_window(e->pmlx, e->pwin, e->pimg, 0, 0);
}
