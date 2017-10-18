/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_event1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/18 13:59:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			f_up(t_w3d *e)
{
	double		tmp;

	if ((tmp = e->pos.x + e->dir.x / e->sprint) >= 0 && tmp < e->height
			&& !e->map[(int)(tmp)][(int)e->pos.y])
		e->pos.x = tmp;
	if ((tmp = e->pos.y + e->dir.y / e->sprint) >= 0 && tmp < e->width
			&& !e->map[(int)e->pos.x][(int)(tmp)])
		e->pos.y = tmp;
	return (0);
}

int			f_down(t_w3d *e)
{
	double		tmp;

	if ((tmp = e->pos.x - e->dir.x / e->sprint) >= 0 && tmp < e->height
			&& !e->map[(int)(tmp)][(int)e->pos.y])
		e->pos.x = tmp;
	if ((tmp = e->pos.y - e->dir.y / e->sprint) >= 0 && tmp < e->width
			&& !e->map[(int)e->pos.x][(int)(tmp)])
		e->pos.y = tmp;
	return (0);
}

int			f_left(t_w3d *e)
{
	double		tmp;
	double		rspd;

	rspd = 0.03;
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

	rspd = -0.03;
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
	system("killall afplay 2>&- 1>&-");
	exit(0);
	return (0);
}
