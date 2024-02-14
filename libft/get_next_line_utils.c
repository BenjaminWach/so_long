/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:08:09 by bwach             #+#    #+#             */
/*   Updated: 2024/01/30 13:43:45 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy_gnl(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*mem;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	mem = (char *)malloc((len1 + len2) + 1);
	if (!mem)
		return (NULL);
	ft_strlcpy(mem, s1, len1 + 1);
	ft_strlcpy(mem + len1, s2, len2 + 1);
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (mem);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char		*sub_str;
	size_t		s_len;

	s_len = ft_strlen(s + start);
	if (s_len < len)
		len = s_len;
	sub_str = (char *) malloc(len + 1);
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}

void	*ft_memset_gnl(void *b, int c, size_t len)
{
	unsigned char	*dest;

	dest = (unsigned char *)b;
	while (len --)
		dest[len] = (unsigned char)c;
	return (b);
}
