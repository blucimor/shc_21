/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_spr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 00:36:46 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 00:36:46 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	order_spr(t_all *list)
{
	t_spr			tmp;
	int				cor_y;
	int				cor_x;

	cor_y = 0;
	while (cor_y < list->set.spr_num - 1 && list->spr[cor_y].cor_y != -1)
	{
		cor_x = cor_y + 1;
		while (cor_x < list->set.spr_num)
		{
			if (list->spr[cor_y].dst < list->spr[cor_x].dst)
			{
				tmp = list->spr[cor_y];
				list->spr[cor_y] = list->spr[cor_x];
				list->spr[cor_x] = tmp;
			}
			cor_x++;
		}
		cor_y++;
	}
}

void	find_spr_center(t_spr *sprite, int cor_y, int cor_x, int num)
{
	sprite[num].cor_y = cor_y;
	sprite[num].cor_x = cor_x;
	sprite[num].x = (cor_x + 0.5) * BLOCK;
	sprite[num].y = (cor_y + 0.5) * BLOCK;
}

void	find_spr_dir(t_all *list, int num)
{
	list->spr[num].dst = pow(pow(list->plr.x - list->spr[num].x, 2) + \
	pow(list->plr.y - list->spr[num].y, 2), 0.5);
	list->spr[num].dir = (-1) * atan2(list->spr[num].y - list->plr.y, \
	list->spr[num].x - list->plr.x) - list->plr.dir;
	if (list->spr[num].dir < -M_PI)
		list->spr[num].dir = list->spr[num].dir + (2 * M_PI);
	else if (list->spr[num].dir >= 2 * M_PI)
		list->spr[num].dir = list->spr[num].dir - (2 * M_PI);
}

void	find_spr_size(t_all *list, int num)
{
	list->spr[num].spr_x = list->set.re_width / 2 - list->set.re_width * \
	list->spr[num].dir / (M_PI / 3);
	list->spr[num].w = list->sp.img_x;
	list->spr[num].h = list->sp.img_y;
	list->spr[num].spr_w = list->spr[num].w * ((list->set.re_height * BLOCK * \
	0.00985) / list->spr[num].dst);
	list->spr[num].spr_h = list->spr[num].h * ((list->set.re_height * \
	BLOCK * 0.00985) / list->spr[num].dst);
	list->spr[num].spr_y = list->set.re_height / 2 + 1.5 * list->spr[num].spr_h;
}
