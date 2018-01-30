/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:25:49 by ojerroud          #+#    #+#             */
/*   Updated: 2017/12/06 16:25:53 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_exit(t_fractol *e)
{
	free(e->mlx);
	free(e->win);
	exit(0);
}

void	clean_screen(t_fractol *mlx, t_data *e)
{
	e->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->data = (int *)mlx_get_data_addr(mlx->img.img, &e->tmp, &e->tmp, &e->tmp);
	mlx_put_image_to_window(mlx->mlx, mlx->win, e->img, 0, 0);
	mlx_destroy_image(mlx->mlx, e->img);
}