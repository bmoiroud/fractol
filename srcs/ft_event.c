/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:08:34 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/05/19 18:43:15 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_zoom(int s, int x, int y, t_win *win)
{
	intmax_t		zoom;

	if (win->zoom < 15 && s == 1)
		win->zoom = 16;
	if ((zoom = win->zoom / 15) > 0 && x > 0 && y > 0)
	{
		win->mand.x += s * (IMG_W * zoom / (win->zoom * (win->zoom - zoom))) / \
												((IMG_W / x) / (IMG_W / IMG_H));
		win->mand.y += s * (IMG_H * zoom / (win->zoom * (win->zoom - zoom))) / \
												((IMG_H / y) / (IMG_W / IMG_H));
		win->zoom += s * zoom;
		win->icount += s;
		if (win->icount == 3 || win->icount == -3)
		{
			win->icount = 0;
			win->imax += s;
			win->imax += s * (win->imax / 100 + 1);
		}
	}
	ft_refresh(win);
}

void	ft_move(t_win *win, int key)
{
	if (key == 123)
		win->mand.x += 3 / win->zoom;
	else if (key == 124)
		win->mand.x -= 3 / win->zoom;
	else if (key == 125)
		win->mand.y -= 3 / win->zoom;
	else if (key == 126)
		win->mand.y += 3 / win->zoom;
	ft_refresh(win);
}

void	ft_print_commands(t_win *win)
{
	mlx_string_put(win->mlx, win->win, 15, WIN_H - 155, 0xC0C0C0, \
								"molette horizontale/verticale: zoom / dezoom");
	mlx_string_put(win->mlx, win->win, 15, WIN_H - 130, 0xC0C0C0, \
								"espace: activer / desactiver modif constante");
	mlx_string_put(win->mlx, win->win, 15, WIN_H - 105, 0xC0C0C0, \
								"H: afficher / cacher les commandes");
	mlx_string_put(win->mlx, win->win, 15, WIN_H - 80, 0xC0C0C0, \
								"fleches: bouger la fractale");
	mlx_string_put(win->mlx, win->win, 15, WIN_H - 55, 0xC0C0C0, \
								"R: reinitialiser la fractale");
	mlx_string_put(win->mlx, win->win, 15, WIN_H - 30, 0xC0C0C0, \
								"ESC: quitter");
}
