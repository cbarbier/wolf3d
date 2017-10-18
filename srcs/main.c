/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/18 15:17:06 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	init_tex(t_w3d *e)
{
	int		i;
	int		j;
	int		xcol;

	i = 0;
	while (i < TEX_DIM)
	{
		j = 0;
		while (j < TEX_DIM)
		{
			xcol = (i * 256 / TEX_DIM) ^ (j * 256 / TEX_DIM);
			e->tex[j * TEX_DIM + i] = 256 * xcol;
			j++;
		}
		i++;
	}
	return (0);
}

static int	set_start(t_w3d *e)
{
	int		i;
	int		j;

	if (!e->width || !e->height)
		return (0);
	j = e->height - 1;
	while (j)
	{
		i = e->width - 1;
		while (i)
		{
			if (!e->map[j][i])
			{
				e->pos.x = (double)j;
				e->pos.y = (double)i;
				return (1);
			}
			i--;
		}
		j--;
	}
	return (0);
}

static int	init_w3d(t_w3d *e)
{
	init_event(e);
	put_map(e);
	if (!set_start(e))
		return (0);
	e->dir.x = -1.0;
	e->dir.y = 0.0;
	e->plane.x = 0.0;
	e->plane.y = 0.66;
	e->horizon = W_HEIGHT / 2;
	e->sprint_life = SPRINT_LIFE;
	init_tex(e);
	e->play = 1;
	system("killall afplay 2>&- 1>&-;test -f assets/sound.mp3 && \
			afplay assets/sound.mp3&");
	return (1);
}

int			main(int argc, char **argv)
{
	t_w3d		e;

	if (argc > 2)
		return (ft_fprintf(2, "Usage: ./wolf3d [file]\n"));
	ft_bzero(&e, sizeof(t_w3d));
	if (!load_map(&e, argv[1]))
		return (ft_fprintf(2, "Error: can't load the map\n"));
	ft_printf("map loaded\n");
	if (init_env(&e) || !init_w3d(&e))
		return (ft_fprintf(2, "Error: can't init the env\n"));
	ft_printf("env initialized\n");
	mlx_hook(e.win, 2, (1L << 0), &handle_press, &e);
	mlx_hook(e.win, 3, (1L << 1), &handle_release, &e);
	mlx_loop_hook(e.mlx, w3d_core, &e);
	mlx_loop(e.mlx);
	free_w3d(&e);
	return (0);
}
