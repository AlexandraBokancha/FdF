/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:18:31 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:29:24 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_color(int color, int z_line)
{
	if (z_line > 0)
		color = 0x00ff00;
	else
		color = 0xffffff;
	return (color);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(PI / 4);
	*y = (*x + *y) * sin(PI / 4) - z;
}

void	center(t_cord *point1, t_cord *point2)
{
	point1->x += (float)WINDOW_WIDTH / 2;
	point1->y += (float)WINDOW_HEIGHT / 4;
	point2->x += (float)WINDOW_WIDTH / 2;
	point2->y += (float)WINDOW_HEIGHT / 4;
}

void	scale(t_data *data, t_cord *point1, t_cord *point2)
{
	float	scale;
	float	scale_z;

	if (data->height < 100)
	{
		scale = 20;
		scale_z = 5;
	}
	else if (data->height >= 100 && data->height < 200)
	{
		scale = 6;
		scale_z = 3;
	}
	else
	{	
		scale = 2;
		scale_z = 1.5;
	}
	point1->x *= scale;
	point1->y *= scale;
	point2->x *= scale;
	point2->y *= scale;
	point1->z *= scale_z;
	point2->z *= scale_z;
}
