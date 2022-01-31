/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:53:18 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 13:54:48 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_xpm_to_texture(t_all *list, t_texture *img, char *path)
{
	img->img = mlx_xpm_file_to_image(list->mlx.mlx, path, &(img->img_x), \
	&(img->img_y));
	if (!img->img)
		ft_error_pr ("Invalid settings argument img");
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
	&(img->line_length), &(img->endian));
	if (!img->addr)
		ft_error_pr ("Invalid settings argument addr");
	img->flg = 1;
}

void	my_mlx_pixel_put(t_texture *img, int x, int y, int color)
{
	char		*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_texture *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	struct_intit_mlx(t_all *list)
{
	struct_init_map(list);
	struct_init_spr(list);
	list->img.img = mlx_new_image(list->mlx.mlx, list->set.re_width, \
	list->set.re_height);
	list->img.addr = mlx_get_data_addr(list->img.img, &list->img.bits_per_pixel, \
	&list->img.line_length, &list->img.endian);
	if (list->com_flg != FLG_BMP)
		list->mlx.win = mlx_new_window(list->mlx.mlx, list->set.re_width, \
		list->set.re_height, "cub3d by blucimor");
}

int	draw_my_window(t_all *list)
{
	draw_map_block(list);
	make_spr(list);
	mlx_put_image_to_window(list->mlx.mlx, list->mlx.win, list->img.img, 0, 0);
	mlx_do_sync(list->mlx.mlx);
	return (0);
}
