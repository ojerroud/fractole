/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                              :+:      :+:    :+:   */
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

# define WIN_WIDTH_MIN	200
# define WIN_WIDTH_MAX	2560

/*
** taille y
*/

# define WIN_HEIGHT_MIN	200
# define WIN_HEIGHT_MAX	1440

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

#endif
