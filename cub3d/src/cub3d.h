/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 11:59:17 by blucimor          #+#    #+#             */
/*   Updated: 2021/04/25 11:59:17 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx_opengl/mlx.h"

# define FLG_RE 0b00000001
# define FLG_NO 0b00000010
# define FLG_SO 0b00000100
# define FLG_WE 0b00001000
# define FLG_EA 0b00010000
# define FLG_SP 0b00100000
# define FLG_FL 0b01000000
# define FLG_CE 0b10000000
# define FLG_AL 0b11111111

# define FLG_BMP 0b00000001

# define COF_H 1.11
# define MOVE_DST 15.00
# define BLOCK 50.00
# define ANGT 0.20
# define BUFF_BMP 54

typedef struct s_struct_texture {
	int				endian;
	int				img_x;
	int				img_y;
	int				flg;
	int				bits_per_pixel;
	int				line_length;
	void			*img;
	char			*addr;
}				t_texture;

typedef struct s_struct_mlx {
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_scene_setting
{
	int				re_width;
	int				re_height;
	int				mp_flg;
	int				x_max;
	int				y_max;
	int				spr_num;
	int				fd;
	char			**map;
	char			*mapl;
	char			*gnl_temp;
	unsigned int	fl_color;
	unsigned int	ce_color;
	unsigned char	set_flgs;
}				t_ss;

typedef struct s_struct_sprite
{
	int				cor_y;
	int				cor_x;
	float			x;
	float			y;
	float			h;
	float			w;
	float			spr_x;
	float			spr_y;
	float			spr_w;
	float			spr_h;
	float			dir;
	float			dst;
}				t_spr;

typedef struct s_struct_ray
{
	int				qrt;
	int				ver_i;
	int				ver_j;
	int				hor_i;
	int				hor_j;
	int				flg_hor;
	float			angl;
	float			ver_x;
	float			ver_y;
	float			hor_x;
	float			hor_y;
	float			hght;
	float			strt_h;
	float			end_h;
	float			prt;
}				t_ray;

typedef struct s_struct_player
{
	int				cor_y;
	int				cor_x;
	float			x;
	float			y;
	float			dir;
	int				flg_plr;
}				t_player;

typedef struct s_struct_all
{	
	t_ss			set;
	t_spr			*spr;
	t_player		plr;
	t_ray			ray;
	t_texture		img;
	t_texture		no;
	t_texture		so;
	t_texture		we;
	t_texture		ea;
	t_texture		sp;
	t_mlx			mlx;
	int				com_flg;
}				t_all;

void			ft_error_pr(char *str);
int				ft_close(t_all *list);
int				keys_hook(int keycode, t_all *list);
int				draw_my_window(t_all *list);
void			struct_intit_mlx(t_all *list);
void			texture_init(t_all *list);
void			struct_init(t_all *list, char *sceen);
void			struct_init_map(t_all *list);
void			struct_init_spr(t_all *list);
void			ft_rgb_convertor(char *rgb, unsigned int *hex);
void			ft_clean_leaks(t_all *list);
void			parser_settings(t_all *list);
void			parser_colors(t_all *list, char **arr);
void			parser_map(t_all *list);
void			parser_resolution(t_all *list, char **arr);
void			parse_texture_path(t_all *list, char **arr);
void			parse_dir_texture(t_all *list, char **arr);
void			mlx_xpm_to_texture(t_all *list, t_texture *img, char *path);
void			my_mlx_pixel_put(t_texture *img, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_texture *img, int x, int y);
void			spr_placement(t_all *list, int cor_y, int cor_x, int num);
void			find_spr_size(t_all *list, int num);
void			find_spr_dir(t_all *list, int num);
void			find_spr_center(t_spr *sprite, int cor_y, int cor_x, int num);
void			draw_map_block(t_all *list);
void			draw_my_pxl(t_all *list, t_texture *t, float w, float h);
void			make_spr(t_all *list);
void			my_spr_pixel_put(t_all *list, float w, float h, int n);
void			order_spr(t_all *list);
float			define_dist(t_all *list);
void			check_wall_hght(t_all *list);
float			define_hght(t_all *list);
void			check_prt(t_all *list);
void			check_qrtr(t_all *list);
float			define_coff_j(float ray);
float			define_coff_i(float ray);
void			claculate_ver_ray(t_all *list, float num);
void			claculate_hor_ray(t_all *list, float num);
float			define_dist_ver(t_all *list);
float			define_dist_hor(t_all *list);
void			ft_make_screen(t_all *list);
void			find_plr(t_all *list, int x, char dir);
void			join_mapls(t_all *list, char *str);

#endif
