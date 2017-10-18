/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:03:21 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/18 08:40:09 by cbarbier         ###   ########.fr       */
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

static int	draw_bar(t_w3d *e, int xp, int energy)
{
	int		i;
	int		yp;
	int		len;
	int		c;

	yp = W_HEIGHT - 30;
	i = -1;
	len = energy ? energy : 102;
	c = (energy ? 0xCC0000 : 0x555555);
	while (i <= len)
	{
		draw_case(e, xp, yp + (energy ? 1 : 0), c);
		draw_case(e, xp, yp + (energy ? 3 : 4), c);
		xp += 4;
		i++;
	}
	return (1);
}

int			draw_sprint_bar(t_w3d *e)
{
	draw_bar(e, 10, 0);
	draw_bar(e, 15, (int)(e->sprint_life / 2));
	return (1);
}
