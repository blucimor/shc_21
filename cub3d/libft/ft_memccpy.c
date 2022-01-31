/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:25:29 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 14:31:53 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t				i;
	unsigned char		ch;
	unsigned char		*d;
	const unsigned char	*s;

	ch = (unsigned char)c;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (len--)
	{
		d[i] = s[i];
		if (s[i] == ch)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
