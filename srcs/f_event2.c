/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_event2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/20 09:55:22 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			f_jump(t_w3d *e)
{
	(void)e;
	return (0);
}

int			f_sprint(t_w3d *e)
{
	if (!e->sprint_life)
		return (0);
	e->sprint = 5.0;
	e->sprint_life -= 0.5;
	return (0);
}
