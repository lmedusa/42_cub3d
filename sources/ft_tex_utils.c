/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:28:36 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/23 18:28:37 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	get_pixel_from_text(t_text *text, float x, float y)
{
	int		ix;
	int		iy;
	int		*adr;

	if (x < 0 || x > 1 || y < 0 || y > 1)
		return (0x0);
	ix = x * (text->img.wdh - 1);
	iy = y * (text->img.hgt - 1);
	adr = (int *)text->img.addr;
	return (adr[text->img.wdh * iy + ix]);
}

unsigned int	get_texture(t_all *all, int side, float coord, float y)
{
	if (side == 2)
		return (get_pixel_from_text(&all->e, coord, y));
	if (side == 3)
		return (get_pixel_from_text(&all->w, coord, y));
	if (side == 1)
		return (get_pixel_from_text(&all->s, coord, y));
	if (side == 4)
		return (get_pixel_from_text(&all->n, coord, y));
	return (0);
}

float			get_tex_coord(float x, float y, t_all *all)
{
	float	ox;
	float	oy;
	float	dx;
	float	dy;
	float	coord;

	ox = (int)(x / 64) * 64 + 32;
	oy = (int)(y / 64) * 64 + 32;
	dx = (x - ox) / 32;
	dy = (y - oy) / 32;
	if (fabs(dx) > fabs(dy))
		coord = (dy + 1) / 2;
	else
		coord = (dx + 1) / 2;
	if (coord < 0)
		coord = 0;
	if (coord > 1)
		coord = 1;
	return (coord);
}

int				get_side(float x, float y, float start)
{
	if ((int)((x - cos(start)) / 64) == (int)(x / 64))
	{
		if ((int)((y - sin(start)) / 64) < (int)(y / 64))
			return (1);
		else
			return (4);
	}
	else if ((int)((y - sin(start)) / 64) == (int)(y / 64))
	{
		if ((int)((x - cos(start)) / 64) < (int)(x / 64))
			return (2);
		else
			return (3);
	}
	return (0);
}
