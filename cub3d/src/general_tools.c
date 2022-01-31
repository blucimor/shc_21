/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 01:39:58 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 13:38:36 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_pr(char *str)
{
	printf("Error!\n%s\n", str);
	exit(1);
}

static void	ft_clean_texture(t_texture *t)
{
	if (t->img != NULL)
		free(t->img);
	if (t->addr != NULL)
		free(t->addr);
}

void	ft_rgb_convertor(char *rgb, unsigned int *hex)
{
	char				**color;
	int					r;
	int					g;
	int					b;

	if (ft_chrcount(rgb, ',') > 2)
		ft_error_pr ("Wrong color format");
	color = ft_split(rgb, ',');
	if (!color)
		ft_error_pr("Malloc problem in colors");
	if (color[3])
		ft_error_pr("Wrong color format");
	if (ft_check_isdigit(color[0]) && ft_check_isdigit(color[1]) && \
		ft_check_isdigit(color[2]))
	{
		r = ft_atoi(color[0]);
		g = ft_atoi(color[1]);
		b = ft_atoi(color[2]);
		if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
			ft_error_pr("Wrong colors value");
		*hex = 256 * 256 * r + 256 * g + b;
		ft_free_array(color);
		return ;
	}
	ft_error_pr("Wrong entry format in colors setting");
}

void	ft_clean_leaks(t_all *list)
{
	if (list->set.map != NULL)
		ft_free_array(list->set.map);
	if (list->set.mapl != NULL)
		free(list->set.mapl);
	ft_clean_texture(&(list->img));
	ft_clean_texture(&(list->no));
	ft_clean_texture(&(list->so));
	ft_clean_texture(&(list->we));
	ft_clean_texture(&(list->ea));
	ft_clean_texture(&(list->sp));
	if (list->set.gnl_temp != NULL)
		free(list->set.gnl_temp);
	if (list->mlx.mlx != NULL)
		free(list->mlx.mlx);
	if (list->mlx.win != NULL)
		free(list->mlx.win);
	if (list->spr != NULL)
		free(list->spr);
}

void	claculate_hor_ray(t_all *list, float num)
{
	list->ray.hor_x = list->plr.x + (num) * define_coff_j(list->ray.angl) * \
	(BLOCK / fabs(tan(list->ray.angl))) + define_coff_j(list->ray.angl) * \
	(BLOCK * (define_coff_i(list->ray.angl) + 1.0) / 2.0 - \
	define_coff_i(list->ray.angl) * (list->plr.y - BLOCK * list->plr.cor_y)) \
	/ fabs(tan(list->ray.angl));
	list->ray.hor_j = floor(list->ray.hor_x / BLOCK);
	list->ray.hor_i = list->plr.cor_y + define_coff_i(list->ray.angl) * \
	(num + 1.0);
	list->ray.hor_y = (list->ray.hor_i + (1.0 - define_coff_i(list->ray.angl)) \
	/ 2.0) * BLOCK;
}
