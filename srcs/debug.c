/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/19 10:34:45 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			put_map(t_w3d *e)
{
	int		**map;
	int		*tab;
	int		i;

	map = e->map;
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
