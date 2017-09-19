/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/19 12:14:32 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>
# define DEBUG		0
# define NB_THREAD	4
# define W_WIDTH	800
# define W_HEIGHT	800

typedef struct			s_vec
{
	double		x;
	double		y;
}				t_vec;
typedef struct			s_w3d
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	t_vec		pos;
	t_vec		dir;
	t_vec		plane;
	int			**map;
	int			width;
	int			height;
}				t_w3d;
/*
** 	CORE FUNCTIONS
*/
int			init_env(t_w3d *e);
void		put_pxl_img(t_w3d *e, int x, int y, unsigned int c);
int			load_map(t_w3d *e);
int			free_w3d(t_w3d *e);
/*
** 	DEBUG FUNCTIONS
*/
int			put_map(t_w3d *e);
#endif
