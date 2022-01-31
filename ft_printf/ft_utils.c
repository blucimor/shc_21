/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 23:35:41 by jtambra           #+#    #+#             */
/*   Updated: 2021/02/14 01:13:14 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_n(char *str, int i)
{
	int		count;

	count = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
		count++;
	}
	return (count);
}

size_t	ft_len_base(long long n, int base)
{
	size_t		i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_mini_atoi(const char *format, int *i)
{
	unsigned long long	num;

	num = 0;
	while (format[*i] <= '9' && format[*i] >= '0')
	{
		num = ((num * 10) + (format[*i] - '0'));
		(*i)++;
	}
	return ((int)num);
}
