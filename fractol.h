/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:54:17 by ojerroud          #+#    #+#             */
/*   Updated: 2017/09/26 17:16:41 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

/*
** largeur x
*/

# define WIN_WIDTH	2560

/*
** taille y
*/

# define WIN_HEIGHT	1440

/*
**	variables
*/

typedef struct		s_var
{
	float	x;
	float	y;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	c_reel;
	float	c_imaginaire;
	float	z_reel;
	float	z_imaginaire;
	float	i;
	float	tmp;
	float	zoom;
	float	max;
	float	image_w;
	float	image_h;
	float	image_x;
	float	image_y;
}					t_var;

/*
** img params ()
*/

typedef struct		s_data
{
	void	*img;
	int		*data;
	int		tmp;
	int		x;
	int		y;
}					t_data;

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	char			*fractale;
	t_data			img;
	t_var			v;
}					t_fractol;

/*
**	event.c
*/

void	move_img(t_fractol *e, t_data *black_screen, int dx, int dy);
int		key_hook(int keycode, void *param);
int		mouse_hook(int button, int x, int y, void *param);
void	zoomer(t_fractol *mlx, t_data *black_screen, float value);
void	clean_screen(t_fractol *mlx, t_data *e);

/*
**	cleaners.c
*/

void	clean_exit(t_fractol *e);
void	clean_screen(t_fractol *mlx, t_data *e);

/*
**	algos.c
*/

void	mandelbrot(t_fractol *e);
void	init_fractale(t_fractol e);

/*
**	fdf.c
*/

void	init_mlx(t_fractol e);


#endif
