/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:48:13 by jtambra           #+#    #+#             */
/*   Updated: 2021/02/14 01:01:29 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_str(int len, char *str)
{
	int	count;

	count = 0;
	while (len-- && (*str != '\0'))
	{
		ft_putchar(*str);
		count++;
		str++;
	}
	return (count);
}

void	ft_change_value(t_spec value, int *len, int *spaces)
{
	if (value.dot > -1 && value.dot < *len)
		*len = value.dot;
	if (value.width > *len)
		*spaces = value.width - *len;
}

int		ft_s_parse(t_spec value, va_list arg)
{
	int		len;
	int		count;
	int		spaces;
	char	*str;

	spaces = 0;
	count = 0;
	if ((str = va_arg(arg, char*)) == NULL)
		str = "(null)";
	len = ft_strlen(str);
	ft_change_value(value, &len, &spaces);
	if (value.minus == 0)
		while (spaces--)
		{
			ft_putchar(' ');
			count++;
		}
	count = count + ft_put_str(len, str);
	if (spaces > 0)
		while (spaces--)
		{
			ft_putchar(' ');
			count++;
		}
	return (count);
}
