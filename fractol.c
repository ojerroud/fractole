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

void	mandelbrot(t_fractol *mlx, float x, float y, float max, float x1, float y1, float zoom)
{
	float	z_reel;
	float	z_imaginaire;
	float	c_reel;
	float	c_imaginaire;
	float	i;
	float	tmp;

	c_reel = x / zoom + x1;
	c_imaginaire = y / zoom + y1;
	i = 0;
	z_reel = 0;
	z_imaginaire = 0;
	while ((pow(z_reel, 2) + pow(z_imaginaire, 2)) < 4 && max > i)
	{
		tmp = z_reel;
		z_reel = pow(z_reel, 2) - pow(z_imaginaire, 2) + c_reel;
		z_imaginaire = 2 * tmp * z_imaginaire + c_imaginaire;
		i++;
	}
	if (i == max)
		mlx_pixel_put(mlx->mlx, mlx->win, c_reel, c_imaginaire, 0xFF0000);
}

void	clean_exit(t_fractol *mlx)
{
	free(mlx->mlx);
	free(mlx->win);
	exit(0);
}

int		key_hook(int keycode, void *param)
{
	if (keycode == 53)
		clean_exit(param);
	return (0);
}

int		main(void)
{
	t_fractol	mlx;
	float		x;
	float		y;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		zoom;
	float		max;

	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	zoom = 100;
	max = 50;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH_MAX, WIN_HEIGHT_MAX, "fractol");
	mlx_key_hook(mlx.win, key_hook, &mlx);
	y = 0;
	while (y <= (y2 - y1) * zoom)
	{
		x = 0;
		while (x <= (x2 - x1) * zoom)
		{
			mandelbrot(&mlx, x ,y, max, x1, y1, zoom);
			x++;
		}
		y++;
	}
	mlx_loop(mlx.mlx);
	return (0);
}
