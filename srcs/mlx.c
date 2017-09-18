/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/27 16:58:36 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			init_env(t_w3d *e)
{
	int		ed;

	if (!(e->mlx = mlx_init()))
		return (1);
	if (!(e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "wolf3d")))
		return (1);
	if (!(e->img = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT)))
		return (1);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &ed);
	/*
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	*/
	return (0);
}

void		put_pxl_img(t_w3d *e, int x, int y, unsigned int c)
{
	char		*d;

	d = (e->data + (e->sizeline * y + x * e->bpp / 8));
	d[0] = (c & 0xFF0000) >> 16;
	d[1] = (c & 0xFF00) >> 8;
	d[2] = (c & 0xFF);
}