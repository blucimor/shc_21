/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 23:42:26 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 14:39:35 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numstr(const char *str, char c)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		while (str[i] != '\0' && str[i] != c)
			i++;
		if (str[i - 1] != c)
			num++;
	}
	return (num);
}

static int	ft_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char	*ft_copy(char **str, char c)
{
	char	*str_p;
	int		len;

	len = ft_len(*str, c);
	str_p = ft_substr(*str, 0, len);
	*str = *str + len;
	return (str_p);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		num_str;
	char	**res;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	num_str = ft_numstr(str, c);
	res = (char **)malloc(sizeof(char *) * (num_str + 1));
	if (!res)
		return (NULL);
	res[num_str] = NULL;
	while (i < num_str)
	{
		while (*str == c)
			str++;
		res[i] = ft_copy(&str, c);
		if (!res[i])
			return (ft_free(res));
		i++;
	}
	return (res);
}
