/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:54:47 by albokanc          #+#    #+#             */
/*   Updated: 2023/11/28 14:30:13 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = (long) nb;
	if (nbr < 0)
	{
		nbr *= -1;
		count += ft_putchar('-');
	}
	if (nbr < 10)
		count += ft_putchar(nbr + '0');
	if (nbr > 9)
	{
		count += ft_putnbr(nbr / 10);
		count += ft_putchar(nbr % 10 + '0');
	}
	return (count);
}
