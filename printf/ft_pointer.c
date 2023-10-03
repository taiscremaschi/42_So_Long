/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/04/17 22:51:27 by marvin            #+#    #+#             */
/*   Updated: 2023/04/17 22:51:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long int n, int type)
{
	int	c;

	c = 0;
	if (!n)
		c += ft_putstr("(nil)");
	else
	{
		c += ft_putstr("0x");
		c += ft_hexad(n, type);
	}
	return (c);
}
