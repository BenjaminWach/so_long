/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:56:12 by bwach             #+#    #+#             */
/*   Updated: 2023/10/26 13:12:28 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		n = -n;
	else
		write(fd, "-", 1);
	if (n / 10)
		ft_putnbr_fd((unsigned int)(-n) / 10, fd);
	write(fd, &"0123456789"[(unsigned int)(-n) % 10], 1);
}
