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
**	my struct table
*/

typedef struct		s_coord
{
	int			x;
	int			y;
	int			z;
	int			color;
}					t_coord;

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	t_coord			**tab;
}					t_fractol;

#endif
