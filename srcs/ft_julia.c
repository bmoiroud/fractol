/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:40:18 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/03/23 15:41:52 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_trace(t_win *win, int y, int x, int c)
{
	t_mand	mand;
	double	mod;
	double	tmp;
	int		i;

	i = 0;
	mand = win->mand;
	mand.z.r = x / win->zoom + mand.x;
	mand.z.i = y / win->zoom + mand.y;
	mod = sqrt(ft_fpow(mand.z.r, 2) + ft_fpow(mand.z.i, 2));
	while (i < win->imax && mod < 4)
	{
		tmp = mand.z.r;
		mand.z.r = ft_fpow(mand.z.r, 2) - ft_fpow(mand.z.i, 2) + mand.c.r;
		mand.z.i = (2 * tmp * mand.z.i) + mand.c.i;
		mod = sqrt(ft_fpow(mand.z.r, 2) + ft_fpow(mand.z.i, 2));
		i++;
	}
	if (i == win->imax)
		return ;
	c = (18673850 - (i * 1896635) % 18673850);
	ft_putpixel(win, y, x, c);
}

void		ft_init_julia(t_win *win)
{
	win->mand.z.r = 0.0;
	win->mand.z.i = 0.0;
	win->mand.c.r = 0.0;
	win->mand.c.i = 0.8;
	win->mand.x = -2.5;
	win->mand.y = -2.0;
	win->zoom = 200;
	win->imax = 30;
	win->init = 1;
}

void		ft_julia(t_win *win)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = 0;
	if (win->init == 0)
		ft_init_julia(win);
	while (i < IMG_H)
	{
		j = 0;
		while (j < IMG_W)
		{
			ft_trace(win, i, j, c);
			j++;
		}
		i++;
	}
}
