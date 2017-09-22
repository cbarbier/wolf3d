/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_dir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/20 09:55:22 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			f_up(t_w3d *e)
{
	double		tmp;

	if ((tmp = e->pos.x + e->dir.x) >= 0 && tmp < e->height
			&& !e->map[(int)(e->pos.x + e->dir.x)][(int)e->pos.y])
		e->pos.x = tmp;
	if ((tmp = e->pos.y + e->dir.y) >= 0 && tmp < e->width
			&& !e->map[(int)e->pos.x][(int)(e->pos.y + e->dir.y)])
		e->pos.y = tmp;
	return (0);
}

int			f_down(t_w3d *e)
{
	double		tmp;

	if ((tmp = e->pos.x - e->dir.x) >= 0 && tmp < e->height
			&& !e->map[(int)(e->pos.x - e->dir.x)][(int)e->pos.y])
		e->pos.x = tmp;
	if ((tmp = e->pos.y - e->dir.y) >= 0 && tmp < e->width
			&& !e->map[(int)e->pos.x][(int)(e->pos.y - e->dir.y)])
		e->pos.y = tmp;
	return (0);
}

int			f_left(t_w3d *e)
{
	double		tmp;
	double		rspd;

	rspd = 0.1;
	tmp = e->dir.x;
	e->dir.x = e->dir.x * cos(rspd) - e->dir.y * sin(rspd);
	e->dir.y = tmp * sin(rspd) + e->dir.y * cos(rspd);
	tmp = e->plane.x;
	e->plane.x = e->plane.x * cos(rspd) - e->plane.y * sin(rspd);
	e->plane.y = tmp * sin(rspd) + e->plane.y * cos(rspd);
	return (0);
}

int			f_right(t_w3d *e)
{
	double		tmp;
	double		rspd;

	rspd = -0.1;
	tmp = e->dir.x;
	e->dir.x = e->dir.x * cos(rspd) - e->dir.y * sin(rspd);
	e->dir.y = tmp * sin(rspd) + e->dir.y * cos(rspd);
	tmp = e->plane.x;
	e->plane.x = e->plane.x * cos(rspd) - e->plane.y * sin(rspd);
	e->plane.y = tmp * sin(rspd) + e->plane.y * cos(rspd);
	return (0);
}

int			f_exit(t_w3d *e)
{
	free_w3d(e);
	exit(0);
	return (0);
}
