/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:36 by albokanc          #+#    #+#             */
/*   Updated: 2024/01/04 18:53:24 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	unsigned int	len;
	unsigned int	count;

	count = 0;
	len = ft_strnlen(base);
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr < len)
		count += ft_putchar(base[nbr]);
	else
	{
		count += ft_putnbr_base(nbr / len, base);
		count += ft_putchar(base[nbr % len]);
	}
	return (count);
}
