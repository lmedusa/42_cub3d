/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:36:19 by lmedusa           #+#    #+#             */
/*   Updated: 2020/09/17 15:36:21 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		wall_check(t_all *all, float x, float y)
{
	int		ix;
	int		iy;

	ix = (int)(x / 64);
	iy = (int)(y / 64);
	if (!all->map[iy][ix])
		return (1);
	if (all->map[iy][ix] == '0' || all->map[iy][ix] == '2')
		return (0);
	return (1);
}

void	plr_util(t_all *all)
{
	float	x;
	float	y;
	float	side;
	double	step;

	side = 0;
	step = 16;
	if (all->plr.side == TRUE)
		side = M_PI / 2 * all->plr.w_dir;
	if (all->plr.side && all->plr.w_dir == -1)
		step = -16;
	all->plr.pov += all->plr.dir * 0.2;
	x = all->plr.x;
	y = all->plr.y;
	x += all->plr.w_dir * cosf(all->plr.pov - side) * step;
	y += all->plr.w_dir * sinf(all->plr.pov - side) * step;
	if (wall_check(all, x, y) == 0)
	{
		all->plr.x += all->plr.w_dir * cosf(all->plr.pov - side) * step;
		all->plr.y += all->plr.w_dir * sinf(all->plr.pov - side) * step;
	}
}

void	start_game(t_all *all)
{
	all->img.wdh = all->win.w;
	all->img.hgt = all->win.h;
	if (!(all->rays = malloc(sizeof(t_rayutil) * all->img.wdh)))
		ft_exit("Bad malloc.", all);
	if (!(all->win.mlx = mlx_init()))
		ft_exit("Error mlx_init.", all);
	create_imges(&all->win, all);
	create_text(all->path_n, &all->n, all);
	create_text(all->path_s, &all->s, all);
	create_text(all->path_w, &all->w, all);
	create_text(all->path_e, &all->e, all);
	create_text(all->sprite_path, &all->sprite, all);
	render(all);
	if (all->bmp == TRUE)
	{
		make_screenshot(all);
		ft_exit("Screenshot saved.", all);
	}
	if (!(all->win.win = mlx_new_window(all->win.mlx, \
	all->win.w, all->win.h, "CUB3D")))
		ft_exit("Error window.", all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.img, 0, 0);
}

void	valid_args(int argc, t_all *all, char **argv)
{
	int		i;

	if (argc == 1 || argc > 3)
		ft_pre_exit("Invalid arguments number.");
	if (argc == 2)
	{
		i = ft_strlen(argv[1]);
		if (i < 5 || ft_memcmp(&argv[1][i - 4], ".cub", 4))
			ft_pre_exit("Invalid map file.");
	}
	if (argc == 3)
	{
		if (!ft_memcmp(argv[2], "--save", ft_strlen(argv[2])))
			all->bmp = TRUE;
		else
			ft_pre_exit("Invalid screenshot command. Try --save.");
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_list	*head;
	t_all	all;

	all.bmp = FALSE;
	line = NULL;
	head = NULL;
	valid_args(argc, &all, argv);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_pre_exit("Error while opening map file.");
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	init_all(&all);
	ft_map(&head, &all, ft_lstsize(head));
	parse_map(&all, all.mp);
	validate_map(&all, all.map);
	sprites(&all);
	start_game(&all);
	mlx_hook(all.win.win, 17, (1L << 5), close_cub, &all);
	mlx_hook(all.win.win, 2, 0, key_pressed, &all);
	mlx_hook(all.win.win, 3, 0, key_released, &all);
	mlx_loop(all.win.mlx);
	return (0);
}
