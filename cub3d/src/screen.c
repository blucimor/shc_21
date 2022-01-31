/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 02:00:02 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 02:00:02 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_conv_int(unsigned char *begin, int fl_sz)
{
	begin[0] = (unsigned char)(fl_sz);
	begin[1] = (unsigned char)(fl_sz >> 8);
	begin[2] = (unsigned char)(fl_sz >> 16);
	begin[3] = (unsigned char)(fl_sz >> 24);
}

static void	ft_make_title(t_all *list, int fd, int fl_sz)
{
	int					i;
	int					tmp;
	unsigned char		title[BUFF_BMP];

	i = 0;
	while (i < BUFF_BMP)
		title[i++] = (unsigned char)(0);
	title[0] = 'B';
	title[1] = 'M';
	ft_conv_int(title + 2, fl_sz);
	title[10] = (unsigned char)(BUFF_BMP);
	title[14] = 40;
	tmp = list->set.re_width;
	ft_conv_int(title + 18, tmp);
	tmp = list->set.re_height;
	ft_conv_int(title + 22, tmp);
	title[27] = 1;
	title[28] = 24;
	if ((0 > write(fd, title, BUFF_BMP)))
		ft_error_pr ("Couldn't save screenshot");
}

static void	ft_make_content(t_all *list, int fd, int pd)
{
	int					y;
	int					x;
	unsigned int		pxl;
	const unsigned char	clr_z[3] = {0, 0, 0};

	y = list->set.re_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (list->set.re_width > x)
		{
			pxl = my_mlx_pixel_get(&list->img, x, y);
			if (0 > write(fd, &pxl, 3))
				ft_error_pr ("Couldn't make screenshot");
			if ((write(fd, &clr_z, pd) < 0) && 0 < pd)
				ft_error_pr ("Couldn't make screenshot");
			x++;
		}
		y--;
	}
}

void	ft_make_screen(t_all *list)
{
	int					fl_sz;
	int					fd;
	int					pd;

	fd = open("screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		ft_error_pr ("Couldn't open");
	pd = (4 - (list->set.re_width * 3) % 4) % 4;
	fl_sz = (3 * (list->set.re_width + pd) * list->set.re_height) + BUFF_BMP;
	ft_make_title(list, fd, fl_sz);
	ft_make_content(list, fd, pd);
	if (0 > (close(fd)))
		ft_error_pr ("Couldn't close");
}
