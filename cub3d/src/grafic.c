/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 01:38:05 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 01:38:05 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_sprite(t_all *list, int n)
{
	float			cor_x;
	float			cor_y;
	float			dst_w;

	cor_x = ft_flt_max(0, list->spr[n].spr_x - list->spr[n].spr_w / 2);
	while (cor_x < ft_flt_min(list->spr[n].spr_x + list->spr[n].spr_w / 2, \
	list->set.re_width))
	{
		cor_y = ft_flt_max(0, list->spr[n].spr_y - list->spr[n].spr_h / 2);
		while (cor_y < ft_flt_min(list->spr[n].spr_y + list->spr[n].spr_h / 2, \
		list->set.re_height))
		{
			list->ray.angl = cor_x / list->set.re_width * (-1) * (M_PI / 3) + \
			list->plr.dir + (M_PI / 3) / 2.0;
			dst_w = define_dist(list) * cos(list->ray.angl - list->plr.dir);
			if (list->spr[n].dst < dst_w)
				my_spr_pixel_put(list, cor_x, cor_y, n);
			cor_y++;
		}
		cor_x++;
	}
}

void	make_spr(t_all *list)
{
	int				num;
	float			tmp_raya;

	num = 0;
	tmp_raya = list->ray.angl;
	order_spr(list);
	while (list->spr[num].cor_y != -1 || list->spr[num].cor_x != -1)
	{
		spr_placement(list, list->spr[num].cor_y, list->spr[num].cor_x, num);
		if (list->spr[num].spr_x + list->spr[num].spr_w / 2 >= 0 && \
		list->spr[num].spr_x - list->spr[num].spr_w / 2 < list->set.re_width)
			draw_sprite(list, num);
		num++;
	}
	list->ray.angl = tmp_raya;
}

void	choose_dir(t_all *list, float w, float h)
{
	if (list->ray.flg_hor)
	{
		if (list->ray.qrt == 1 || list->ray.qrt == 2)
			draw_my_pxl(list, &list->so, w, h);
		else
			draw_my_pxl(list, &list->no, w, h);
	}
	else
	{
		if (list->ray.qrt == 1 || list->ray.qrt == 4)
			draw_my_pxl(list, &list->we, w, h);
		else
			draw_my_pxl(list, &list->ea, w, h);
	}			
}

static void	my_flr_ceil_put(t_all *list)
{
	float			cor_x;
	float			cor_y;

	cor_x = 0.0;
	while (list->set.re_width > cor_x)
	{
		cor_y = 0.0;
		while ((list->set.re_height / 2.0) > cor_y)
		{
			my_mlx_pixel_put(&list->img, cor_x, cor_y, list->set.ce_color);
			cor_y++;
		}
		while (list->set.re_height > cor_y)
		{
			my_mlx_pixel_put(&list->img, cor_x, cor_y, list->set.fl_color);
			cor_y++;
		}
		cor_x++;
	}
}

void	draw_map_block(t_all *list)
{
	float			cor_x;
	float			cor_y;

	cor_x = 0.0;
	my_flr_ceil_put(list);
	while (list->set.re_width > cor_x)
	{
		list->ray.angl = cor_x / list->set.re_width * (M_PI / 3) * (-1) + \
		list->plr.dir + (M_PI / 3) / 2.0;
		check_wall_hght(list);
		cor_y = ft_flt_max(list->ray.strt_h, 0.0);
		while (ft_flt_min(list->ray.end_h, list->set.re_height) > cor_y)
		{
			choose_dir(list, cor_x, cor_y);
			cor_y++;
		}
		cor_x++;
	}
}
