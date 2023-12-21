/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:37:06 by bwach             #+#    #+#             */
/*   Updated: 2023/10/26 10:46:21 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str;
	char	*str1;

	i = 0;
	str = (char *)s1;
	str1 = (char *)s2;
	while (i < n)
	{
		if (str[i] != str1[i])
			return ((unsigned char)str[i] - (unsigned char)str1[i]);
		i++;
	}
	return (0);
}
