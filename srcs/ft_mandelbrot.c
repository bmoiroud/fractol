/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:35:58 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/03/23 15:42:03 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_trace(t_win *win, int x, int y)
{
	t_mand	mand;
	double	mod;
	double	tmp;
	int		i;

	i = 0;
	mand = win->mand;
	mand.c.r = x / win->zoom + mand.x;
	mand.c.i = y / win->zoom + mand.y;
	mod = sqrt(ft_fpow(mand.z.r, 2) + ft_fpow(mand.z.i, 2));
	while (i < win->imax && mod < 4)
	{
		tmp = mand.z.r;
		mand.z.r = ft_fpow(mand.z.r, 2) - ft_fpow(mand.z.i, 2) + mand.c.r;
		mand.z.i = 2.0 * mand.z.i * tmp + mand.c.i;
		mod = sqrt(ft_fpow(mand.z.r, 2) + ft_fpow(mand.z.i, 2));
		i++;
	}
	if (i == win->imax)
		return ;
	ft_putpixel(win, y, x, win->color[i % 63]);
}

void		ft_init_mand(t_win *win)
{
	win->init = 1;
	win->zoom = 290;
	win->imax = 60;
	win->mand.z.r = 0;
	win->mand.z.i = 0;
	win->mand.x = -2.3;
	win->mand.y = -1.4;
	ft_getcolor(win, 255, 16777215, 63);
}

void		ft_mandelbrot(t_win *win)
{
	int		i;
	int		j;

	i = 0;
	if (win->init == 0)
		ft_init_mand(win);
	while (i < IMG_H)
	{
		j = 0;
		while (j < IMG_W)
		{
			ft_trace(win, j, i);
			j++;
		}
		i++;
	}
}
