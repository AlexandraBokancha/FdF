/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsgnd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:55:41 by albokanc          #+#    #+#             */
/*   Updated: 2023/11/28 14:30:09 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsgnd(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
		count += ft_putchar(nb + '0');
	if (nb > 9)
	{
		count += ft_putnbr_unsgnd(nb / 10);
		count += ft_putchar(nb % 10 + '0');
	}
	return (count);
}
