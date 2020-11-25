/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:33:04 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/23 18:33:06 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_pressed(int kcode, t_all *all)
{
	if (kcode == 53)
		ft_exit("Exit game.", all);
	if (kcode == W)
		all->plr.w_dir = 1;
	else if (kcode == S)
		all->plr.w_dir = -1;
	else if (kcode == D)
	{
		all->plr.w_dir = -1;
		all->plr.side = TRUE;
	}
	else if (kcode == A)
	{
		all->plr.w_dir = 1;
		all->plr.side = TRUE;
	}
	else if (kcode == RIGHT)
		all->plr.dir = 1;
	else if (kcode == LEFT)
		all->plr.dir = -1;
	render(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.img, 0, 0);
	return (1);
}

int		key_released(int kcode, t_all *all)
{
	if (kcode == W)
		all->plr.w_dir = 0;
	else if (kcode == S)
		all->plr.w_dir = 0;
	else if (kcode == D)
	{
		all->plr.w_dir = 0;
		all->plr.side = FALSE;
	}
	else if (kcode == A)
	{
		all->plr.w_dir = 0;
		all->plr.side = FALSE;
	}
	else if (kcode == RIGHT)
		all->plr.dir = 0;
	else if (kcode == LEFT)
		all->plr.dir = 0;
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.img, 0, 0);
	return (1);
}
