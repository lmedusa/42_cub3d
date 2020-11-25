/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:30:00 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/23 18:30:03 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	spr_parse(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->spr_count)
	{
		all->spr_util[i].dir = atan2(all->spr_util[i].y - all->plr.y, \
		all->spr_util[i].x - all->plr.x);
		while (all->spr_util[i].dir - all->plr.pov > M_PI)
			all->spr_util[i].dir -= 2 * M_PI;
		while (all->spr_util[i].dir - all->plr.pov < -M_PI)
			all->spr_util[i].dir += 2 * M_PI;
		all->spr_util[i].dir -= all->plr.pov;
		all->spr_util[i].dist = sqrt(pow((all->spr_util[i].x \
		- all->plr.x), 2) + pow((all->spr_util[i].y - all->plr.y), 2));
		all->spr_util[i].size = (64 / all->spr_util[i].dist) * \
		(all->img.wdh / 2) / tan(FOV / 2);
		all->spr_util[i].h = all->img.wdh / (FOV * (180 / M_PI)) * \
		((180 / M_PI * all->spr_util[i].dir) + 30) - all->spr_util[i].size / 2;
		all->spr_util[i].v = all->img.hgt / \
		2 - all->spr_util[i].size / 2;
		all->spr_util[i].offset = all->sprite.img.hgt / all->spr_util[i].size;
		all->spr_util[i].tex = 0;
		i++;
	}
}

void	sprite_sort(t_all *all)
{
	int		i;
	int		j;
	t_spr	tmp;

	i = 0;
	while (i < all->spr_count)
	{
		j = 0;
		while (j < all->spr_count - 1)
		{
			if (all->spr_util[j].dist < all->spr_util[j + 1].dist)
			{
				tmp = all->spr_util[j];
				all->spr_util[j] = all->spr_util[j + 1];
				all->spr_util[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	render_spr(t_all *all)
{
	int		i;

	i = 0;
	spr_parse(all);
	sprite_sort(all);
	while (i < all->spr_count)
	{
		draw_sprite(all, all->spr_util[i]);
		i++;
	}
}

void	sprites(t_all *all)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	all->spr_util = malloc(sizeof(t_spr) * all->spr_count);
	if (!(all->spr_util))
		exit(0);
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '2')
			{
				all->spr_util[i].x = (x + 0.5) * 64;
				all->spr_util[i].y = (y + 0.5) * 64;
				i++;
			}
			x++;
		}
		y++;
	}
}
