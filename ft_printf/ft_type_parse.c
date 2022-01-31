/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:42:57 by jtambra           #+#    #+#             */
/*   Updated: 2021/02/14 01:13:19 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier(t_spec *value)
{
	value->zero = 0;
	value->width = 0;
	value->dot = -1;
	value->minus = 0;
	value->type = 0;
	value->sign_num = 0;
}

int		ft_per_parse(t_spec value)
{
	int		count;

	count = 0;
	if (value.minus == 0 && value.zero == 1)
		while (value.width-- > 1)
		{
			ft_putchar('0');
			count++;
		}
	else if (value.minus == 0 && value.zero == 0)
		while (value.width-- > 1)
		{
			ft_putchar(' ');
			count++;
		}
	ft_putchar('%');
	count++;
	while (value.width-- > 1)
	{
		ft_putchar(' ');
		count++;
	}
	return (count);
}

int		ft_type_parse(const char *format, int *i, va_list arg, t_spec value)
{
	int	count;
	int	base;

	base = 10;
	count = 0;
	value.type = format[*i];
	if (format[*i] == 'c' || format[*i] == 'C')
		count = ft_c_parse(value, arg);
	else if (format[*i] == 's')
		count = ft_s_parse(value, arg);
	else if (format[*i] == 'p' || format[*i] == 'P')
		count = ft_p_parse(value, arg, 16);
	else if (format[*i] == 'd' || format[*i] == 'D' || format[*i] == 'i')
		count = ft_di_parse(value, arg, base);
	else if (format[*i] == 'u' || format[*i] == 'U')
		count = ft_u_parse(value, arg, base);
	else if (format[*i] == 'x' || format[*i] == 'X')
		count = ft_x_parse(value, arg, 16);
	else if (format[*i] == '%')
		count = ft_per_parse(value);
	else
		return (-1);
	return (count);
}
