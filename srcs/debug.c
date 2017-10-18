/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/18 17:14:35 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			put_map(t_w3d *e)
{
	int		**map;
	int		*tab;
	int		i;

	if (!DEBUG || !(map = e->map))
		return (0);
	while (*map)
	{
		tab = *map;
		i = 0;
		while (i < e->width)
			ft_printf("%i", tab[i++]);
		ft_printf("\n");
		map++;
	}
	return (0);
}
