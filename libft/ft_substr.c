/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:47:51 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 14:22:39 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		n;
	char				*res;

	i = 0;
	n = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && len > n)
		{
			res[n] = s[i];
			n++;
		}
		i++;
	}
	res[n] = '\0';
	return (res);
}
