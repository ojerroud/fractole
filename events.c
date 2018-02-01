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
		e->v.image_x = 0;
		e->v.image_y = 0;
	}
	clean_screen(e, black_screen);
	e->v.image_x += (dx) ? (e->v.image_w / dx) : 0;
	e->v.image_y += (dy) ? (e->v.image_h / dy) : 0;
	mlx_put_image_to_window(e->mlx, e->win, e->img.img,
		e->v.image_x, e->v.image_y);
}

void	zoomer(t_fractol *mlx, t_data *black_screen, double value)
{
	int tmp;

	clean_screen(mlx, black_screen);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	tmp = mlx->v.zoom;
	mlx->v.zoom += (mlx->v.zoom / 20 * value);
	if (mlx->v.zoom < 100)
		mlx->v.zoom = tmp;
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
		move_img(param, &black_screen, 0, -10);
	if (keycode == 125)
		move_img(param, &black_screen, 0, 10);
	if (keycode == 123)
		move_img(param, &black_screen, -10, 0);
	if (keycode == 124)
		move_img(param, &black_screen, 10, 0);
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
		change_c(param, &black_screen, -1);
	if (button == 5)
		change_c(param, &black_screen, 1);
	x = y;
	return (0);
}
