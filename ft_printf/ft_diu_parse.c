/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diu_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:02:44 by jtambra           #+#    #+#             */
/*   Updated: 2021/02/14 01:09:57 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(long long nb, int base)
{
	char		*str;
	size_t		len;

	len = ft_len_base(nb, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
		nb = nb * -1;
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		if (nb % base >= 10)
			str[len - 1] = nb % base + 87;
		else
			str[len - 1] = nb % base + 48;
		nb = nb / base;
		len--;
	}
	return (str);
}

int		ft_di_parse(t_spec value, va_list arg, int base)
{
	char		*str;
	int			i;
	int			count;
	int			len;
	long long	num;

	count = 0;
	i = 0;
	if ((num = va_arg(arg, int)) < 0)
		value.sign_num = 1;
	if ((str = ft_itoa_base(num, base)) == NULL)
		return (-1);
	len = ft_strlen(str);
	if (value.dot < 0 || value.dot <= len)
		count = ft_no_dot(value, str, count);
	if (value.dot != -1 && value.dot > len)
		count = ft_dot_exist(value, str, count, i);
	if (str)
		free(str);
	return (count);
}

int		ft_u_parse(t_spec value, va_list arg, int base)
{
	char		*str;
	int			i;
	int			count;
	int			len;
	long long	num;

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
	if (value.dot < 0 || value.dot <= len)
		count = ft_no_dot(value, str, count);
	if (value.dot != -1 && value.dot > len)
		count = ft_dot_exist(value, str, count, i);
	if (str)
		free(str);
	return (count);
}
