/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 08:41:16 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/18 13:54:23 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				handle_press(int kc, void *data)
{
	t_w3d			*e;
	int				i;

	e = (t_w3d *)data;
	i = 1;
	handle_keyclick(kc, data);
	while (i < NB_EVENT)
	{
		if (e->events[i].keycode == kc)
			e->events[i].pressed = 1;
		i++;
	}
	return (0);
}

int				handle_release(int kc, void *data)
{
	t_w3d			*e;
	int				i;

	e = (t_w3d *)data;
	i = 1;
	while (i < NB_EVENT)
	{
		if (e->events[i].keycode == kc)
			e->events[i].pressed = 0;
		i++;
	}
	return (0);
}

int				handle_keyclick(int kc, void *data)
{
	t_w3d		*e;

	e = (t_w3d *)data;
	if (kc == 53)
		e->exit = 1;
	else if (kc == 46)
		e->minimap = !(e->minimap);
	else if (kc == 35)
	{
		e->play = !e->play;
		if (e->play)
			system("test -f assets/sound.mp3 && killall -CONT afplay 2>&-");
		else
			system("test -f assets/sound.mp3 && killall -STOP afplay 2>&-");
	}
	return (0);
}
