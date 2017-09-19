/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/19 20:00:29 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			draw(t_w3d *e)
{
	int		i;

	i = 0;
	while (i < W_WIDTH)
	{
		raycasting(e, i);
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (1);
}

static int	init_w3d(t_w3d *e)
{
	ft_printf("map w: %d & h: %d\n", e->width, e->height);
	e->pos.x = 15.0;
	e->pos.y = 12.0;
	e->dir.x = -1.0;
	e->dir.y = 0.0;
	e->plane.x = 0.0;
	e->plane.y = 0.66;
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
	draw(&e);
	mlx_key_hook(e.win, handle_key, (void *)&e);
	mlx_loop(e.mlx);
	free_w3d(&e);
	return (0);
}
/*
	mlx_hook(e.win, 2, (1L<<0), &key_press, &e);
	mlx_hook(e.win, 3, (1L<<1), &key_release, &e);
*/
