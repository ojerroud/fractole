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

# define WIN_WIDTH	600
# define WIN_HEIGHT	600
# define ZOOM		150

/*
**	variables
*/

typedef struct		s_var
{
	int		x;
	int		y;
	double	x1;
	double	x2;
	double	xdiff;
	double	y1;
	double	y2;
	double	ydiff;
	double	c_reel;
	double	c_imaginaire;
	double	z_reel;
	double	z_imaginaire;
	int		i;
	double	tmp;
	double	zoom;
	int		max;
	double	image_w;
	double	image_h;
	int		image_x;
	int		image_y;
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
	void		*mlx;
	void		*win;
	char		*fractale;
	t_data		img;
	t_var		v;
}					t_fractol;

/*
**	event.c
*/

void				move_img(t_fractol *e, t_data *black_screen,
	int dx, int dy);
int					key_hook(int keycode, void *param);
int					mouse_hook(int button, int x, int y, void *param);
void				zoomer(t_fractol *mlx, t_data *black_screen, double value);
void	an_screen(t_fractol *mlx, t_data *e);

/*
**	cleaners.c
*/

void				clean_exit(t_fractol *e);
void				clean_screen(t_fractol *mlx, t_data *e);

/*
**	algos.c
*/

void				init_variables(t_fractol *e);
void				mandelbrot(t_fractol *e);
void				init_fractale(t_fractol *e);

/*
**	fdf.c
*/

void				init_mlx(t_fractol e);

#endif