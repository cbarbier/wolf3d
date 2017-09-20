/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:03:21 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/20 16:14:17 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	draw_case(t_w3d *e, int x, int y, unsigned int c)
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
			put_pxl_img(e, x + i, y + j, c);
			i++;
		}
		j++;
	}
	return (1);
}

static int	draw_line(t_w3d *e, int *map, int yp)
{
	int		i;
	int		xp;

	xp = 5;
	i = -1;
	while (i <= e->width)
	{
		if (i < 0 || i == e->width || !map || map[i])
				draw_case(e, xp, yp, 0xDD00CC);
		xp += 4;
		i++;
	}
	return (1);
}

int			draw_radar(t_w3d *e)
{
	int			**map;
	int			yp;

	map = e->map;
	yp = 10;
	draw_line(e, 0, 6);
	while (*map)
	{
		draw_line(e, *map++, yp);
		yp += 4;
	}
	draw_line(e, 0, yp);
	draw_case(e, 10 + (int)e->pos.y * 4, 9 + (int)e->pos.x * 4, 0xEEEEEE);
	return (1);
}
