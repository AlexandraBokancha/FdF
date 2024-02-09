/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:11 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:46:41 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **tab, int box)
{
	while (box >= 0)
	{
		free(tab[box]);
		box--;
	}
	free(tab);
}

int	create_tab(char **tab, const char *s, char sep)
{
	int	box;
	int	len;

	box = 0;
	len = 0;
	while (*s)
	{
		while (*s == sep && *s)
			s++;
		while (*s != sep && *s)
		{	
			len++;
			s++;
		}
		if (len > 0)
		{
			tab[box] = malloc(sizeof(char) * len + 1);
			if (!tab)
				return (ft_free(tab, box), 0);
			tab[box][len] = '\0';
		}
		box++;
		len = 0;
	}
	return (0);
}

void	fill_tab(char **tab, const char *s, char sep)
{
	int	i;
	int	box;

	i = 0;
	box = 0;
	while (*s)
	{
		while (*s == sep && *s)
			s++;
		while (*s != sep && *s)
		{	
			tab[box][i] = *s;
			s++;
			i++;
		}
		i = 0;
		box++;
	}
}

int	count_word(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str && str[i])
	{
		while (is_space(str[i]))
			i++;
		if (is_word(str[i]))
		{
			count++;
			while (is_word(str[i]))
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		total_words;

	if (!s)
		return (NULL);
	total_words = count_word(s);
	if (total_words < 0)
		return (NULL);
	tab = malloc(sizeof(char *) * (total_words + 1));
	if (!tab)
		return (NULL);
	tab[total_words] = 0;
	create_tab(tab, s, c);
	fill_tab(tab, s, c);
	return (tab);
}
