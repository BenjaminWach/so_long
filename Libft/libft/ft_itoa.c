/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:39:02 by bwach             #+#    #+#             */
/*   Updated: 2023/10/30 21:00:21 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*reverse_malloc(char *str)
{
	char	*new;
	int		i;
	int		end;

	end = ft_strlen(str);
	new = malloc(sizeof(char) * (end + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (--end >= 0)
		new[++i] = str[end];
	new[++i] = 0;
	return (new);
}

static char	*empty_malloc(void)
{
	char	*empty;

	empty = malloc(sizeof(char) * 2);
	if (!empty)
		return (NULL);
	empty[0] = '0';
	empty[1] = 0;
	return (empty);
}

char	*ft_itoa(int n)
{
	char		tab[12];
	int			i;
	int			sign;
	long int	nb;

	if (n == 0)
		return (empty_malloc());
	nb = (long int)n;
	sign = 1;
	if (nb < 0)
	{
		sign *= -1;
		nb = -nb;
	}
	i = 0;
	while (nb)
	{
		tab[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	if (sign == -1)
		tab[i++] = '-';
	tab[i] = 0;
	return (reverse_malloc(tab));
}
