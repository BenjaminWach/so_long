/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:18:18 by bwach             #+#    #+#             */
/*   Updated: 2023/10/28 14:10:29 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*temp1;
	char			*temp2;

	i = 0;
	temp1 = (char *)src;
	temp2 = (char *)dest;
	if (!src && !dest)
		return (dest);
	while (i < n)
	{
		temp2[i] = temp1[i];
		i++;
	}
	return (dest);
}
