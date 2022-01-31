/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 23:06:49 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 14:23:15 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	top;
	size_t	bot;
	char	*res;

	i = 0;
	top = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	bot = ft_strlen(s1);
	while (s1[top] != '\0' && ft_check(set, s1[top]))
		top++;
	while (bot > top && ft_check(set, s1[bot - 1]))
		bot--;
	res = (char *)malloc(sizeof(char) * ((bot - top) + 1));
	if (!res)
		return (NULL);
	while (top < bot)
		res[i++] = s1[top++];
	res[i] = '\0';
	return (res);
}
