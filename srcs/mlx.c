/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/12 15:12:58 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			init_env(t_w3d *e)
{
	int		ed;
	int		w;
	int		h;

	if (!(e->mlx = mlx_init()))
		return (1);
	if (!(e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "wolf3d")))
		return (1);
	if (!(e->img = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT)))
		return (1);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &ed);
	h = W_HEIGHT;
	w = W_WIDTH;
	e->sky = mlx_xpm_file_to_image(e->mlx, "assets/sky.xpm", &h, &w);
	e->dsky = mlx_get_data_addr(e->sky, &(e->bpp), &(e->sizeline), &ed);
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

int			draw_vline(t_w3d *e, t_ray *r, int iw)
{
	int			i;

	i = 0;
	while (i < W_HEIGHT)
	{
		if (i > r->end)
			put_pxl_img(e, iw, i, 0xc5c5c5);
		else if (i > r->start)
			put_pxl_img(e, iw, i, r->color);
		i++;
	}
	return (1);
}
