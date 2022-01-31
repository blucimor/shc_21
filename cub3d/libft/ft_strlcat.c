/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:17:56 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 14:24:31 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	end;

	end = ft_strlen(src) + ft_strlen(dst);
	i = ft_strlen(dst);
	if (size <= i)
		return (ft_strlen(src) + size);
	ft_strlcpy(dst + i, src, size - i);
	return (end);
}
