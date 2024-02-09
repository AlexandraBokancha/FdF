/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:10:07 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:31:15 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(int flag, t_data *data, char **str)
{
	if (flag == 1)
		ft_printf("The map is too big for this program.\n");
	else if (flag == 2)
		ft_printf("Error opening file.\n");
	else if (flag == 3)
		ft_printf("The map is empty.\n");
	else if (flag == 4)
	{
		ft_printf("The map is in the wrong format.\n");
		free_tab(str, data->height);
	}
	free(data);
	exit(EXIT_FAILURE);
}
