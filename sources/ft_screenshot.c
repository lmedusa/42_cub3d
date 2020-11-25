/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:34:05 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/23 18:34:07 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			get_screenshot_color(t_all *all, int x, int y)
{
	char	*dst;

	dst = all->img.addr + (y * all->img.len + x * (all->img.bpp / 8));
	return (*(unsigned int*)dst);
}

void		init_header(unsigned char *header, int size, t_all *all, int wdh)
{
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	header[2] = (unsigned char)size;
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	header[18] = (unsigned char)wdh;
	header[19] = (unsigned char)(wdh >> 8);
	header[20] = (unsigned char)(wdh >> 16);
	header[21] = (unsigned char)(wdh >> 24);
	header[22] = (unsigned char)all->img.hgt;
	header[23] = (unsigned char)(all->img.hgt >> 8);
	header[24] = (unsigned char)(all->img.hgt >> 16);
	header[25] = (unsigned char)(all->img.hgt >> 24);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
}

void		screen(t_all *all, int fd, int wdh)
{
	int		color;
	int		x;
	int		y;
	int		dx;

	color = 0;
	x = 0;
	y = all->img.hgt - 1;
	dx = wdh;
	while (y >= 0)
	{
		while (x < dx)
		{
			color = get_screenshot_color(all, x, y);
			write(fd, &color, 3);
			x++;
		}
		y--;
		x = 0;
	}
}

int			make_screenshot(t_all *all)
{
	int				fd;
	unsigned char	header[54];
	int				i;
	int				size;
	int				temp_w;

	temp_w = all->img.wdh;
	if (all->img.wdh % 4)
		temp_w = all->img.wdh - (all->img.wdh % 4);
	size = temp_w * all->img.wdh + 54;
	i = 0;
	if ((fd = open("./screenshot.bmp", O_RDWR | O_CREAT, 0666)) < 0)
		return (-1);
	while (i < 54)
	{
		header[i] = (unsigned char)0;
		i++;
	}
	init_header(header, size, all, temp_w);
	write(fd, header, 54);
	screen(all, fd, temp_w);
	close(fd);
	return (1);
}
