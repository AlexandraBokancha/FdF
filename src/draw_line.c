/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:31:47 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:36:10 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put(t_data *vars, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pxl = vars->addr + (y * vars->len + x * (vars->bpp / 8));
		*(unsigned int *)pxl = color;
	}
}

void	bresenham_line(t_data *data, t_cord p1, t_cord p2, t_data *vars)
{
	float	x_step;
	float	y_step;
	int		max_step;

	p1.z = data->z[(int)p1.y][(int)p1.x];
	p2.z = data->z[(int)p2.y][(int)p2.x];
	data->color = check_color(data->color, p1.z);
	scale(data, &p1, &p2);
	isometric(&p1.x, &p1.y, p1.z);
	isometric(&p2.x, &p2.y, p2.z);
	center(&p1, &p2);
	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	max_step = fmaxf(fabsf(x_step), fabsf(y_step));
	x_step /= max_step;
	y_step /= max_step;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		ft_mlx_pixel_put(vars, p1.x, p1.y, data->color);
		p1.x += x_step;
		p1.y += y_step;
		if (p1.x > WINDOW_WIDTH || p1.y > WINDOW_HEIGHT || p1.y < 0 || p1.x < 0)
			break ;
	}
}

void	draw_line(t_data *data, t_data *vars)
{
	t_cord	p1;
	t_cord	p2;

	p1.y = 0;
	while (p1.y < data->height)
	{
		p1.x = 0;
		while (p1.x < data->width)
		{
			p2 = p1;
			if (p1.x < data->width - 1)
			{
				p2.x += 1;
				bresenham_line(data, p1, p2, vars);
			}
			p2 = p1;
			if (p1.y < data->height - 1)
			{
				p2.y += 1;
				bresenham_line(data, p1, p2, vars);
			}
			p1.x++;
		}
		p1.y++;
	}
}
