/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:17:34 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:27:17 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(char **tab, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_tab_int(int **z, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(z[i]);
		i++;
	}
	free(z);
}

void	init_tab_int(t_data *data)
{
	int	i;

	i = 0;
	data->z = malloc(sizeof(int *) * data->height);
	if (!data->z)
		return ;
	while (i < data->height)
	{
		data->z[i] = malloc(sizeof(int) * data->width);
		if (!data->z[i])
			return ;
		i++;
	}
}
