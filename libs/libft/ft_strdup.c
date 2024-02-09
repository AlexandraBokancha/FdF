/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:20:55 by albokanc          #+#    #+#             */
/*   Updated: 2023/11/16 20:14:41 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc((ft_strlen(s) + 1) * (sizeof(char)));
	if (!dup)
		return (NULL);
	while (s[i])
	{	
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
