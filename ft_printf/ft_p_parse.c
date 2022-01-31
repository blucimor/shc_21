/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:54:02 by jtambra           #+#    #+#             */
/*   Updated: 2021/02/14 01:09:38 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

size_t	ft_len_ptr(unsigned long long n, int base)
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

char	*ft_itoa_pointer(unsigned long long nb, int base)
{
	char				*str;
	unsigned long long	len;

	len = ft_len_ptr(nb, base) + 2;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	if (nb == 0)
		str[len - 1] = '0';
	while (nb > 0)
	{
		str[len - 1] = (nb % base >= 10) ? nb % base + 87 : nb % base + 48;
		nb = nb / base;
		len--;
	}
	return (str);
}

int		ft_p_parse(t_spec value, va_list arg, int base)
{
	char				*str;
	unsigned long long	ptr;
	int					count;
	int					i;
	int					len;

	count = 0;
	i = 0;
	ptr = va_arg(arg, unsigned long long);
	if ((str = ft_itoa_pointer(ptr, base)) == NULL)
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
