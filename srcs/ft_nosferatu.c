/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nosferatu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:01:47 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/03/24 14:14:14 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_trace(t_win *win, t_mand mand, int x, int y)
{
	int			i;
	double		mod;
	t_complex	tmp;

	tmp.r = 0.0;
	tmp.i = 0.0;
	mand.z.r = x / win->zoom + mand.x;
	mand.z.i = y / win->zoom + mand.y;
	mod = sqrt(ft_fpow(mand.z.r, 2) + ft_fpow(mand.z.i, 2));
	i = 0;
	while (i < win->imax && mod < 4)
	{
		tmp.r = ft_fpow(mand.z.r, 2);
		tmp.i = ft_fpow(mand.z.i, 2);
		mand.z.r = tmp.r - tmp.i - mand.c.r;
		mand.z.i = 2 * (mand.z.r * mand.z.i) + mand.c.i;
		mod = sqrt(tmp.r + tmp.i);
		i++;
	}
	if (i == win->imax)
		return ;
	ft_putpixel(win, y, x, win->color[i % 63]);
}

void		ft_init_nos(t_win *win)
{
	win->init = 1;
	win->zoom = 200;
	win->imax = 60;
	win->mand.z.r = 0;
	win->mand.z.i = 0;
	win->mand.c.r = 0.5667;
	win->mand.c.i = -0.5;
	win->mand.x = -3.0;
	win->mand.y = -1.8;
	ft_getcolor(win, 255, 16777215, 63);
}

void		ft_nosferatu(t_win *win)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (win->init == 0)
		ft_init_nos(win);
	while (i < IMG_H)
	{
		j = 0;
		while (j < IMG_W)
		{
			ft_trace(win, win->mand, j, i);
			j++;
		}
		i++;
	}
}
