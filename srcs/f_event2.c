/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_event2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/18 08:35:50 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			f_jump(t_w3d *e)
{
	(void)e;
	return (0);
}

int			f_sprint(t_w3d *e)
{
	if (!e->sprint_life)
		return (0);
	e->sprint = 5.0;
	e->sprint_life -= 0.5;
	return (0);
}

int			f_shft_left(t_w3d *e)
{
	double		nx;
	double		ny;

	ny = e->pos.y - e->plane.y * 0.1;
	nx = e->pos.x - e->plane.x * 0.1;
	if (nx < 0 || (int)nx >= e->height || ny < 0 || (int)ny >= e->width
		|| e->map[(int)nx][(int)ny])
		return (0);
	e->pos.x = nx;
	e->pos.y = ny;
	return (0);
}

int			f_shft_right(t_w3d *e)
{
	double		nx;
	double		ny;

	ny = e->pos.y + e->plane.y * 0.1;
	nx = e->pos.x + e->plane.x * 0.1;
	if (nx < 0 || (int)nx >= e->height || ny < 0 || (int)ny >= e->width
		|| e->map[(int)nx][(int)ny])
		return (0);
	e->pos.x = nx;
	e->pos.y = ny;
	return (0);
}
