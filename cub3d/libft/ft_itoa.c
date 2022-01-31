/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:44:35 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 14:33:46 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dozen(int n)
{
	int	q;

	q = 0;
	if (n <= 0)
		q++;
	while (n != 0)
	{
		q++;
		n = n / 10;
	}
	return (q);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			dozen;
	long int	nb;

	nb = n;
	dozen = ft_dozen(nb);
	result = (char *)malloc((dozen + 1) * sizeof(char));
	if (result)
	{
		if (nb == 0)
			result[0] = '0';
		if (nb < 0)
		{
			result[0] = '-';
			nb = nb * -1;
		}
		result[dozen] = '\0';
		while (nb)
		{
			result[--dozen] = nb % 10 + '0';
			nb = nb / 10;
		}
		return (result);
	}
	return (NULL);
}
