/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:43:35 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 18:56:18 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_dir_texture(t_all *list, char **arr)
{
	if (arr[0][0] == 'N' && arr[0][1] == 'O' && !arr[2])
	{
		if ((list->set.set_flgs & FLG_NO))
			ft_error_pr ("Only one north texture setting allowed");
		mlx_xpm_to_texture(list, &(list->no), arr[1]);
		list->set.set_flgs |= FLG_NO;
	}
	else if (arr[0][0] == 'W' && arr[0][1] == 'E' && !arr[2])
	{
		if ((list->set.set_flgs & FLG_WE))
			ft_error_pr ("Only one west texture setting allowed");
		mlx_xpm_to_texture(list, &(list->we), arr[1]);
		list->set.set_flgs |= FLG_WE;
	}
	else if (arr[0][0] == 'E' && arr[0][1] == 'A' && !arr[2])
	{
		if ((list->set.set_flgs & FLG_EA))
			ft_error_pr ("Only one east texture setting allowed");
		mlx_xpm_to_texture(list, &(list->ea), arr[1]);
		list->set.set_flgs |= FLG_EA;
	}
	else
		ft_error_pr ("The texture path is not correct!");
}

void	parse_texture_path(t_all *list, char **arr)
{
	if (arr[0][0] == 'W' || arr[0][0] == 'E' || arr[0][0] == 'N')
		parse_dir_texture(list, arr);
	else if (arr[0][0] == 'S' && arr[0][1] == 'O' && !arr[2])
	{
		if ((list->set.set_flgs & FLG_SO))
			ft_error_pr ("Only one soth texture setting allowed");
		mlx_xpm_to_texture(list, &(list->so), arr[1]);
		list->set.set_flgs |= FLG_SO;
	}
	else if (arr[0][0] == 'S' && arr[0][1] == '\0' && !arr[2])
	{
		if ((list->set.set_flgs & FLG_SP))
			ft_error_pr ("Only one sprite texture setting allowed");
		mlx_xpm_to_texture(list, &(list->sp), arr[1]);
		list->set.set_flgs |= FLG_SP;
	}
	else
		ft_error_pr ("The texture path is not correct");
}

void	parser_resolution(t_all *list, char **arr)
{
	long int	resol;

	if (arr[0][0] == 'R' && !arr[3])
	{
		if (!ft_check_isdigit(arr[1]) || !ft_check_isdigit(arr[2]))
			ft_error_pr("Only unsigned integers allowed in resolution");
		resol = ft_atoi(arr[1]);
		if (resol > 0 && resol < list->set.re_width)
			list->set.re_width = resol;
		if (resol == 0)
			ft_error_pr("Resolution is not correct");
		resol = ft_atoi(arr[2]);
		if (resol > 0 && resol < list->set.re_height)
			list->set.re_height = resol;
		if (resol == 0)
			ft_error_pr("Resolution is not correct");
		list->set.set_flgs |= FLG_RE;
	}
	else
		ft_error_pr("Resolution is not correct");
}

void	parser_colors(t_all *list, char **arr)
{
	if (arr[0][0] == 'F' && !arr[2])
	{
		if (list->set.set_flgs & FLG_FL)
			ft_error_pr("Only one floor color setting allowed");
		ft_rgb_convertor(arr[1], &list->set.fl_color);
		list->set.set_flgs |= FLG_FL;
	}
	else if (arr[0][0] == 'C' && !arr[2])
	{
		if (list->set.set_flgs & FLG_CE)
			ft_error_pr("Only one ceiling color setting allowed");
		ft_rgb_convertor(arr[1], &list->set.ce_color);
		list->set.set_flgs |= FLG_CE;
	}
	else
		ft_error_pr("In the color settings");
}
