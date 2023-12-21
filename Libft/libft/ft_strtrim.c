/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:34:39 by bwach             #+#    #+#             */
/*   Updated: 2023/10/30 12:07:53 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		start;
	char	*dup;
	int		len;

	i = 0;
	dup = 0;
	if (!s1[0])
	{
		dup = (char *)malloc(1);
		if (!dup)
			return (NULL);
		*dup = 0;
		return (dup);
	}
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = i;
	while (s1[i])
		i++;
	i--;
	while (i >= 0 && (s1[i] && ft_strchr(set, s1[i])))
		i--;
	len = i - start + 1;
	return (ft_substr(s1, (unsigned int)start, (size_t)len));
}
