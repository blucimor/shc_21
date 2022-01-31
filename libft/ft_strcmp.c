/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:31:18 by blucimor          #+#    #+#             */
/*   Updated: 2021/03/30 22:31:18 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	if (!str1 || !str2 || ft_strlen(str1) != ft_strlen(str2))
		return (0);
	if (str1 == str2 && str1 == NULL)
		return (1);
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	if (*str1 != *str2)
		return (0);
	return (1);
}
