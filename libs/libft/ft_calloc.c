/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:14:59 by albokanc          #+#    #+#             */
/*   Updated: 2023/11/15 21:06:58 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;
	size_t	i;

	i = nmemb * size;
	if (i && !(i / size == nmemb))
		return (NULL);
	c = malloc(i);
	if (!c)
		return (NULL);
	ft_bzero(c, i);
	return (c);
}
