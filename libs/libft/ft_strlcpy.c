/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:58:45 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:47:09 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcpy(char *s1, char *s2, char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	while (buff[j])
	{
		s2[i++] = buff[j];
		j++;
	}
	free(s1);
	s2[i] = '\0';
	return (s2);
}
