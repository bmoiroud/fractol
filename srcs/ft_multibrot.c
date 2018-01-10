/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multibrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:47:31 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/03/21 17:31:16 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_trace(t_mand mand, t_win *win, int x, int y)
{
	double	mod;
	double	tmp;
	int		i;

	i = 0;
	mod = sqrt(ft_fpow(mand.z.r, 6) + ft_fpow(mand.z.i, 6));
	tmp = 0;
	mand.c.r = x / win->zoom + mand.x;
	mand.c.i = y / win->zoom + mand.y;
	while (i < win->imax && mod < 4)
	{
		tmp = mand.z.r;
		mand.z.r = ft_fpow(mand.z.r, 6) - (15 * ft_fpow(mand.z.r, 4) * \
					ft_fpow(mand.z.i, 2)) + (15 * ft_fpow(mand.z.r, 2) * \
					ft_fpow(mand.z.i, 4)) - ft_fpow(mand.z.i, 6) + mand.c.i;
		mand.z.i = (6 * ft_fpow(tmp, 5) * mand.z.i - 20 * ft_fpow(tmp, 3) * \
					ft_fpow(mand.z.i, 3) + 6 * tmp * ft_fpow(mand.z.i, 5)) + \
					mand.c.r;
		mod = sqrt(ft_fpow(mand.z.r, 6) + ft_fpow(mand.z.i, 6));
		i++;
	}
	if (i == win->imax)
		return ;
	ft_putpixel(win, y, x, win->color[i % 31]);
}

void		ft_init_multi(t_win *win)
{
	win->init = 1;
	win->zoom = 330;
	win->imax = 100;
	win->mand.x = -1.8;
	win->mand.y = -1.3;
	ft_getcolor(win, 255, 16777215, 31);
}

void		ft_multibrot(t_win *win)
{
	int		i;
	int		j;

	i = 0;
	if (win->init == 0)
		ft_init_multi(win);
	while (i < IMG_H)
	{
		j = 0;
		while (j < IMG_W)
		{
			win->mand.z.r = 0;
			win->mand.z.i = 0;
			ft_trace(win->mand, win, j, i);
			j++;
		}
		i++;
	}
}
