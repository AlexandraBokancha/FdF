/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:26:28 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/06 16:58:39 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0' || little == big)
		return (0);
	while (big[i])
	{
		j = 0;
		while (little[j] && little[j] == big[i + j])
		{	
			j++;
		}
		if (j == ft_strlen(little))
			return (1);
		i++;
	}
	return (0);
}
