/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:25:49 by ojerroud          #+#    #+#             */
/*   Updated: 2017/12/06 16:25:53 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *e)
{
	e->v.c_reel = e->v.x / e->v.zoom + e->v.x1;
	e->v.c_imaginaire = e->v.y / e->v.zoom + e->v.y1;
	e->v.z_reel = 0;
	e->v.z_imaginaire = 0;
	e->v.i = 0;
	while (pow(e->v.z_reel, 2) + pow(e->v.z_imaginaire, 2) < 4 && e->v.i < e->v.max)
	{
		e->v.tmp = e->v.z_reel;
		e->v.z_reel = pow(e->v.z_reel, 2) - pow(e->v.z_imaginaire, 2) + e->v.c_reel;
		e->v.z_imaginaire = 2 * e->v.z_imaginaire * e->v.tmp + e->v.c_imaginaire;
		e->v.i++;
	}
	if (e->v.i == e->v.max)
		e->img.data[(int)e->v.image_w * (int)e->v.y + (int)e->v.x] = 0x000000;
	else
		e->img.data[(int)e->v.image_w * (int)e->v.y + (int)e->v.x] = e->v.i * 255 / e->v.max;
}

void	clean_exit(t_fractol *e)
{
	free(e->mlx);
	free(e->win);
	exit(0);
}

void	clean_screen(t_fractol *mlx, t_data *e)
{
	e->img = mlx_new_image(mlx->mlx, mlx->v.image_w, mlx->v.image_h);
	e->data = (int *)mlx_get_data_addr(mlx->img.img, &e->tmp, &e->tmp, &e->tmp);
	mlx_put_image_to_window(mlx->mlx, mlx->win, e->img, 0, 0);
	mlx_destroy_image(mlx->mlx, e->img);
}

void	move_img(t_fractol *e, t_data *black_screen, int dx, int dy)
{
	if (dx == dy)
	{
		e->v.image_x = 0;
		e->v.image_y = 0;
	}
	clean_screen(e, black_screen);
	e->v.image_x += (dx) ? (e->v.image_w / dx / 2) : 0;
	e->v.image_y += (dy) ? (e->v.image_h / dy / 2) : 0;
	mlx_put_image_to_window(e->mlx, e->win, e->img.img,
		e->v.image_x, e->v.image_y);
	dx = dy;
}

/*
**	esc
**	space
**	up
**	down
**	left
**	right
*/

int		key_hook(int keycode, void *param)
{
	t_data	black_screen;

	if (keycode == 53)
		clean_exit(param);
	if (keycode == 49)
		move_img(param, &black_screen, 0, 0);
	if (keycode == 126)
		move_img(param, &black_screen, 0, -20);
	if (keycode == 125)
		move_img(param, &black_screen, 0, 20);
	if (keycode == 123)
		move_img(param, &black_screen, -20, 0);
	if (keycode == 124)
		move_img(param, &black_screen, 20, 0);
	return (0);
}

void	init_mlx(t_fractol e)
{
	e.v.x1 = -2.1;
	e.v.x2 = 0.6;
	e.v.y1 = -1.2;
	e.v.y2 = 1.2;
	e.v.zoom = 100;
	e.v.max = 50;
	e.v.image_w = (e.v.x2 - e.v.x1) * e.v.zoom;
	e.v.image_h = (e.v.y2 - e.v.y1) * e.v.zoom;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.v.image_w, e.v.image_h, "fractol");
	e.img.img = mlx_new_image(e.mlx, e.v.image_w, e.v.image_h * 1.1);
	e.img.data = (int *)mlx_get_data_addr(e.img.img, &e.img.tmp, &e.img.tmp, &e.img.tmp);
	mlx_key_hook(e.win, key_hook, &e);
	e.v.x = -1;
	while (++e.v.x < e.v.image_w)
	{
		e.v.y = -1;
		while (++e.v.y < e.v.image_h)
			mandelbrot(&e);
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img.img, 0, 0);
	mlx_loop(e.mlx);
}

int		main(int ac, char** av)
{
	t_fractol e;

	if (ac != 2 || (ft_strcmp(av[1], "mandelbrot") && ft_strcmp(av[1], "julia")))
	{
		ft_putendl("Usage : ./fractol fractale [ mandelbrot - julia ]");
		return (-1);
	}
	e.fractale = av[1];
	init_mlx(e);
	return (0);
}
