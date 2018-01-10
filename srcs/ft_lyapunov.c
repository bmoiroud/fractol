/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lyapunov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:37:11 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/03/23 15:37:14 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_trace(t_win *win, t_lyap *l, int y, int x)
{
	int		n;
	int		c;
	double	lexp;

	lexp = 0.0;
	c = 0;
	n = 0;
	l->x = 0.5;
	while (n < l->nmax)
	{
		l->r = ((l->s[n % 12] == 'A') ? l->a : l->b);
		lexp = log(fabs(l->r * (1 - 2 * l->x)));
		l->x = l->r * l->x * (1 - l->x);
		n++;
	}
	l->i++;
	c = lexp * 180 + 1246720;
	ft_putpixel(win, y, x, c);
}

void		ft_init_lyap(t_win *win)
{
	win->lyap.a = 0.0;
	win->lyap.b = 0.0;
	win->lyap.l = 0.0;
	win->lyap.x = 0.5;
	win->lyap.r = 0.0;
	win->lyap.i = 0;
	win->lyap.nmax = 800;
	win->zoom = 1.0;
	if ((win->lyap.s = malloc(13 * sizeof(char))) == NULL)
		ft_error(2, win);
	ft_strncpy(win->lyap.s, "BBBBBBAAAAAA", 12);
}

void		ft_lyapunov(t_win *win)
{
	double	i;
	double	j;

	i = 0;
	if (win->init == 0)
		ft_init_lyap(win);
	while (i < IMG_H)
	{
		j = 0;
		while (j < IMG_W)
		{
			win->lyap.a = (j / IMG_W * 0.6 + 3.4) * win->zoom;
			win->lyap.b = (i / IMG_H * 0.9 + 2.5) * win->zoom;
			ft_trace(win, &win->lyap, i, j);
			j++;
		}
		i++;
	}
}
