/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:08:41 by ojerroud          #+#    #+#             */
/*   Updated: 2017/12/06 20:08:43 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_img(t_fractol *e, t_data *black_screen, int dx, int dy)
{
	if (dx == dy)
	{
		init_variables(e);
		init_fractale(e);
		return ;
	}
	clean_screen(e, black_screen);
	e->v.x1 -= (dx) ? (e->v.xdiff) / (double)dx : 0;
	e->v.x2 -= (dx) ? (e->v.xdiff) / (double)dx : 0;
	e->v.y1 -= (dy) ? (e->v.ydiff) / (double)dy : 0;
	e->v.y2 -= (dy) ? (e->v.ydiff) / (double)dy : 0;
	init_fractale(e);
}

void	zoomer(t_fractol *mlx, t_data *black_screen, double value)
{
	int tmp;

	clean_screen(mlx, black_screen);
	tmp = mlx->v.zoom;
	mlx->v.zoom += (mlx->v.zoom / 20 * value);
	mlx->v.zoom = (mlx->v.zoom < ZOOM) ? tmp : mlx->v.zoom;
	if ((mlx->v.x2 - mlx->v.x1) * mlx->v.zoom > WIN_WIDTH)
		mlx->v.x2 = WIN_WIDTH / mlx->v.zoom + mlx->v.x1;
	if ((mlx->v.y2 - mlx->v.y1) * mlx->v.zoom > WIN_HEIGHT)
		mlx->v.y2 = WIN_HEIGHT / mlx->v.zoom + mlx->v.y1;
	if (value < 0)
	{
		if ((mlx->v.x2 - mlx->v.x1) * mlx->v.zoom > WIN_WIDTH)
			mlx->v.x2 = WIN_WIDTH / mlx->v.zoom + mlx->v.x1;
		else
			mlx->v.x2 = mlx->v.image_w / mlx->v.zoom + mlx->v.x1;
		if ((mlx->v.y2 - mlx->v.y1) * mlx->v.zoom > WIN_HEIGHT)
			mlx->v.y2 = WIN_HEIGHT / mlx->v.zoom + mlx->v.y1;
		else
			mlx->v.y2 = mlx->v.image_h / mlx->v.zoom + mlx->v.y1;
	}
	mlx->v.xdiff = mlx->v.x2 - mlx->v.x1;
	mlx->v.ydiff = mlx->v.y2 - mlx->v.y1;
	init_fractale(mlx);
}

/*
**	esc
**	space
**	up
**	down
**	left
**	right
**	p > pause julia mvm
**	} > max-
**	{ > max+
*/

int		key_hook(int keycode, t_fractol *e)
{
	t_data	black_screen;

	if (keycode == 53)
		clean_exit(e);
	if (keycode == 49)
		move_img(e, &black_screen, 0, 0);
	if (keycode == 126)
		move_img(e, &black_screen, 0, -20);
	if (keycode == 125)
		move_img(e, &black_screen, 0, 20);
	if (keycode == 123)
		move_img(e, &black_screen, -20, 0);
	if (keycode == 124)
		move_img(e, &black_screen, 20, 0);
	if (keycode == 69)
		zoomer(e, &black_screen, 1);
	if (keycode == 78)
		zoomer(e, &black_screen, -1);
	if (keycode == 35)
		e->v.p = (e->v.p == 1) ? 0 : 1;
	if (keycode == 30 || keycode == 33)
	{
		e->v.max += (keycode == 30) ? 10 : -10;
		clean_screen(e, &black_screen);
		init_fractale(e);
	}
	return (0);
}

int		mouse_mvm(int x, int y, t_fractol *e)
{
	t_data	black_screen;

	if (ft_strcmp(e->fractale, "julia") || e->v.p == 0)
		return (0);
	clean_screen(e, &black_screen);
	e->mouse.x_mid = WIN_WIDTH / 2;
	e->mouse.y_mid = WIN_HEIGHT / 2;
	x = (x < 0) ? 0 : x;
	y = (y < 0) ? 0 : y;
	x = (x > WIN_WIDTH) ? WIN_WIDTH : x;
	y = (y > WIN_HEIGHT) ? WIN_HEIGHT : y;
	y = WIN_HEIGHT - y;
	e->v.c_reel = ((double)x / WIN_WIDTH * 2) - 1;
	e->v.c_imaginaire = (double)y / WIN_HEIGHT;
	init_fractale(e);
	return (0);
}

/*
**	scrollup
**	scrolldown
*/

int		mouse_hook(int button, int x, int y, void *param)
{
	t_data	black_screen;

	if (button == 4)
		zoomer(param, &black_screen, 1);
	if (button == 5)
		zoomer(param, &black_screen, -1);
	x = y;
	return (0);
}
