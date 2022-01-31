/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:34:25 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 13:49:17 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_for_save(t_all *list, char *str)
{
	int			i;

	i = 0;
	if (str[0] == '-' && str[1] == '-' && str[2] == 's' && str[3] == 'a' \
	&& str[4] == 'v' && str[5] == 'e' && str[6] == '\0')
		list->com_flg |= FLG_BMP;
	else
		ft_error_pr("Wrong --save command!");
}

void	valid_scene_format(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!(i > 4 && str[i - 4] == '.' && str[i - 3] == 'c' && \
	str[i - 2] == 'u' && str[i - 1] == 'b'))
		ft_error_pr("Not valid scene description format");
}

void	run_cub3d(t_all *list, char *sceen)
{
	struct_init(list, sceen);
	parser_settings(list);
	struct_intit_mlx(list);
	parser_map(list);
	if (list->com_flg & FLG_BMP)
	{
		draw_map_block(list);
		make_spr(list);
		ft_make_screen(list);
		return ;
	}
	mlx_hook(list->mlx.win, 17, 0, ft_close, list);
	mlx_hook(list->mlx.win, 2, 0, keys_hook, list);
	mlx_loop_hook(list->mlx.mlx, draw_my_window, list);
	mlx_loop(list->mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_all		list;

	if (argc < 2 || argc > 3)
		ft_error_pr("Wrong number of arguments!");
	valid_scene_format(argv[1]);
	if (argc == 2)
		run_cub3d(&list, argv[1]);
	else if (argc == 3)
	{
		check_for_save(&list, argv[2]);
		run_cub3d(&list, argv[1]);
	}
	ft_clean_leaks(&list);
	if ((close(list.set.fd) == -1))
		ft_error_pr("Close() problem");
	exit(0);
}
