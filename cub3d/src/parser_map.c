/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:48:20 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 13:56:49 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_plr(t_all *list, int x, char dir)
{
	list->plr.cor_x = x;
	list->plr.cor_y = list->set.y_max;
	list->plr.x = BLOCK * list->plr.cor_x + BLOCK / 2;
	list->plr.y = BLOCK * list->plr.cor_y + BLOCK / 2;
	if (dir == 'E')
		list->plr.dir = 0;
	else if (dir == 'W')
		list->plr.dir = M_PI;
	else if (dir == 'N')
		list->plr.dir = M_PI / 2;
	else if (dir == 'S')
		list->plr.dir = M_PI * 3 / 2;
	list->plr.dir += 0.00099;
}

void	spr_placement(t_all *list, int cor_y, int cor_x, int num)
{
	find_spr_center(list->spr, cor_y, cor_x, num);
	find_spr_dir(list, num);
	find_spr_size(list, num);
}

static void	validation_map(t_all *list, int y, int x, int y_len)
{
	if (y == 0 || y == list->set.y_max || x == 0 || x == (y_len - 1))
		ft_error_pr ("Invalid map");
	if ((int)ft_strlen(list->set.map[y + 1]) <= x || \
	(int)ft_strlen(list->set.map[y - 1]) <= x)
		ft_error_pr ("Invalid map");
	if (list->set.map[y][x + 1] == ' ' || list->set.map[y + 1][x] == ' ' \
	|| list->set.map[y][x - 1] == ' ' || list->set.map[y - 1][x] == ' ')
		ft_error_pr ("Invalid map");
}

void	parser_map(t_all *list)
{
	int			y;
	int			x;
	int			spr_num;
	int			y_len;

	y = 0;
	spr_num = 0;
	while (list->set.map[y] != NULL)
	{
		x = 0;
		y_len = ft_strlen(list->set.map[y]);
		while (list->set.map[y][x] != '\0')
		{
			if ((ft_strchr("02NSWE", list->set.map[y][x])))
				validation_map(list, y, x, y_len);
			if (list->set.map[y][x] == '2')
			{
				spr_placement(list, y, x, spr_num);
				spr_num++;
			}
			x++;
		}
		y++;
	}
}

void	join_mapls(t_all *list, char *str)
{
	char		*tmp;

	tmp = list->set.mapl;
	list->set.mapl = ft_strjoin(list->set.mapl, str);
	if (!list->set.mapl)
		ft_error_pr("Malloc problem in map");
	if (tmp != NULL)
		free(tmp);
}
