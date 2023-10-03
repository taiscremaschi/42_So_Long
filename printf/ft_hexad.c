/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/04/17 22:28:43 by marvin            #+#    #+#             */
/*   Updated: 2023/04/17 22:28:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexad(unsigned long int n, int type)
{
	char	*p;
	int		c;

	c = 0;
	if (type == 'x' || type == 'p')
		p = "0123456789abcdef";
	if (type == 'X')
		p = "0123456789ABCDEF";
	if (n >= 16)
	{
		c += ft_hexad(n / 16, type);
		c += ft_hexad(n % 16, type);
	}
	else
		c += ft_putchar(p[n]);
	return (c);
}
