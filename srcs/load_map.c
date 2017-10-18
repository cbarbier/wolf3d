/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:07:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/18 17:06:36 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int			wdth(char *ptr)
{
	unsigned int	nbnum;

	nbnum = 0;
	while (*ptr)
	{
		if (*ptr != ' ')
		{
			while (*ptr && *ptr != ' ')
				ptr++;
			nbnum++;
		}
		else
			ptr++;
	}
	return (nbnum);
}

static int			**add_new_line(int **tab, int *l)
{
	int		len;
	int		i;
	int		**res;

	len = 0;
	while (tab && tab[len])
		len++;
	len += 2;
	if (!(res = (int **)ft_memalloc(len * sizeof(int*))))
		return (0);
	i = 0;
	while (i < len - 2)
	{
		res[i] = tab[i];
		i++;
	}
	res[i] = l;
	if (tab)
		free(tab);
	return (res);
}

static int			loadin_to_tab(t_w3d *e, int fd, char *line, int *i)
{
	int		ret;
	int		*tab;

	*i = 0;
	while ((ret = get_next_line(fd, &line)) > 0 && ++(*i))
	{
		if (*i == 1)
			e->width = wdth(line);
		else if (wdth(line) != e->width)
			return (1);
		tab = ft_str_to_int_tab(line, e->width);
		e->map = add_new_line(e->map, tab);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (i && ret);
}

int					load_map(t_w3d *e, char *file)
{
	int		ret;
	int		fd;
	char	*line;
	int		index;

	e->file = file;
	if ((fd = open(e->file ? file : "maps/map", O_RDONLY)) == -1)
		return (0);
	index = 0;
	line = 0;
	ret = loadin_to_tab(e, fd, line, &index);
	close(fd);
	e->height = index;
	if (!ret)
		return (e->width < 100 && e->height < 100);
	if (!index)
		return (0);
	while (index--)
		ft_memdel((void **)&(e->map[index]));
	ft_memdel((void **)&(e->map));
	return (0);
}
