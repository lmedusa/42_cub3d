/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:31:24 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/25 14:31:26 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			create_text(char *path, t_text *text, t_all *all)
{
	text->img.img = mlx_xpm_file_to_image(all->win.mlx, path, \
	&(text->img.wdh), &(text->img.hgt));
	if (text->img.img == NULL)
		ft_exit("Error\n Invalid texture.", all);
	text->img.addr = mlx_get_data_addr(text->img.img, \
	&text->img.bpp, &text->img.len, &text->img.endian);
	if (text->img.addr == NULL)
		ft_exit("Invalid texture.", all);
}

void			init_texture(t_all *all, int flag, char *path, t_maputil *map)
{
	if (flag == 1)
	{
		map->flg_no += 1;
		all->path_n = path;
	}
	if (flag == 2)
	{
		map->flg_so += 1;
		all->path_s = path;
	}
	if (flag == 3)
	{
		map->flg_we += 1;
		all->path_w = path;
	}
	if (flag == 4)
	{
		map->flg_ea += 1;
		all->path_e = path;
	}
	if (flag == 5)
	{
		map->flg_s += 1;
		all->sprite_path = path;
	}
}

void			valid_text(t_all *all, char *str)
{
	int		i;

	i = ft_strlen(str);
	if (i < 5 || ft_memcmp(&str[i - 4], ".xpm", 4) != 0)
		ft_exit("Invalid texture file.", all);
}

void			ft_texture(char *str, t_all *all, int flag, t_maputil *m)
{
	while (*str && *str == ' ')
		str++;
	str = str + 2;
	while (*str && *str == ' ')
		str++;
	valid_text(all, str);
	init_texture(all, flag, str, m);
}
