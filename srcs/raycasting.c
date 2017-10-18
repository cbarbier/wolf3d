/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 12:08:04 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/18 13:14:08 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	calc_dist_n_height(t_w3d *e, t_dda *g, t_ray *r)
{
	if (!g->side)
		r->dist = (g->mx - e->pos.x + (1 - g->stpx) / 2) / g->rdir.x;
	else
		r->dist = (g->my - e->pos.y + (1 - g->stpy) / 2) / g->rdir.y;
	r->wallheight = (int)(W_HEIGHT / r->dist);
	e->jump = e->events[5].pressed ? 50 : 0;
	r->start = e->horizon + e->jump - r->wallheight / 2;
	r->start = r->start < 0 ? 0 : r->start;
	r->end = e->horizon + e->jump + r->wallheight / 2;
	r->end = r->end >= W_HEIGHT ? W_HEIGHT - 1 : r->end;
	set_color(e, g, r);
	return (1);
}

static int	dda(t_w3d *e, t_dda *g)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (g->sdst.x < g->sdst.y)
		{
			g->sdst.x += g->ddst.x;
			g->mx += g->stpx;
			g->side = 0;
		}
		else
		{
			g->sdst.y += g->ddst.y;
			g->my += g->stpy;
			g->side = 1;
		}
		if (g->mx == e->height || g->my == e->width
		|| g->mx < 0 || g->my < 0
		|| (g->val = e->map[g->mx][g->my]) > 0)
			hit = 1;
	}
	return (1);
}

static int	set_step_n_sdst(t_w3d *e, t_dda *g)
{
	if (g->rdir.x < 0)
	{
		g->stpx = -1;
		g->sdst.x = (e->pos.x - g->mx) * g->ddst.x;
	}
	else
	{
		g->stpx = 1;
		g->sdst.x = (g->mx + 1.0 - e->pos.x) * g->ddst.x;
	}
	if (g->rdir.y < 0)
	{
		g->stpy = -1;
		g->sdst.y = (e->pos.y - g->my) * g->ddst.y;
	}
	else
	{
		g->stpy = 1;
		g->sdst.y = (g->my + 1.0 - e->pos.y) * g->ddst.y;
	}
	return (1);
}

int			raycasting(t_w3d *e, int iw)
{
	t_dda		g;
	t_ray		ray;
	double		camx;

	camx = 2.0 * iw / (double)(W_WIDTH) - 1;
	g.rdir.x = e->dir.x + e->plane.x * camx;
	g.rdir.y = e->dir.y + e->plane.y * camx;
	g.mx = (int)e->pos.x;
	g.my = (int)e->pos.y;
	g.ddst.x = sqrt(1 + (g.rdir.y * g.rdir.y) / (g.rdir.x * g.rdir.x));
	g.ddst.y = sqrt(1 + (g.rdir.x * g.rdir.x) / (g.rdir.y * g.rdir.y));
	set_step_n_sdst(e, &g);
	dda(e, &g);
	calc_dist_n_height(e, &g, &ray);
	draw_vline(e, &g, &ray, iw);
	return (1);
}
