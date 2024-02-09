/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:50:27 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 18:05:31 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	push_win(t_data *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_hook(env->win, 2, 1L << 0, &close_esc, env);
	mlx_hook(env->win, 33, 131072, &close_cross, env);
	mlx_loop(env->mlx);
}

int	init_win(t_data *env)
{
	env->mlx = mlx_init();
	if (env->mlx == NULL)
	{
		free(env->mlx);
		return (0);
	}
	env->win = mlx_new_window(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (env->win == NULL)
	{
		free(env->win);
		return (0);
	}
	env->img = mlx_new_image(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env->addr = mlx_get_data_addr(env->img, &env->bpp, &env->len, &env->endian);
	return (1);
}

void	destroy_win(t_data *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	free_tab_int(env->data->z, env->data->height);
	free(env->data);
}

int	main(int ac, char **av)
{
	char	*file_name;
	t_data	env;

	if (ac != 2)
	{
		ft_printf("%s\n", "No file found. Please, try again.");
		exit(0);
	}
	file_name = av[1];
	if (ft_strstr(file_name, ".fdf") == 0)
	{
		ft_printf("%s\n", "File has a wrong format. Please, try again.");
		exit(0);
	}
	env.data = malloc(sizeof(t_data));
	if (!env.data)
		return (0);
	env.data = init_map(file_name, env.data);
	init_win(&env);
	draw_line(env.data, &env);
	push_win(&env);
	return (0);
}
