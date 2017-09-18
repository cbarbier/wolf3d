/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/07/21 11:40:49 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
	
static int	w3d_core(t_w3d *e)
{
	int		**map;
	int		i;

	if (!load_map(e))
		return (0);
	map = e->map;
	while (*map)
	{
	 	i = 0;
		while (i < e->width)
			ft_printf("%i ", (*map)[i++]);
		ft_printf("\n");
		map++;
	}	
	return (1);
}

int		main(int argc, char **argv)
{
	t_w3d		e;

	(void)argc;
	(void)argv;
	ft_bzero(&e, sizeof(t_w3d));
	ft_printf("wolf 3d in progress\n");
	if (init_env(&e))
		return (1);
	ft_printf("env initialized\n");
	w3d_core(&e);
	while (1);
	return (0);
}
