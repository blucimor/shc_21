/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:00:13 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 14:25:22 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	size_t		end;
	char		*res;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	end = s1_len + s2_len;
	res = (char *)malloc(sizeof(char) * ((end + 1)));
	if (!res)
		return (NULL);
	else
	{
		ft_memcpy(res, s1, s1_len);
		ft_memcpy(res + s1_len, s2, s2_len);
	}
	res[end] = '\0';
	return (res);
}
