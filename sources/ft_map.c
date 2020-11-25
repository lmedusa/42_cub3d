/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:25:01 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/23 18:25:02 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_setspace(t_all *all, int max_h)
{
	int		i;
	int		size;
	char	*tmp;

	i = 0;
	size = 0;
	tmp = NULL;
	while (all->map[i])
	{
		size = ft_strlen(all->map[i]) + 1;
		if (size < max_h)
		{
			if (!(tmp = ft_strnew(max_h - size)))
				exit(0);
			ft_memset(tmp, ' ', max_h - size);
			all->map[i] = ft_strjoin(all->map[i], tmp);
			if (!all->map[i])
				ft_exit("Bad malloc.", all);
			free(tmp);
		}
		i++;
	}
}

void		make_map(t_all *all, int flag, int size)
{
	int		i;
	int		j;

	i = flag;
	j = 0;
	if (!(all->map = ft_calloc(size - flag + 1, sizeof(char *))))
		ft_exit("Error malloc.", all);
	while (all->map_buff[i])
	{
		all->map[j] = all->map_buff[i];
		all->map_h = all->map_h < ft_strlen(all->map[j]) ? \
		ft_strlen(all->map[j]) : all->map_h;
		j++;
		i++;
	}
	all->map_v = j + 1;
	all->map_h += 1;
	ft_setspace(all, all->map_h);
}

void		ft_map(t_list **head, t_all *all, int size)
{
	int			i;
	t_maputil	par;
	t_list		*tmp;

	if (size < 11)
		ft_exit("Invalid map.", all);
	i = -1;
	tmp = *head;
	ft_bzero(&par, sizeof(t_maputil));
	parse_config(tmp, all, &par);
	if (!(all->map_buff = ft_calloc(size + 1, sizeof(char *))))
		ft_exit("Error malloc.", all);
	while (tmp)
	{
		all->map_buff[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = 0;
	while (all->map_buff[i])
	{
		if (ft_check_line(all->map_buff[i]) == 1)
			break ;
		i++;
	}
	make_map(all, i, size);
}
