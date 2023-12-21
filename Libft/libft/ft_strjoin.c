/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:46:06 by bwach             #+#    #+#             */
/*   Updated: 2023/10/30 08:59:41 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*mem;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	mem = (char *)malloc(len1 + len2 + 1);
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s1, len1);
	ft_memcpy(mem + len1, s2, len2);
	mem[len1 + len2] = '\0';
	return (mem);
}
