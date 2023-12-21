/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:26:55 by bwach             #+#    #+#             */
/*   Updated: 2023/10/30 20:14:29 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;
	size_t			s_len;

	s_len = ft_strlen(s);
	if (start >= s_len || !s || len == 0)
	{
		new = malloc(1);
		if (!new)
			return (NULL);
		new[0] = 0;
		return (new);
	}
	if (len > s_len - start)
		len = s_len - start;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (s[start] && ++i < len)
		new[i] = s[start + i];
	new[i] = '\0';
	return (new);
}
