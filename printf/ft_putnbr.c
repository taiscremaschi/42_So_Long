/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:38:14 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/04/18 14:21:43 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	c;

	c = 0;
	if (n == -2147483648)
	{
		c += ft_putchar('-');
		c += ft_putchar('2');
		c += ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		c += ft_putchar('-');
		c += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		c += ft_putnbr(n / 10);
		c += ft_putnbr(n % 10);
	}
	else
		c += ft_putchar(n + '0');
	return (c);
}
