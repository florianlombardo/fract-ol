/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/23 15:53:15 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 17:24:16 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# define WIDTH 640
# define HEIGHT 480

# define F e->f

# define K_ESCAPE	53
# define K_PLUS		69
# define K_MINUS	78
# define K_R		15
# define K_NUM_1	83
# define K_NUM_2	84
# define K_NUM_3	85
# define M_LEFT		1
# define M_UP		4
# define M_DOWN		5

# define REV(X) X == 0 ? 1 : 0

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_cplx
{
	double		r;
	double		i;
}				t_cplx;

typedef struct	s_img
{
	int			bpp;
	int			s_line;
	int			endian;
	char		*data;
}				t_img;

typedef struct	s_frctl
{
	double		x1;
	double		y1;
	double		zoom;
	double		h;
	int			i_max;
	int			color;
	t_cplx		z;
	t_cplx		c;
	void		(*draw)(void *);
	void		(*init)(void *);
}				t_frctl;

typedef struct	s_env
{
	void		*pmlx;
	void		*pwin;
	void		*pimg;
	short		isjulia;
	short		move;
	t_img		i;
	t_frctl		f;
}				t_env;

/*
** image.c
*/

void			draw_image(t_env *e, char *str);
void			init_mandelbrot(void *p);
void			init_burningships(void *p);
void			init_julia(void *p);
void			img_pixel_put(t_env *e, int x, int y, int color);

/*
** mandelbrot.c
*/

void			mandelbrot(void *p);

/*
** burningships.c
*/

void			burningships(void *p);

/*
** julia.c
*/

void			julia(void *p);

/*
** deal_key.c
*/

int				deal_key(int key, t_env *e);

/*
** deal_mouse.c
*/

int				deal_mouse(int button, int x, int y, t_env *e);
int				deal_hook(int x, int y, t_env *e);

/*
** utilities.c
*/

t_point			setp(int x, int y);
t_cplx			setc(double r, double i);
void			ft_reset(t_env *e);
void			ft_quit(t_env *e);
double			ft_abs(double x);

#endif
