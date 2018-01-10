/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:43:26 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/06/18 17:00:34 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_putpixel(t_win *win, int y, int x, int color)
{
	int		i;

	i = 0;
	if (x < IMG_W && y < IMG_H && x >= 0 && y >= 0)
	{
		i = win->linelen * y + x * 4;
		win->data[i] = color & 0xff;
		win->data[++i] = color >> 8 & 0xff;
		win->data[++i] = color >> 16 & 0xff;
	}
}

void	ft_refresh(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img);
	win->img = mlx_new_image(win->mlx, IMG_W, IMG_H);
	ft_fractol(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	if (win->commands == 1 && win->id != 3)
		ft_print_commands(win);
}

void	ft_init(t_win *win)
{
	ft_bzero(win, sizeof(t_win));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIN_W, WIN_H, "fract'ol");
	win->img = mlx_new_image(win->mlx, IMG_W, IMG_H);
	win->data = mlx_get_data_addr(win->img, &win->bpp, &win->linelen, \
																&win->endian);
}

void	ft_fractol(t_win *win)
{
	if (win->id == 0)
		ft_mandelbrot(win);
	else if (win->id == 1)
		ft_julia(win);
	else if (win->id == 2)
		ft_multibrot(win);
	else if (win->id == 3)
		ft_lyapunov(win);
	else if (win->id == 4)
		ft_tricorn(win);
	else if (win->id == 5)
		ft_nosferatu(win);
}
