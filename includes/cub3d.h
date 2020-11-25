/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:02:54 by lmedusa           #+#    #+#             */
/*   Updated: 2020/11/25 16:02:57 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define FOV M_PI / 3
# define BUFFER_SIZE 32
# define LEFT	123
# define RIGHT	124
# define W		13
# define D		2
# define S		1
# define A		0

# define FALSE 0
# define TRUE 1

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;
}					t_win;

typedef	struct		s_map
{
	int				flg;
	int				i;
	int				j;
	int				x;
	int				y;
}					t_map;

typedef struct		s_render
{
	float			col;
	float			point;
	float			tmp;
	float			zy;
	float			col_true;
	unsigned int	color;
}					t_render;

typedef struct		s_ray
{
	float			len;
	float			x;
	float			y;
	float			step;
}					t_ray;

typedef struct		s_rayutil
{
	float			len;
}					t_rayutil;

typedef struct		s_plr
{
	float			x;
	float			y;
	float			pov;
	float			dir;
	int				side;
	float			w_dir;
	float			start;
	float			end;
}					t_plr;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				wdh;
	int				hgt;
	int				bpp;
	int				len;
	int				endian;
}					t_img;

typedef	struct		s_spr
{
	int				i;
	int				j;
	float			y;
	float			x;
	unsigned int	*col;
	float			h;
	float			v;
	float			dir;
	float			dist;
	float			size;
	float			tex;
	float			offset;
}					t_spr;

typedef struct		s_maputil
{
	int				flg_r;
	int				flg_no;
	int				flg_so;
	int				flg_we;
	int				flg_ea;
	int				flg_s;
	int				flg_c;
	int				flg_f;
	int				len;
}					t_maputil;

typedef	struct		s_text
{
	t_img			img;
}					t_text;

typedef struct		s_all
{
	t_map			mp;
	t_win			win;
	t_img			img;
	t_plr			plr;
	t_ray			ray;
	t_text			n;
	t_text			s;
	t_text			w;
	t_text			e;
	t_text			sprite;
	t_spr			*spr_util;
	t_rayutil		*rays;
	unsigned int	tmp_color;
	unsigned int	floor;
	unsigned int	cell;
	int				map_v;
	int				map_h;
	int				bmp;
	int				spr_count;
	char			*sprite_path;
	char			*path_n;
	char			*path_s;
	char			*path_e;
	char			*path_w;
	char			**map;
	char			**map_buff;
	float			text_coord;
}					t_all;

typedef	struct		s_gnl
{
	char			*s;
	char			*t;
	int				i;
	int				r;
}					t_gnl;

int					check_plr(t_all *all, char m, int x, int y);
void				check_flags(t_maputil *f, t_all *all);
void				parse_config(t_list *tmp, t_all *all, t_maputil *map);
void				parse_str(char *str, t_all *all);
int					ft_check_line(void *s);
int					ft_is_valid(char c, char *valid);
int					close_cub(t_all *all);
int					ft_isdigit(int dig);
void				ft_clear(int i, char **mas);
void				ft_pre_exit(char *error);
void				ft_exit(char *error, t_all *all);
void				ft_texture(char *str, t_all *all, int flag, t_maputil *m);
char				*ft_strnstr(const char *big, const char *small, size_t len);
void				ft_strdel(char **s);
char				*ft_strnew(size_t size);
void				*ft_memset(void *src, int c, size_t len);
void				validate_map(t_all *all, char **m);
void				plr_util(t_all *all);
int					key_released(int kcode, t_all *all);
int					key_pressed(int kcode, t_all *all);
int					get_side(float x, float y, float start);
float				get_tex_coord(float x, float y, t_all *all);
unsigned int		get_texture(t_all *all, int side, float coord, float y);
unsigned int		get_pixel_from_text(t_text *text, float x, float y);
void				create_imges(t_win *screen, t_all *all);
void				create_text(char *path, t_text *text, t_all *all);
void				init_texture(t_all *all, int flag, \
					char *path, t_maputil *map);
void				init_all(t_all *all);
void				sprites(t_all *all);
void				render_spr(t_all *all);
void				sprite_sort(t_all *all);
void				spr_parse(t_all *all);
int					make_screenshot(t_all *all);
void				screen(t_all *all, int fd, int wdh);
void				init_header(unsigned char *header, \
					int size, t_all *all, int wdh);
int					get_screenshot_color(t_all *all, int x, int y);
void				render(t_all *all);
void				draw_sprite(t_all *all, t_spr s);
void				render_wall(int side, float x, float len, t_all *all);
void				raycast(t_all *all);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
void				background(int x, int y, t_all *all, unsigned int color);
void				make_map(t_all *all, int flag, int size);
void				parse_map(t_all *all, t_map mp);
int					ft_memcmp(const void *src, const void *src2, size_t n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				*ft_calloc(size_t num, size_t size);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
int					get_next_line(int fd, char **line);
int					proc_gnl(int fd, char **doc, char **line);
char				*ft_new(size_t size);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_bzero(void *str, size_t len);
size_t				ft_strlen(char const *str);
void				ft_map(t_list **head, t_all *all, int size);
int					ft_atoi(const char *str);
unsigned int		get_color(int r, int g, int b);
void				validate_color(char *str, t_all *all);
void				resolution(char *str, t_all *all, t_maputil *map);
void				rgb_to_hex(char *str, t_all *all, int flag, t_maputil *map);
void				ft_putendl(char *s);

#endif
