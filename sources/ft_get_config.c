/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:40:33 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/25 14:40:34 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	resolution(char *str, t_all *all, t_maputil *map)
{
	int		w;
	int		h;

	mlx_get_screen_size(all->win.mlx, &w, &h);
	if (all->win.w != -1 || all->win.h != -1)
		ft_exit("Why? Why you set multiple resolution?", all);
	while (*str && *str == ' ')
		str++;
	str++;
	all->win.w = ft_atoi(str);
	while (*str && *str == ' ')
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	all->win.h = ft_atoi(str);
	if (all->win.h <= 0 || all->win.w <= 0)
		exit(0);
	if (all->win.w > w)
		all->win.w = w;
	if (all->win.h > h)
		all->win.h = h;
	map->flg_r += 1;
}

void	validate_range(int r, int g, int b, t_all *all)
{
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		ft_exit("Invalid color range. Try 0-255 range.", all);
}

void	rgb_to_hex(char *str, t_all *all, int flag, t_maputil *map)
{
	int				c[3];

	while (*str && !ft_isdigit(*str))
		str++;
	validate_color(str, all);
	c[0] = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		str++;
	str++;
	c[1] = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		str++;
	str++;
	c[2] = ft_atoi(str);
	validate_range(c[0], c[1], c[2], all);
	if (flag == 2)
		all->floor = get_color(c[0], c[1], c[2]);
	if (flag == 1)
		all->cell = get_color(c[0], c[1], c[2]);
	if (flag == 2)
		map->flg_f += 1;
	if (flag == 1)
		map->flg_c += 1;
}

int		check_plr(t_all *all, char m, int x, int y)
{
	if (m == '1' || m == '2' || m == '0' || m == ' ')
		return (0);
	else if (m == 'N')
		all->plr.pov = M_PI + M_PI / 2;
	else if (m == 'W')
		all->plr.pov = M_PI;
	else if (m == 'S')
		all->plr.pov = M_PI / 2;
	else if (m == 'E')
		all->plr.pov = 0;
	all->plr.x = x + 32;
	all->plr.y = y + 32;
	return (1);
}

void	parse_map(t_all *all, t_map mp)
{
	while (all->map[mp.i])
	{
		mp.j = 0;
		while (all->map[mp.i][mp.j] != '\0')
		{
			if (ft_is_valid(all->map[mp.i][mp.j], "NSWE102 ") == 0)
				ft_exit("Invalid symbols on map.", all);
			if (all->map[mp.i][mp.j] == '2')
				all->spr_count++;
			if (check_plr(all, all->map[mp.i][mp.j], mp.x, mp.y) == 1)
			{
				mp.flg += 1;
				all->map[mp.i][mp.j] = '0';
			}
			mp.x += 64;
			mp.j++;
		}
		mp.i++;
		mp.x = 0;
		mp.y += 64;
	}
	if (mp.flg == 0 || mp.flg > 1)
		ft_exit("Wrong players number.", all);
}
