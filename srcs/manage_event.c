/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:00:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/20 08:36:02 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		set_event(t_event *ev, int kc, int (*f)(t_w3d *))
{
	ev->keycode = kc;
	ev->f = f;
}

int			init_event(t_w3d *e)
{
	set_event(e->events, 53, f_exit);
	set_event(e->events + 1, 126, f_up);
	set_event(e->events + 2, 125, f_down);
	set_event(e->events + 3, 123, f_left);
	set_event(e->events + 4, 124, f_right);
	set_event(e->events + 5, 49, f_jump);
	set_event(e->events + 6, 1, f_sprint);
	set_event(e->events + 7, 0, f_shft_left);
	set_event(e->events + 8, 2, f_shft_right);
	return (0);
}

int			handle_press(int kc, void *data)
{
	t_w3d			*e;
	int			i;

	e = (t_w3d *)data;
	i = 1;
	handle_keyclick(kc, data);
	while (i < NB_EVENT)
	{
		if (e->events[i].keycode == kc)
			e->events[i].pressed = 1;
		i++;
	}
	ft_printf("keycode %d\n", kc);
	return (0);
}
	
int			handle_release(int kc, void *data)
{
	t_w3d			*e;
	int			i;

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

int			apply_event(void *data)
{
	t_w3d			*e;
	int			i;

	e = (t_w3d *)data;
	i = 0;
	while (i < NB_EVENT)
	{
		if (e->events[i].pressed)
			e->events[i].f(e);
		i++;
	}
	return (0);
}

int			handle_keyclick(int kc, void *data)
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
		system(e->play ? "killall -CONT afplay 2&>/dev/null" :
			"killall -STOP afplay 2&> /dev/null");
	}
	return (0);
}
