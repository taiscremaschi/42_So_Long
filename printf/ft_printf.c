/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:16:54 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/04/18 16:07:03 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formato(char type, va_list args)
{
	int	c;

	c = 0;
	if (type == '%')
		c += ft_putchar('%');
	else if (type == 'c')
		c += ft_putchar(va_arg(args, int));
	else if (type == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (type == 'd')
		c += ft_putnbr(va_arg(args, int));
	else if (type == 'i')
		c += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		c += ft_nbrunsigned(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		c += ft_hexad(va_arg(args, unsigned int), type);
	else if (type == 'p')
		c += ft_pointer(va_arg(args, unsigned long int), type);
	return (c);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		c;
	int		i;

	i = -1;
	c = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			c += formato(str[++i], args);
			continue ;
		}
		c += ft_putchar(str[i]);
	}
	return (c);
}
