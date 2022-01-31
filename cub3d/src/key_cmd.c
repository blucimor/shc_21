/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:53:30 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 13:46:29 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_all *list)
{
	ft_clean_leaks(list);
	if ((close(list->set.fd) == -1))
		ft_error_pr ("Couldn't close");
	exit(0);
}

static void	ft_move(t_all *list, int num, int nmb, float angl)
{
	float		x;
	float		y;

	x = list->plr.x + MOVE_DST * cos(list->plr.dir + angl * nmb) * num;
	y = list->plr.y + -MOVE_DST * sin(list->plr.dir + angl * nmb) * num;
	list->plr.y = y;
	list->plr.x = x;
}

int	keys_hook(int keycode, t_all *list)
{
	if (keycode == 53)
		ft_close(list);
	else if (keycode == 13)
		ft_move(list, 1, 1, 0.0);
	else if (keycode == 1)
		ft_move(list, -1, -1, 0.0);
	else if (keycode == 0)
		ft_move(list, 1, 1, M_PI / 2);
	else if (keycode == 2)
		ft_move(list, 1, -1, M_PI / 2);
	else if (keycode == 123)
	{
		list->plr.dir += ANGT;
		if (list->plr.dir >= 2 * M_PI)
			list->plr.dir -= 2 * M_PI;
	}
	else if (keycode == 124)
	{
		list->plr.dir -= ANGT;
		if (list->plr.dir < 0)
			list->plr.dir += 2 * M_PI;
	}
	list->plr.cor_y = list->plr.y / BLOCK;
	list->plr.cor_x = list->plr.x / BLOCK;
	return (0);
}
