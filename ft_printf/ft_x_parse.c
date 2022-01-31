/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:51:51 by jtambra           #+#    #+#             */
/*   Updated: 2021/02/14 01:11:38 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x_upper(char *str, t_spec value)
{
	int		i;

	i = 0;
	if (value.type == 'X')
		while (str[i] != '\0')
		{
			str[i] = ft_toupper((int)str[i]);
			i++;
		}
}

int		ft_x_parse(t_spec value, va_list arg, int base)
{
	char		*str;
	int			len;
	long long	num;
	int			count;
	int			i;

	i = 0;
	count = 0;
	num = va_arg(arg, int);
	if (num < 0)
	{
		num = num * -1;
		num = (4294967295 - num) + 1;
	}
	if ((str = ft_itoa_base(num, base)) == NULL)
		return (-1);
	len = ft_strlen(str);
	ft_x_upper(str, value);
	if (value.dot < 0 || value.dot <= len)
		count = ft_no_dot(value, str, count);
	if (value.dot != -1 && value.dot > len)
		count = ft_dot_exist(value, str, count, i);
	if (str)
		free(str);
	return (count);
}
