/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:35:13 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/23 18:35:14 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render_wall(int side, float x, float len, t_all *all)
{
	double			plane;
	t_render		ren;

	ft_bzero(&ren, sizeof(t_render));
	plane = (all->img.wdh / 2) / tan(M_PI / 6);
	ren.col = 64 / len * plane;
	ren.point = (all->img.hgt / 2) - ren.col / 2;
	ren.tmp = ren.point;
	ren.col_true = ren.col;
	if (ren.col >= all->img.hgt)
		ren.col = all->img.hgt - 1;
	while (ren.point <= ren.tmp + ren.col_true)
	{
		if (ren.point < 0)
			ren.point = 0;
		ren.zy = (ren.point - ren.tmp) / ren.col_true;
		if (!side)
			ren.color = all->tmp_color;
		else
			ren.color = get_texture(all, side, all->text_coord, ren.zy);
		all->tmp_color = ren.color;
		my_mlx_pixel_put(&all->img, x, ren.point, ren.color);
		ren.point++;
	}
}

void	draw_sprite(t_all *all, t_spr s)
{
	int		y;
	int		x;

	s.i = -1;
	s.col = NULL;
	while (++s.i < (int)s.size)
	{
		if (s.h + s.i > all->img.wdh || s.h + s.i < 0 || \
		all->rays[s.i + (int)s.h].len < s.dist)
			continue;
		x = s.i / s.size * all->sprite.img.wdh;
		s.tex = 0;
		s.j = -1;
		while (++s.j < s.size)
		{
			y = (unsigned int)s.tex;
			s.col = (unsigned int *)(all->sprite.img.addr + \
			(y * all->sprite.img.len + x * (all->sprite.img.bpp / 8)));
			s.tex += s.offset;
			if (s.v + s.j > all->img.hgt || \
			s.v + s.j < 0 || *s.col == 0xFF000000)
				continue;
			my_mlx_pixel_put(&all->img, s.h + s.i, s.v + s.j, *s.col);
		}
	}
}

void	render(t_all *all)
{
	mlx_do_sync(all->win.mlx);
	plr_util(all);
	background(0, 0, all, all->cell);
	background(0, all->img.hgt / 2, all, all->floor);
	all->plr.start = all->plr.pov - M_PI / 6;
	all->plr.end = all->plr.start + M_PI / 3;
	raycast(all);
	render_spr(all);
}
