/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:02:01 by jtambra           #+#    #+#             */
/*   Updated: 2021/02/14 01:12:37 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flags(const char *format, int *i, t_spec *value)
{
	if (format[*i] == '-')
		value->minus = 1;
	if (format[*i] == '0')
		value->zero = 1;
}

void	ft_parse_dot(const char *format, int *i, t_spec *value, va_list arg)
{
	(*i)++;
	if (format[*i] == '-')
		return ;
	if (format[*i] >= '0' && format[*i] <= '9')
		value->dot = ft_mini_atoi(format, i);
	else if (format[*i] == '*')
	{
		value->dot = va_arg(arg, int);
		(*i)++;
	}
	else
		value->dot = 0;
}

void	ft_parse_star(t_spec *value, va_list arg, int *i)
{
	if ((value->width = va_arg(arg, int)) < 0)
	{
		value->minus = 1;
		value->width = -value->width;
	}
	(*i)++;
}

int		ft_parser(int *count, const char *format, int *i, va_list arg)
{
	t_spec	value;
	int		num;

	num = 0;
	ft_specifier(&value);
	(*i)++;
	if (format[(*i)] == '%')
	{
		ft_putchar(format[*i]);
		return ((*count)++);
	}
	while (format[*i] == '-' || format[*i] == '0')
	{
		ft_parse_flags(format, i, &value);
		(*i)++;
	}
	if (format[*i] == '*')
		ft_parse_star(&value, arg, i);
	else if (format[*i] >= '0' && format[*i] <= '9')
		value.width = ft_mini_atoi(format, i);
	if (format[*i] == '.')
		ft_parse_dot(format, i, &value, arg);
	num = ft_type_parse(format, i, arg, value);
	*count = (num >= 0) ? *count + num : -1;
	return (*count);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		j;
	int		count;

	i = -1;
	j = 0;
	count = 0;
	va_start(arg, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_parser(&count, format, &i, arg);
			if (count < 0)
				return (-1);
		}
		else
		{
			ft_putchar(format[i]);
			j++;
		}
	}
	va_end(arg);
	return (count + j);
}
