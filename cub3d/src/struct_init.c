/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:04:37 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 14:09:10 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_texture(t_texture *texture)
{
	texture->img = NULL;
	texture->addr = NULL;
}

void	texture_init(t_all *list)
{
	t_texture		no;
	t_texture		we;
	t_texture		ea;	
	t_texture		so;
	t_texture		sp;

	ft_init_texture(&no);
	ft_init_texture(&we);
	ft_init_texture(&ea);
	ft_init_texture(&so);
	ft_init_texture(&sp);
	list->no = no;
	list->we = we;
	list->ea = ea;
	list->so = so;
	list->sp = sp;
	list->set.x_max = 0;
	list->set.y_max = 0;
	list->set.set_flgs = 0b00000000;
	list->set.mp_flg = 0;
}

void	struct_init(t_all *list, char *sceen)
{
	t_mlx		mlx;
	t_ss		set;
	t_texture	img;
	t_player	plr;
	t_ray		ray;

	set.fd = open(sceen, O_RDONLY);
	if (set.fd == -1)
		ft_error_pr("Couldn't open file");
	mlx_get_screen_size(&set.re_width, &set.re_height);
	mlx.win = NULL;
	set.map = NULL;
	set.mapl = NULL;
	set.gnl_temp = NULL;
	ft_init_texture(&img);
	plr.flg_plr = 0;
	ray.qrt = 0;
	list->mlx = mlx;
	list->set = set;
	list->img = img;
	list->plr = plr;
	list->ray = ray;
	texture_init(list);
	list->mlx.mlx = mlx_init();
}

void	struct_init_map(t_all *list)
{
	list->set.map = ft_split(list->set.mapl, '|');
	if (!list->set.map)
		ft_error_pr ("Malloc problem with map");
	list->set.y_max--;
	list->set.x_max--;
	if (list->set.mapl != NULL)
		free(list->set.mapl);
	list->set.mapl = NULL;
}

void	struct_init_spr(t_all *list)
{
	list->spr = malloc(sizeof(t_spr) * (list->set.spr_num + 1));
	if (!list->spr)
		ft_error_pr ("Malloc problem with sprite");
	list->spr[list->set.spr_num].cor_y = -1;
	list->spr[list->set.spr_num].cor_x = -1;
}
