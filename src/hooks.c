/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:38:21 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:30:41 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_esc(int keycode, t_data *vars)
{
	if (keycode == 65307)
	{
		destroy_win(vars);
		exit(0);
	}
	return (0);
}

int	close_cross(t_data *vars)
{
	destroy_win(vars);
	exit(0);
	return (0);
}
