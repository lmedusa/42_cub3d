/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:31:04 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/23 18:31:05 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			create_imges(t_win *screen, t_all *all)
{
	t_img		*img;

	img = &(all->img);
	if (!(img->img = mlx_new_image(screen->mlx, all->img.wdh, all->img.hgt)))
		ft_exit("Error while creating IMAGE.", all);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
	if (!img->addr)
		ft_exit("Error while get image adddddddddr.", all);
}

void			init_ptr(t_all *all)
{
	all->plr.side = FALSE;
	all->spr_count = 0;
	all->floor = -1;
	all->cell = -1;
	all->n.img.img = NULL;
	all->s.img.img = NULL;
	all->w.img.img = NULL;
	all->e.img.img = NULL;
	all->sprite.img.img = NULL;
	all->win.mlx = NULL;
	all->win.win = NULL;
	all->img.img = NULL;
	all->map = NULL;
	all->map_buff = NULL;
	all->spr_util = NULL;
	all->rays = NULL;
}

void			init_all(t_all *all)
{
	all->floor = -1;
	all->cell = -1;
	all->map_v = 0;
	all->map_h = 0;
	all->mp.i = 0;
	all->mp.x = 0;
	all->mp.y = 0;
	all->mp.flg = 0;
	all->ray.step = 0.5;
	all->plr.pov = -1;
	all->img.wdh = -1;
	all->img.hgt = -1;
	all->win.h = -1;
	all->win.w = -1;
	all->plr.x = 0;
	all->plr.y = 0;
	all->plr.w_dir = 0;
	all->plr.dir = 0;
	all->ray.x = 0;
	all->ray.y = 0;
	all->ray.len = 0;
	all->tmp_color = 0;
	init_ptr(all);
}
