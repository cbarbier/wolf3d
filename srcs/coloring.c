/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:15:57 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/18 13:09:42 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				set_color(t_w3d *e, t_dda *g, t_ray *r)
{
	(void)e;
	if (g->val == 1)
		r->color = 0xFF0000;
	else if (g->val == 2)
		r->color = 0x00FF00;
	else if (g->val == 3)
		r->color = 0x0000FF;
	else if (g->val == 4)
		r->color = 0xFFFF00;
	else if (g->val == 5)
		r->color = 0x00FFFF;
	else
		r->color = 0xc8c8c8;
	if (g->side)
		r->color /= 2;
	return (0);
}

int				apply_tex(t_w3d *e, t_dda *g, t_ray *r, int i)
{
	int			tx;
	int			ty;
	int			d;
	double		wallx;

	if (g->val != 6)
		return (0);
	i -= e->jump;
	if (!g->side)
		wallx = e->pos.y + r->dist * g->rdir.y;
	else
		wallx = e->pos.x + r->dist * g->rdir.x;
	wallx -= floor(wallx);
	tx = (int)(wallx * TEX_DIM);
	if ((!g->side && g->rdir.x > 0) || (g->side && g->rdir.y < 0))
		tx = TEX_DIM - tx - 1;
	d = i * 256 - W_HEIGHT * 128 + r->wallheight * 128;
	ty = ((d * TEX_DIM) / r->wallheight) / 256;
	r->color = e->tex[TEX_DIM * ty + tx];
	if (g->side)
		r->color = (r->color >> 1) & 8355711;
	return (0);
}
