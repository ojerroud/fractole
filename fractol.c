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

void	julia(t_fractol *mlx, int x, int y)
{
	int	tmp_x;
	int	tmp_y;
	int	tmp;
	int	color;

	tmp_x = x;
	tmp_y = y;
	color = 0;
	while (sqrt(pow(tmp_x, 2) + pow(tmp_y, 2)) > 2)
	{
		printf("z = %f\n", sqrt(pow(tmp_x, 2) + pow(tmp_y, 2)));
		tmp = tmp_x;
		tmp_x = pow(tmp_x, 2) - pow(tmp_y, 2);
		tmp_y = 2 * tmp * tmp_y;
		color++;
	}
	mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
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
	int			x;
	int			y;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1600, 1600, "fractol");
	mlx_key_hook(mlx.win, key_hook, &mlx);
	y = 1;
	while (y <= 800)
	{
		x = 1;
		while (x <= 800)
		{
			julia(&mlx, x ,y);
			x++;
		}
		y++;
	}
	mlx_loop(mlx.mlx);
	return (0);
}
