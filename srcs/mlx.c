/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/18 08:32:52 by cbarbier         ###   ########.fr       */
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
	if ((e->sky = mlx_xpm_file_to_image(e->mlx, "assets/sky.xpm", &h, &w)))
		e->dsky = mlx_get_data_addr(e->sky, &(e->bpp), &(e->sizeline), &ed);
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

int			draw_vline(t_w3d *e, t_dda *g, t_ray *r, int iw)
{
	int			i;

	i = 0;
	while (i < W_HEIGHT)
	{
		if (i > r->end)
			put_pxl_img(e, iw, i, 0xc5c5c5);
		else if (i > r->start)
		{
			apply_tex(e, g, r, i);
			put_pxl_img(e, iw, i, r->color);
		}
		else if (!e->sky)
			put_pxl_img(e, iw, i, 0x330000);
		i++;
	}
	return (1);
}
