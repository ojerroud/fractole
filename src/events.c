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
		init_variables(e);
	mlx_destroy_image(e->mlx, e->img.img);
	clean_screen(e, black_screen);
	e->v.x1 -= (dx) ? (e->v.xdiff / (double)dx) : 0;
	e->v.x2 -= (dx) ? (e->v.xdiff / (double)dx) : 0;
	e->v.y1 -= (dy) ? (e->v.ydiff / (double)dy) : 0;
	e->v.y2 -= (dy) ? (e->v.ydiff / (double)dy) : 0;
	init_fractale(e);
}

void	zoomer(t_fractol *mlx, t_data *black_screen, double value)
{
	int tmp;

	mlx_destroy_image(mlx->mlx, mlx->img.img);
	clean_screen(mlx, black_screen);
	tmp = mlx->v.zoom;
	mlx->v.zoom += (mlx->v.zoom / 20 * value);
	if (mlx->v.zoom < 100)
		mlx->v.zoom = tmp;
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
	init_fractale(mlx);
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
	if (keycode == 69)
		zoomer(param, &black_screen, 1);
	if (keycode == 78)
		zoomer(param, &black_screen, -1);
	return (0);
}

void	change_c(t_fractol *mlx, t_data *black_screen, float value)
{
	if (ft_strcmp(mlx->fractale, "julia"))
		return ;
	clean_screen(mlx, black_screen);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx->v.c_reel += (0.001 * value);
	mlx->v.c_imaginaire += (0.001 * value);
	init_fractale(mlx);
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
