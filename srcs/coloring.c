/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:15:57 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/12 15:19:50 by cbarbier         ###   ########.fr       */
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
