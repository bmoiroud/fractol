/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:29:50 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/03/24 14:16:02 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define WIN_H 800
# define WIN_W 1200
# define IMG_H WIN_H
# define IMG_W WIN_W

typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct	s_lyap
{
	double		a;
	double		b;
	double		l;
	double		x;
	double		r;
	char		*s;
	int			i;
	int			nmax;
}				t_lyap;

typedef struct	s_mand
{
	t_complex	z;
	t_complex	c;
	double		x;
	double		y;
}				t_mand;

typedef struct	s_win
{
	int			constmod;
	int			commands;
	int			linelen;
	int			icount;
	int			endian;
	int			init;
	int			imax;
	int			bpp;
	int			id;
	int			*color;
	void		*win;
	void		*mlx;
	void		*img;
	char		*data;
	double		zoom;
	t_mand		mand;
	t_lyap		lyap;
}				t_win;

int				ft_keyfunct(int key, void *param);
int				ft_motion(int x, int y, void *param);
int				ft_mousefunct(int key, int x, int y, void *param);
void			ft_init(t_win *win);
void			ft_julia(t_win *win);
void			ft_tricorn(t_win *win);
void			ft_refresh(t_win *win);
void			ft_fractol(t_win *win);
void			ft_lyapunov(t_win *win);
void			ft_nosferatu(t_win *win);
void			ft_multibrot(t_win *win);
void			ft_mandelbrot(t_win *win);
void			ft_free_all(t_win *fract);
void			ft_print_commands(t_win *win);
void			ft_move(t_win *fract, int key);
void			ft_error(int error, t_win *win);
void			ft_zoom(int s, int x, int y, t_win *fract);
void			ft_getcolor(t_win *win, int c1, int c2, int n);
void			ft_putpixel(t_win *win, int y, int x, int color);

#endif
