/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:00:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/20 08:36:02 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			handle_key(int kc, void *data)
{
	t_w3d			*e;
	double			tmp;
	double			rspd;

	rspd = 0.1;
	e = (t_w3d *)data;
	if (kc == 53)
	{
		free_w3d(e);
		exit(0);
	}
	//up = 126 down = 125
//	ft_printf("%i\n", kc);
	if (kc == 126)
	{
		if ((tmp = e->pos.x + e->dir.x) >= 0 && tmp < e->height
		&& !e->map[(int)(e->pos.x + e->dir.x)][(int)e->pos.y])
			e->pos.x = tmp;
		if ((tmp = e->pos.y + e->dir.y) >= 0 && tmp < e->width
		&& !e->map[(int)e->pos.x][(int)(e->pos.y + e->dir.y)])
			e->pos.y = tmp;
	}
	else if (kc == 125)
	{
		if ((tmp = e->pos.x - e->dir.x) >= 0 && tmp < e->height
		&& !e->map[(int)(e->pos.x - e->dir.x)][(int)e->pos.y])
			e->pos.x = tmp;
		if ((tmp = e->pos.y - e->dir.y) >= 0 && tmp < e->width
		&& !e->map[(int)e->pos.x][(int)(e->pos.y - e->dir.y)])
			e->pos.y = tmp;
	}
	else if (kc == 123 || kc == 124)
	{
		rspd = (kc == 124 ? -rspd : rspd);
		tmp = e->dir.x;
		e->dir.x = e->dir.x * cos(rspd) - e->dir.y * sin(rspd);
		e->dir.y = tmp * sin(rspd) + e->dir.y * cos(rspd);
		tmp = e->plane.x;
		e->plane.x = e->plane.x * cos(rspd) - e->plane.y * sin(rspd);
		e->plane.y = tmp * sin(rspd) + e->plane.y * cos(rspd);
	}
	draw(e);
	return (0);
}
