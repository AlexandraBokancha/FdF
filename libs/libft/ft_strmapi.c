/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:05:42 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:47:19 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*news;

	i = 0;
	if (!s)
		return (NULL);
	news = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!news)
		return (NULL);
	while (s[i])
	{
		news[i] = (*f)(i, s[i]);
		i++;
	}
	news[i] = '\0';
	return (news);
}
