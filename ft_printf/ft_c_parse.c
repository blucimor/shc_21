/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:50:28 by jtambra           #+#    #+#             */
/*   Updated: 2021/02/13 23:50:47 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c_parse(t_spec value, va_list arg)
{
	int			len;
	char		c;

	len = 0;
	if (value.minus == 0)
		while (value.width > 1)
		{
			ft_putchar(' ');
			len++;
			value.width--;
		}
	c = (char)va_arg(arg, int);
	ft_putchar(c);
	len++;
	if (value.minus == 1)
		while (value.width > 1)
		{
			ft_putchar(' ');
			len++;
			value.width--;
		}
	return (len);
}
