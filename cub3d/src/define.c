/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 01:57:32 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 01:57:32 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	define_dist_ver(t_all *list)
{
	float		num;
	int			flg;

	num = 0.0;
	flg = 0;
	while (flg == 0)
	{
		claculate_ver_ray(list, num);
		num++;
		if (list->ray.ver_i <= list->set.y_max && list->ray.ver_i >= 0.0 && \
		list->ray.ver_j < (int)ft_strlen(list->set.map[list->ray.ver_i]) \
		&& list->ray.ver_j >= 0.0)
		{
			if (list->set.map[list->ray.ver_i][list->ray.ver_j] == '1')
				flg = 1;
		}
		else
			return (INFINITY);
	}
	return (fabs((list->plr.y - list->ray.ver_y) / sin(list->ray.angl)));
}

float	define_dist_hor(t_all *list)
{
	float		num;
	int			flg;

	num = 0.0;
	flg = 0;
	while (flg == 0)
	{
		claculate_hor_ray(list, num);
		num++;
		if (list->ray.hor_i >= 0.0 && list->ray.hor_i <= list->set.y_max && \
		list->ray.hor_j >= 0.0 && \
		list->ray.hor_j < (int)ft_strlen(list->set.map[list->ray.hor_i]))
		{	
			if (list->set.map[list->ray.hor_i][list->ray.hor_j] == '1')
				flg = 1;
		}
		else
			return (INFINITY);
	}
	return (fabs((list->plr.y - list->ray.hor_y) / sin(list->ray.angl)));
}
