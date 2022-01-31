/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 01:55:18 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 01:55:18 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	claculate_ver_ray(t_all *list, float num)
{
	list->ray.ver_y = list->plr.y + (num) * (BLOCK * fabs(tan(list->ray.angl))) \
	* define_coff_i(list->ray.angl) + define_coff_i(list->ray.angl) * (BLOCK * \
	(define_coff_j(list->ray.angl) + 1.0) / 2.0 - define_coff_j(list->ray.angl) \
	* (list->plr.x - BLOCK * list->plr.cor_x)) * fabs(tan(list->ray.angl));
	list->ray.ver_i = floor(list->ray.ver_y / BLOCK);
	list->ray.ver_j = define_coff_j(list->ray.angl) * (num + 1.0) + \
	list->plr.cor_x;
	list->ray.ver_x = (list->ray.ver_j + (1.0 - define_coff_j(list->ray.angl)) \
	/ 2.0) * BLOCK;
}

float	define_coff_i(float ray)
{
	if (ray >= M_PI)
		return (1.0);
	return (-1.0);
}

float	define_coff_j(float ray)
{
	if (ray < 3.0 * M_PI / 2.0 && ray >= M_PI / 2.0)
		return (-1.0);
	return (1.0);
}

void	draw_my_pxl(t_all *list, t_texture *t, float w, float h)
{
	float			img_w;
	float			img_h;
	unsigned int	pix;

	img_w = list->ray.prt * t->img_x;
	img_h = (h - list->ray.strt_h) / list->ray.hght * t->img_y;
	pix = my_mlx_pixel_get(t, img_w, img_h);
	my_mlx_pixel_put(&list->img, w, h, pix);
}

void	my_spr_pixel_put(t_all *list, float w, float h, int n)
{
	float			tx_y;
	float			tx_x;
	float			prt_x;
	float			prt_y;
	unsigned int	pix;

	prt_x = (w - (list->spr[n].spr_x - (list->spr[n].spr_w / 2))) \
	/ list->spr[n].spr_w;
	prt_y = (h - (list->spr[n].spr_y - (list->spr[n].spr_h / 2))) \
	/ list->spr[n].spr_h;
	tx_x = floor(prt_x * list->sp.img_x);
	tx_y = floor(prt_y * list->sp.img_y);
	pix = my_mlx_pixel_get(&list->sp, tx_x, tx_y);
	if (pix != 0x00FFFFFF)
		my_mlx_pixel_put(&list->img, w, h, pix);
}
