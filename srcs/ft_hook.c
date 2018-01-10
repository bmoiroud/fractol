/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:38:35 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/05/21 19:08:48 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_keyfunct(int key, void *param)
{
	t_win	*win;

	win = (t_win *)param;
	if (key == 53)
	{
		ft_free_all(win);
		exit(EXIT_SUCCESS);
	}
	else if (key >= 123 && key <= 126)
		ft_move(win, key);
	else if (key == 15)
	{
		win->init = 0;
		ft_refresh(win);
	}
	else if (key == 49)
		win->constmod = ++win->constmod % 2;
	else if (key == 4)
	{
		win->commands = ++win->commands % 2;
		ft_refresh(win);
	}
	return (0);
}

int		ft_motion(int x, int y, void *param)
{
	t_win	*win;

	win = (t_win *)param;
	if (x < WIN_W && x >= 0 && y < WIN_H && y >= 0 && win->constmod == 1)
	{
		if (win->id == 1 || win->id == 5)
		{
			win->mand.c.r = (double)x / (double)WIN_W * 8.0 - 4.0;
			win->mand.c.i = (double)y / (double)WIN_H * 8.0 - 4.0;
		}
		else if (win->id == 0 || win->id == 3)
		{
			win->mand.z.r = (double)x / (double)WIN_W * 4.8 - 2.4;
			win->mand.z.i = (double)y / (double)WIN_H * 2.8 - 1.4;
		}
		else if (win->id == 4)
		{
			win->mand.z.r = (double)x / (double)WIN_W * 8.0 - 4.0;
			win->mand.z.i = (double)y / (double)WIN_H * 6.0 - 3.0;
		}
		ft_refresh(win);
	}
	return (0);
}

int		ft_mousefunct(int key, int x, int y, void *param)
{
	if (key == 7 || key == 4)
		ft_zoom(1, x, y, (t_win *)param);
	else if (key == 5 || key == 6)
		ft_zoom(-1, x, y, (t_win *)param);
	return (0);
}
