/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:03:21 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/20 11:52:55 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	draw_case(t_w3d *e, int x, int y)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if ((int)e->pos.x == i && (int)e->pos.y == y)
				put_pxl_img(e, x + i, y + j, 0x00FFFF);
			else
				put_pxl_img(e, x + i, y + j, 0xFFFFFF);
			i++;
		}
		j++;
	}
	return (1);
}

static int	draw_line(t_w3d *e, int *map, int w, int y)
{
	int		i;
	int		x;

	x = 5;
	i = -1;
	while (i <= w)
	{
		if (i < 0 || i == w || !map || map[i])
			draw_case(e, x, y);
		x += 4;
		i++;
	}
	return (1);
}

int			draw_radar(t_w3d *e)
{
	int			**map;
	int			h;
	int			y;

	h = e->height;
	map = e->map;
	y = 10;
	draw_line(e, 0, e->width, 6);
	while (*map)
	{
		draw_line(e, *map++, e->width, y);
		y += 4;
	}
	draw_line(e, 0, e->width, y);
	return (1);
}
