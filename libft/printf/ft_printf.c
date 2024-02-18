/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:34:13 by bwach             #+#    #+#             */
/*   Updated: 2024/02/17 17:04:33 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_conversion(va_list args, const char conversion)
{
	int	print_length;

	print_length = 0;
	if (conversion == 'c')
		print_length += ft_putchar(va_arg(args, int));
	else if (conversion == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (conversion == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (conversion == 'd' || conversion == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (conversion == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (conversion == 'x' || conversion == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), conversion);
	else if (conversion == '%')
		print_length += ft_print_percent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
			print_length += ft_conversion(args, str[++i]);
		else
			print_length += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (print_length);
}
