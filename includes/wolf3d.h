/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/18 13:17:27 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>
# define DEBUG			0
# define NB_THREAD		4
# define W_WIDTH		800
# define W_HEIGHT		700
# define NB_EVENT		9
# define SPRINT_LIFE	200.0
# define TEX_DIM		64

struct s_w3d;
typedef struct	s_event
{
	int		keycode;
	int		pressed;
	int		(*f)(struct s_w3d *e);
}				t_event;
typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;
typedef struct	s_ray
{
	int				start;
	int				end;
	unsigned int	color;
	double			dist;
	int				wallheight;
}				t_ray;
typedef struct	s_dda
{
	int			mx;
	int			my;
	int			side;
	t_vec		rdir;
	t_vec		ddst;
	t_vec		sdst;
	int			stpx;
	int			stpy;
	int			val;
}				t_dda;
typedef struct	s_w3d
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	void			*sky;
	char			*dsky;
	char			*file;
	int				bpp;
	int				sizeline;
	t_vec			pos;
	t_vec			dir;
	t_vec			plane;
	double			camx;
	int				**map;
	int				width;
	int				height;
	int				minimap;
	int				horizon;
	int				jump;
	double			sprint;
	double			sprint_life;
	t_event			events[NB_EVENT];
	unsigned int	tex[TEX_DIM * TEX_DIM];
	int				exit;
	int				play;
}				t_w3d;
/*
** 	CORE FUNCTIONS
*/
int				w3d_core(t_w3d *e);
int				load_map(t_w3d *e, char *file);
int				raycasting(t_w3d *e, int iw);
int				free_w3d(t_w3d *e);
int				set_color(t_w3d *e, t_dda *g, t_ray *r);
int				apply_tex(t_w3d *e, t_dda *g, t_ray *r, int i);
/*
** 	MLX FUNCTIONS
*/
int				init_env(t_w3d *e);
int				init_event(t_w3d *e);
void			put_pxl_img(t_w3d *e, int x, int y, unsigned int c);
int				draw_vline(t_w3d *e, t_dda *g, t_ray *r, int iw);
int				apply_event(void *data);
int				handle_press(int kc, void *data);
int				handle_release(int kc, void *data);
int				handle_keyclick(int kc, void *data);
int				draw_radar(t_w3d *e);
int				draw_sprint_bar(t_w3d *e);
/*
** 	EVENT FUNCTIONS
*/
int				f_exit(t_w3d *e);
int				f_up(t_w3d *e);
int				f_down(t_w3d *e);
int				f_left(t_w3d *e);
int				f_right(t_w3d *e);
int				f_jump(t_w3d *e);
int				f_sprint(t_w3d *e);
int				f_shft_left(t_w3d *e);
int				f_shft_right(t_w3d *e);
/*
** 	DEBUG FUNCTIONS
*/
int				put_map(t_w3d *e);
#endif
