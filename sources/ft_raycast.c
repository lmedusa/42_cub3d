/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:44:25 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/23 18:44:26 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycast(t_all *all)
{
	float	hei;
	int		side;

	all->ray.len = 0;
	hei = 0;
	while (all->plr.start <= all->plr.end)
	{
		all->ray.x = all->plr.x;
		all->ray.y = all->plr.y;
		while (all->map[(int)(all->ray.y / 64)][(int)(all->ray.x / 64)] && \
		all->map[(int)(all->ray.y / 64)][(int)(all->ray.x / 64)] != '1')
		{
			all->ray.x += all->ray.step * cos(all->plr.start);
			all->ray.y += all->ray.step * sin(all->plr.start);
		}
		side = get_side(all->ray.x, all->ray.y, all->plr.start);
		all->text_coord = get_tex_coord(all->ray.x, all->ray.y, all);
		all->ray.len = sqrt(pow((all->plr.x - all->ray.x), 2) + \
		pow((all->plr.y - all->ray.y), 2));
		all->rays[(int)hei].len = all->ray.len;
		all->ray.len = all->ray.len * cos(all->plr.start - all->plr.pov);
		render_wall(side, hei++, all->ray.len, all);
		all->ray.len = 0;
		all->plr.start += FOV / all->img.wdh;
	}
}
