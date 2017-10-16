/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr33.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:10:28 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/19 10:37:06 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	free_map(int ***amap)
{
	int		**map;

	map = *amap;
	while (*map)
		free(*map++);
	if (*amap)
		free(*amap);
	*amap = 0;
	return (0);
}

int			free_w3d(t_w3d *e)
{
	free_map(&e->map);
	if (e->img)
		mlx_destroy_image(e->mlx, e->img);
	if (e->sky)
		mlx_destroy_image(e->mlx, e->sky);
	if (e->win)
		mlx_destroy_window(e->mlx, e->win);
	return (0);
}
