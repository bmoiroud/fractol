/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:11:02 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/03/18 15:09:15 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_getcolor(t_win *win, int c1, int c2, int n)
{
	int		i;
	int		ci;

	ci = (c2 - c1) / ((n + 1) / 2);
	i = -1;
	if (!(win->color = (int *)malloc((n + 1) * sizeof(int))))
		ft_error(2, win);
	while (++i < (n - 1) / 2)
		win->color[i] = c1 + (ci * i);
	win->color[i] = c1 + (ci * (i - 1));
	while (i++ < (n - 1))
		win->color[i] = c1 + (ci * ((n) - i));
}
