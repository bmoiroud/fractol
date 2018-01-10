/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:19:56 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/05/21 19:01:45 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_error(int error, t_win *win)
{
	if (error == 1)
		ft_putstr("invalid argument\n");
	else if (error == 2)
		ft_putstr("malloc error\n");
	if (win)
		ft_free_all(win);
	exit(EXIT_FAILURE);
}

void	ft_free_all(t_win *win)
{
	if (win->lyap.s)
		free(win->lyap.s);
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_window(win->mlx, win->win);
}

int		ft_get_param(char **tab)
{
	int		n;

	n = ft_atoi(tab[1]);
	if (n == -1 || n < 0 || n > 6)
		ft_error(1, NULL);
	return (n);
}

int		main(int ac, char **av)
{
	t_win		win;

	if (ac < 2)
	{
		ft_putstr("usage: ./fractol <fractal>\n\t1.Mandelbrot\n\t2.Julia\n\t");
		ft_putstr("3.Multibrot\n\t4.Lyapunov\n\t5.Tricorn\n\t6.Nosferatu\n");
	}
	else
	{
		ft_init(&win);
		win.id = ft_get_param(av) - 1;
		ft_fractol(&win);
		mlx_put_image_to_window(win.mlx, win.win, win.img, 0, 0);
		mlx_key_hook(win.win, ft_keyfunct, (void *)&win);
		mlx_hook(win.win, 6, 1 << 8, ft_motion, (void *)&win);
		if (win.id != 3)
			mlx_mouse_hook(win.win, ft_mousefunct, (void *)&win);
		if (win.commands == 1 && win.id != 3)
			ft_print_commands(&win);
		mlx_loop(win.mlx);
	}
	return (0);
}
