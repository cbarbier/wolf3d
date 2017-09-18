/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:07:45 by cbarbier          #+#    #+#             */
/*   Updated: 2016/12/20 17:54:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	unsigned int		add_int(t_w3d *e, char *ptr, int *res)
{
	unsigned int	index;
	char			*tmp;

	(void)e;
	index = 0;
	while (ptr[index] != ' ' && ptr[index])
		index++;
	tmp = ft_strsub(ptr, 0, index);
	*res = ft_atoi(tmp);
	ft_strdel(&tmp);
	while (ptr[index] && ptr[index] == ' ')
		index++;
	return (index);
}

static int			*str_to_int_tab(t_w3d *e, char const *s)
{
	int				*res;
	char			*ptr;
	int				i_res;

	if (!s)
		return (0);
	ptr = (char *)s;
	if (!(res = (int *)ft_memalloc(e->width * sizeof(int))))
		return (0);
	while (*ptr && *ptr == ' ')
		ptr++;
	i_res = 0;
	while (i_res < e->width)
	{
		ptr += add_int(e, ptr, res + i_res);
		i_res++;
	}
	return (res);
}

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
		tab = str_to_int_tab(e, line);
		e->map = add_new_line(e->map, tab);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (ret);
}

int				load_map(t_w3d *e)
{
	int		ret;
	int		fd;
	char	*line;
	int		index;

	if ((fd = open("maps/map", O_RDONLY)) == -1)
		return (0);
	index = 0;
	line = 0;
	ret = loadin_to_tab(e, fd, line, &index);
	close(fd);
	if (!ret)
		return (1);
	if (!index)
		return (0);
	while (index--)
		ft_memdel((void **)&(e->map[index]));
	ft_memdel((void **)&(e->map));
	return (0);
}
