/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   burningships.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 14:31:44 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 11:48:05 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	burningships(void *p)
{
	t_env	*e;
	t_point	pos;
	double	tmp;
	int		j;

	e = p;
	pos.x = -1;
	while (++pos.x < WIDTH && (pos.y = -1))
		while (++pos.y < HEIGHT)
		{
			F.c = setc(pos.x / F.zoom + F.x1, pos.y / F.zoom + F.y1);
			F.z = setc(0, 0);
			j = 0;
			while (F.z.r * F.z.r + F.z.i * F.z.i < 4 && j < F.i_max)
			{
				F.z = setc(ft_abs(F.z.r), ft_abs(F.z.i));
				tmp = F.z.r;
				F.z.r = F.z.r * F.z.r - F.z.i * F.z.i + F.c.r;
				F.z.i = 2 * F.z.i * tmp + F.c.i;
				j++;
			}
			if (j != F.i_max && j > 3)
				img_pixel_put(e, pos.x, pos.y, (j * 255 / F.i_max) * 400000);
		}
	mlx_put_image_to_window(e->pmlx, e->pwin, e->pimg, 0, 0);
}
