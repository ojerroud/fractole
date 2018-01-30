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

void	zoomer(t_fractol *mlx, t_data *black_screen, float value)
{
	clean_screen(mlx, black_screen);
	mlx->v.zoom += (mlx->v.zoom / 2 * value);
	init_fractale(*mlx);
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

