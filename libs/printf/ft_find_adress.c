/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_adress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:02:04 by albokanc          #+#    #+#             */
/*   Updated: 2023/11/28 15:22:30 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_adress(void *ptr)
{
	int					count;
	char				*base;
	unsigned long long	p;

	base = "0123456789abcdef";
	count = 0;
	p = (unsigned long long)ptr;
	if (p == 0)
		return (ft_putstr("(nil)"));
	count += write(1, "0x", 2);
	count += ft_putnbr_base(p, base);
	return (count);
}
