/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:49:20 by albokanc          #+#    #+#             */
/*   Updated: 2024/01/23 15:37:07 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_base(char *base)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = ft_strlen(base);
	while ((base[i] >= 33 && base[i] < 43)
		|| (base[i] >= 44 && base[i] < 45)
		|| (base[i] >= 46 && base[i] <= 126))
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	if (i == len && len > 1)
		return (0);
	return (1);
}

int	ft_strchr_base(char c, char *base)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(base))
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_posin_base(char c, char *base)
{
	int	i;

	i = 0;
	while (c != base[i] && base[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	if (ft_check_base(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
	{
		if (ft_strchr_base(str[i], base) < 0)
			return (0);
		nbr = nbr * ft_strlen(base) + ft_posin_base(str[i], base);
		i++;
	}
	return (nbr * sign);
}
