/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:45:24 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/04/18 14:35:35 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (!str)
	{
		c += (ft_putstr("(null)"));
		return (c);
	}
	while (str[i])
	{
		c += ft_putchar(str[i]);
		i++;
	}
	return (c);
}
