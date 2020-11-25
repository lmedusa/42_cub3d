/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:32:13 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/24 21:32:15 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		close_cub(t_all *all)
{
	ft_exit("Exit cub.", all);
	return (0);
}

void	close_gl(t_all *all)
{
	if (all->win.win)
		mlx_destroy_window(all->win.mlx, all->win.win);
	if (all->s.img.img)
		mlx_destroy_image(all->win.mlx, all->s.img.img);
	if (all->w.img.img)
		mlx_destroy_image(all->win.mlx, all->w.img.img);
	if (all->n.img.img)
		mlx_destroy_image(all->win.mlx, all->n.img.img);
	if (all->e.img.img)
		mlx_destroy_image(all->win.mlx, all->e.img.img);
	if (all->sprite.img.img)
		mlx_destroy_image(all->win.mlx, all->sprite.img.img);
	if (all->img.img)
		mlx_destroy_image(all->win.mlx, all->img.img);
	if (all->win.mlx)
		free(all->win.mlx);
}

void	free_all(t_all *all)
{
	if (all->map_buff)
		ft_clear(all->map_v, all->map_buff);
	if (all->rays)
		free(all->rays);
	if (all->spr_util)
		free(all->spr_util);
	if (all->map_buff)
		free(all->map_buff);
	if (all->map_buff)
		free(all->map);
}

void	ft_pre_exit(char *error)
{
	ft_putendl(error);
	exit(0);
}

void	ft_exit(char *error, t_all *all)
{
	if (ft_memcmp(error, "1", 1) == 0)
	{
		ft_putendl("Invalid command for screenshot, try --save.");
		exit(0);
	}
	ft_putendl(error);
	close_gl(all);
	free_all(all);
	exit(0);
}
