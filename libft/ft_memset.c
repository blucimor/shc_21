/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:34:38 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 14:31:00 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)buf;
	while (len-- > 0)
		*temp++ = (unsigned char)c;
	return (buf);
}
