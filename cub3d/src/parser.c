/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:36:38 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 14:06:15 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	create_map(t_all *list)
{
	if (list->set.mapl)
	{
		if ((int)ft_strlen(list->set.gnl_temp) > list->set.x_max)
			list->set.x_max = ft_strlen(list->set.gnl_temp);
		join_mapls(list, list->set.gnl_temp);
		join_mapls(list, "|");
		list->set.y_max++;
	}
	else
	{
		list->set.mapl = ft_strdup(list->set.gnl_temp);
		if (!list->set.mapl)
			ft_error_pr("Malloc problem in map");
		join_mapls(list, "|");
		list->set.y_max++;
	}
}

static void	collect_plr_spr(t_all *list)
{
	int			x;

	x = 0;
	while (list->set.gnl_temp[x])
	{
		if ((ft_strchr("NSWE", list->set.gnl_temp[x])))
		{
			if (list->plr.flg_plr)
				ft_error_pr ("Only one player is allowed");
			list->plr.flg_plr = 1;
			find_plr(list, x, list->set.gnl_temp[x]);
		}
		else if (!(ft_strchr(" 012", list->set.gnl_temp[x])))
			ft_error_pr ("Invalid map");
		if (list->set.gnl_temp[x] == '2')
			list->set.spr_num += 1;
		x++;
	}
	list->set.mp_flg = 1;
}

static void	parse_gnl_temp(t_all *list)
{
	char			**arr;

	arr = NULL;
	arr = ft_split(list->set.gnl_temp, ' ');
	if (!arr)
		ft_error_pr("Malloc problem in settings");
	if (ft_strcmp(arr[0], "R"))
	{
		if (list->set.set_flgs & FLG_RE)
			ft_error_pr("Only one resolution setting allowed");
		parser_resolution(list, arr);
	}
	else if ((ft_strcmp(arr[0], "F")) || (ft_strcmp(arr[0], "C")))
		parser_colors(list, arr);
	else if ((ft_strcmp(arr[0], "NO")) || (ft_strcmp(arr[0], "SO")) || \
	(ft_strcmp(arr[0], "WE")) || (ft_strcmp(arr[0], "EA")) || \
	(ft_strcmp(arr[0], "S")))
		parse_texture_path(list, arr);
	else
		ft_error_pr ("Invalid settings argument 1");
	if (arr != NULL)
		ft_free_array(arr);
}

static void	collect_settings_data(t_all *list)
{
	if (*list->set.gnl_temp)
	{
		if (list->set.set_flgs != FLG_AL)
			parse_gnl_temp(list);
		else
		{
			collect_plr_spr(list);
			create_map(list);
		}
	}
	else
	{
		if (list->set.mp_flg)
			ft_error_pr("Invalid map");
	}
}

void	parser_settings(t_all *list)
{
	int				gnl;

	gnl = 1;
	list->set.spr_num = 0;
	while (gnl)
	{
		gnl = get_next_line(list->set.fd, &list->set.gnl_temp);
		if (gnl == -1)
			ft_error_pr("GNL problem");
		collect_settings_data(list);
		if (list->set.gnl_temp != NULL)
		{
			free(list->set.gnl_temp);
			list->set.gnl_temp = NULL;
		}
	}
	if (!list->plr.flg_plr)
		ft_error_pr("Should be a player");
	if (list->set.gnl_temp != NULL)
	{
		free(list->set.gnl_temp);
		list->set.gnl_temp = NULL;
	}
}
