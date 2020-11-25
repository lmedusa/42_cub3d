/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:37:28 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/25 14:37:30 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		validate_map(t_all *all, char **m)
{
	int		x;
	int		y;

	y = -1;
	while (m[++y])
	{
		x = -1;
		while (m[y][++x])
		{
			if (m[y][x] != '1' && m[y][x] != ' ' && m[y][x])
			{
				if (x == 0 || x == all->map_h - 1)
					ft_exit("Map is broken.", all);
				if (y == 0 || y == all->map_v - 1)
					ft_exit("Map is broken.", all);
				if (x + 1 < all->map_h && m[y][x + 1] == ' ')
					ft_exit("Map is broken.", all);
				if (m[y][x - 1] == ' ' || m[y - 1][x] == ' ')
					ft_exit("Map is broken.", all);
				if (y + 1 < all->map_v && m[y + 1][x] == ' ')
					ft_exit("Map is broken.", all);
			}
		}
	}
}

void		validate_color(char *str, t_all *all)
{
	int		flg;

	flg = 0;
	while (*str)
	{
		if (*str == ',')
			flg++;
		str++;
	}
	if (flg != 2)
		ft_exit("Invalid RGB config.", all);
}

void		check_flags(t_maputil *f, t_all *all)
{
	if (f->flg_ea > 1 || f->flg_ea == 0)
		ft_exit("East texture error.", all);
	if (f->flg_we > 1 || f->flg_we == 0)
		ft_exit("West texture error.", all);
	if (f->flg_so > 1 || f->flg_so == 0)
		ft_exit("South texture error.", all);
	if (f->flg_no > 1 || f->flg_no == 0)
		ft_exit("North texture error.", all);
	if (f->flg_s > 1 || f->flg_s == 0)
		ft_exit("Sprite texture error.", all);
	if (f->flg_r > 1 || f->flg_r == 0)
		ft_exit("Resolution error.", all);
	if (f->flg_c > 1 || f->flg_c == 0)
		ft_exit("Celling color error.", all);
	if (f->flg_f > 1 || f->flg_f == 0)
		ft_exit("Floor color error.", all);
}

void		parse_config(t_list *tmp, t_all *all, t_maputil *map)
{
	while (tmp)
	{
		map->len = ft_strlen(tmp->content);
		if (ft_strnstr(tmp->content, "R ", map->len))
			resolution(tmp->content, all, map);
		else if (ft_strnstr(tmp->content, "NO ", map->len))
			ft_texture(tmp->content, all, 1, map);
		else if (ft_strnstr(tmp->content, "SO ", map->len))
			ft_texture(tmp->content, all, 2, map);
		else if (ft_strnstr(tmp->content, "WE ", map->len))
			ft_texture(tmp->content, all, 3, map);
		else if (ft_strnstr(tmp->content, "EA ", map->len))
			ft_texture(tmp->content, all, 4, map);
		else if (ft_strnstr(tmp->content, "S ", map->len))
			ft_texture(tmp->content, all, 5, map);
		else if (ft_strnstr(tmp->content, "F ", map->len))
			rgb_to_hex(tmp->content, all, 1, map);
		else if (ft_strnstr(tmp->content, "C ", map->len))
			rgb_to_hex(tmp->content, all, 2, map);
		else
			parse_str(tmp->content, all);
		tmp = tmp->next;
	}
	check_flags(map, all);
}
