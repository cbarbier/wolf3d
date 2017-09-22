/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/20 10:34:17 by cbarbier         ###   ########.fr       */
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
# define NB_EVENT	5

typedef struct s_w3d		t_w3d;
typedef struct 			s_event
{
	int		keycode;
	int		(*f)(t_w3d *e);
}				t_event;
typedef struct			s_vec
{
	double		x;
	double		y;
}				t_vec;
typedef struct			s_ray
{
	int		start;
	int		end;
	unsigned int	color;
}				t_ray;
typedef struct			s_dda
{
	int		mx;
	int		my;
	int		side;
	t_vec		rdir;
	t_vec		ddst;
	t_vec		sdst;
	int		stpx;
	int		stpy;
	int		val;
}				t_dda;
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
	double		camx;
	int			**map;
	int			width;
	int			height;
	t_event		events[NB_EVENT];
}				t_w3d;
/*
** 	CORE FUNCTIONS
*/
int			load_map(t_w3d *e);
int			raycasting(t_w3d *e, int iw);
int			free_w3d(t_w3d *e);
/*
** 	MLX FUNCTIONS
*/
int			init_env(t_w3d *e);
int			init_event(t_w3d *e);
void		put_pxl_img(t_w3d *e, int x, int y, unsigned int c);
int			draw_vline(t_w3d *e, t_ray *r, int iw);
int			draw(t_w3d *e);
int			handle_event(int kc, void *data);
int			draw_radar(t_w3d *e);
/*
** 	EVENT FUNCTIONS
*/
int			f_exit(t_w3d *e);
int			f_up(t_w3d *e);
int			f_down(t_w3d *e);
int			f_left(t_w3d *e);
int			f_right(t_w3d *e);
/*
** 	DEBUG FUNCTIONS
*/
int			put_map(t_w3d *e);
#endif
