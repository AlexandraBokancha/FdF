/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:50:27 by albokanc          #+#    #+#             */
/*   Updated: 2023/12/22 18:42:26 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "header/fdf.h"

/*int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, str);
	mlx_loop(mlx);
}*/


// to calculate the memory offset
// int offset = (y * line_len + x * (bits_per_pixel / 8));

/*void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

#include <stdio.h>

int close_window(int keycode, t_vars *vars)
{
	if (keycode == 65307)	
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int close_cross(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	// il faut liberer la memoire
	return (0);
}

int main(void)
{
	t_data img;
	t_trgb color;
	t_vars vars;
	int trgb;
	int i;
	int j;
	int color_shadow;
	int opposite_color;

	i = 0;
	color.t = 0;
	color.r = 255;
	color.g = 0;
	color.b = 255;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "fil de fer");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	//trgb = create_trgb(0, 255, 0, 255);
	//color_shadow = add_shade(0, 255, 0, 255, 0.5);
	opposite_color = get_opposite(&color);	
	while (i <= 1000)
	{	
			j = 0;
			while (j <= 1000)
			{	
				mlx_pixel_put(vars.mlx, vars.win, i, j, opposite_color);
				j++;
			}
			i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 1000, 1000);
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars); // pour fermer avec esc
	mlx_hook(vars.win, 33, 131072, close_cross, &vars); // pour fermer avec la croix
	mlx_loop(vars.mlx);
}			
