/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 01:47:24 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 01:47:24 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	define_dist(t_all *list)
{
	float		v_dst;
	float		h_dst;

	if (list->ray.angl >= 2 * M_PI)
		list->ray.angl = list->ray.angl - (2 * M_PI);
	if (list->ray.angl < 0)
		list->ray.angl = list->ray.angl + (2 * M_PI);
	check_qrtr(list);
	v_dst = define_dist_ver(list);
	h_dst = define_dist_hor(list);
	if (h_dst > v_dst)
		list->ray.flg_hor = 0;
	else
		list->ray.flg_hor = 1;
	check_prt(list);
	if (h_dst > v_dst)
		return (v_dst);
	else
		return (h_dst);
}

void	check_wall_hght(t_all *list)
{
	list->ray.hght = define_hght(list);
	list->ray.strt_h = (list->set.re_height - list->ray.hght) / 2.0;
	list->ray.end_h = (list->set.re_height + list->ray.hght) / 2.0;
}

float	define_hght(t_all *list)
{
	float		hght;
	float		dst;

	dst = cos(list->ray.angl - list->plr.dir) * define_dist(list);
	hght = list->set.re_height * BLOCK * COF_H / dst;
	return (hght);
}

void	check_prt(t_all *list)
{
	if (list->ray.flg_hor)
	{
		if (list->ray.qrt == 2 || list->ray.qrt == 1)
			list->ray.prt = list->ray.hor_x - BLOCK * list->ray.hor_j;
		else
			list->ray.prt = BLOCK * (list->ray.hor_j + 1) - list->ray.hor_x;
	}
	else
	{
		if (list->ray.qrt == 4 || list->ray.qrt == 1)
			list->ray.prt = list->ray.ver_y - BLOCK * list->ray.ver_i;
		else
			list->ray.prt = BLOCK * (list->ray.ver_i + 1) - list->ray.ver_y;
	}
	list->ray.prt = list->ray.prt / BLOCK;
}

void	check_qrtr(t_all *list)
{
	if (list->ray.angl < M_PI / 2.0 && list->ray.angl >= 0.0)
		list->ray.qrt = 1;
	else if (list->ray.angl >= M_PI / 2.0 && list->ray.angl < M_PI)
		list->ray.qrt = 2;
	else if (list->ray.angl < 1.5 * M_PI && list->ray.angl >= M_PI)
		list->ray.qrt = 3;
	else
		list->ray.qrt = 4;
}
