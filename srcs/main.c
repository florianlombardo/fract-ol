/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/23 16:08:46 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 12:10:20 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** on divise bpp (bits per pixel) par 8 pour obtenir bytes per pixel
*/

static void	init_image(t_env *e)
{
	e->i.data = mlx_get_data_addr(e->pimg, &(e->i.bpp),
		&(e->i.s_line), &(e->i.endian));
	e->i.bpp /= 8;
}

static void	ft_usage(void)
{
	ft_putendl_fd("Usage: ./fractol <fractal>", 2);
	ft_putendl_fd("Available fractals:", 2);
	ft_putendl_fd("1- mandelbrot", 2);
	ft_putendl_fd("2- julia", 2);
	ft_putendl_fd("3- burningships", 2);
	exit(EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	t_env	e;

	if (ac == 2 && (!ft_strcmp(av[1], "mandelbrot") ||
		!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "burningships")))
	{
		e.pmlx = mlx_init();
		e.pwin = mlx_new_window(e.pmlx, WIDTH, HEIGHT, "fractol");
		e.pimg = mlx_new_image(e.pmlx, WIDTH, HEIGHT);
		init_image(&e);
		draw_image(&e, av[1]);
		mlx_mouse_hook(e.pwin, deal_mouse, &e);
		mlx_key_hook(e.pwin, deal_key, &e);
		mlx_hook(e.pwin, 6, 0, deal_hook, &e);
		mlx_loop(e.pmlx);
	}
	else
		ft_usage();
	mlx_destroy_image(e.pmlx, e.pimg);
	mlx_destroy_window(e.pmlx, e.pwin);
	return (EXIT_SUCCESS);
}
