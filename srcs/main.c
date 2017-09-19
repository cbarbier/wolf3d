/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/19 12:02:00 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	w3d_core(t_w3d *e)
{
	int		i;

	i = 0;
	while (i < W_WIDTH)
	{
		raycasting(e, i);
		i++;
	}
	mlx_loop(e->mlx);
	return (1);
}

static int	init_w3d(t_w3d *e)
{
	ft_printf("map w: %d & h: %d\n", e->width, e->height);
	e->pos.x = 22.0;
	e->pos.y = 12.0;
	e->dir.x = -1.0;
	e->dir.y = 0.0;
	return (0);
}

int			main(int argc, char **argv)
{
	t_w3d		e;

	(void)argc;
	(void)argv;
	ft_bzero(&e, sizeof(t_w3d));
	if (!load_map(&e))
		return (0);
	ft_printf("map loaded\n");
	if (init_env(&e))
		return (1);
	init_w3d(&e);
	ft_printf("env initialized\n");
	w3d_core(&e);
	free_w3d(&e);
	return (0);
}
