/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:12:14 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/25 16:12:17 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	get_color(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

void			my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= img->wdh || y >= img->hgt)
		return ;
	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void			background(int x, int y, t_all *all, unsigned int color)
{
	int		i;
	int		j;
	int		width;
	int		height;

	i = x;
	width = all->img.wdh;
	height = all->img.hgt / 2;
	while (i < x + width)
	{
		j = y;
		while (j < y + height)
		{
			my_mlx_pixel_put(&all->img, i, j, color);
			j++;
		}
		i++;
	}
}
