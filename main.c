/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:25:49 by ojerroud          #+#    #+#             */
/*   Updated: 2017/12/06 16:25:53 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol e)
{
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	init_fractale(&e);
	mlx_loop(e.mlx);
}

int		main(int ac, char **av)
{
	t_fractol e;

	if (ac != 2 || (ft_strcmp(av[1], "mandelbrot") &&
		ft_strcmp(av[1], "julia")))
	{
		ft_putendl("Usage : ./fractol fractale [ mandelbrot - julia ]");
		return (-1);
	}
	e.fractale = av[1];
	e.v.zoom = 100;
	change_variables(&e);
	init_mlx(e);
	return (0);
}
