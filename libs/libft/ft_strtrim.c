/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:15:26 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:47:27 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkstr(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	int		start;
	char	*strtrim;

	i = 0;
	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && ft_checkstr(s1[start], set))
		start++;
	while (end > start && ft_checkstr(s1[end - 1], set))
		end--;
	strtrim = malloc(sizeof(char) * (end - start) + 1);
	if (!strtrim)
		return (NULL);
	while (s1[start] && start < end)
	{
		strtrim[i] = s1[start];
		i++;
		start++;
	}
	strtrim[i] = 0;
	return (strtrim);
}
