/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/19 10:34:45 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int			draw_raycast(t_w3d *e)
{
	int		i;

	i = 0;
	while (i < W_WIDTH)
	{
		raycasting(e, i);
		i++;
	}
	return (1);
}

int			w3d_core(t_w3d *e)
{
	if (e->exit)
		f_exit(e);
	if (!e->events[6].pressed || !e->sprint_life)
		e->sprint = 10.0;
	ft_memcpy(e->data, e->dsky, 4 * W_WIDTH * W_HEIGHT);
	apply_event(e);
	draw_raycast(e);
	draw_radar(e);
	draw_sprint_bar(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
