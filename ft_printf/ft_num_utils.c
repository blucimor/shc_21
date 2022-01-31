/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:24:01 by jtambra           #+#    #+#             */
/*   Updated: 2021/02/14 00:30:21 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_before_num(t_spec *value, char *str, int *count, int len)
{
	if (value->minus == 0)
	{
		if (value->width > len && value->sign_num == 1)
			value->width--;
		while ((value->width > len) || ((value->type != 'p' ||
			(value->type == 'p' && str[2] == '0')) && value->width >= len
			&& *str == '0' && value->dot == 0))
		{
			if (value->zero == 1 && value->dot != 0 && ((value->dot > len)
														|| (value->dot < 0)))
				ft_putchar('0');
			else
				ft_putchar(' ');
			value->width--;
			(*count)++;
		}
	}
}

void	ft_put_num(t_spec *value, char *str, int *count, int len)
{
	int		i;

	i = 0;
	if (value->sign_num == 1)
	{
		ft_putchar('-');
		(*count)++;
		value->width--;
	}
	if (value->dot == 0)
	{
		if (value->type == 'p' && str[2] == '0')
			str[2] = '\0';
		if (*str != '0' || (*str == '0' && len != 1))
			*count = *count + ft_put_n(str, i);
	}
	else
		*count = *count + ft_put_n(str, i);
}

int		ft_no_dot(t_spec value, char *str, int count)
{
	int		len;

	len = ft_strlen(str);
	if (value.sign_num == 1 && value.zero == 1 && value.dot < 0)
	{
		ft_putchar('-');
		count++;
		value.width--;
		value.sign_num = 0;
	}
	ft_before_num(&value, str, &count, len);
	ft_put_num(&value, str, &count, len);
	if (value.minus == 1)
		while ((value.width > len) || (value.width >= len && *str == '0'
										&& value.dot == 0))
		{
			ft_putchar(' ');
			value.width--;
			count++;
		}
	return (count);
}

void	ft_put_speces(t_spec value, int *count)
{
	if (value.minus == 0)
		while (value.width > value.dot)
		{
			ft_putchar(' ');
			value.width--;
			(*count)++;
		}
}

int		ft_dot_exist(t_spec value, char *str, int count, int i)
{
	int		len;

	len = ft_strlen(str);
	if (value.sign_num == 1 && value.minus == 0)
		value.width--;
	ft_put_speces(value, &count);
	if (value.sign_num == 1)
	{
		ft_putchar('-');
		count++;
	}
	while (value.dot > len)
	{
		ft_putchar('0');
		value.dot--;
		count++;
	}
	count = count + ft_put_n(str, i);
	if (value.minus == 1)
		while (value.width > (count))
		{
			ft_putchar(' ');
			count++;
		}
	return (count);
}
