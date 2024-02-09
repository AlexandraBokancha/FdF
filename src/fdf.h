/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:17:15 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:40:19 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"
# include <stdlib.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <stdio.h>
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define PI 3.14159265359

typedef struct s_data {
	struct s_data	*data;	
	void			*img;
	char			*addr;
	int				bpp;
	int				len;
	int				endian;
	void			*mlx;
	void			*win;
	int				**z;
	int				height;
	int				width;
	int				color;
}						t_data;

typedef struct s_cord {
	float	x;
	float	y;
	int		z;
	int		z1;
}								t_cord;

int		close_esc(int keycode, t_data *vars);
int		close_cross(t_data *vars);
void	free_tab(char **tab, int height);
void	free_tab_int(int **z, int height);
t_data	*init_map(char *file_name, t_data *data);
int		check_color(int color, int z_line);
void	draw_line(t_data *data, t_data *vars);
void	isometric(float *x, float *y, int z);
void	center(t_cord *point1, t_cord *point2);
void	scale(t_data *data, t_cord *point1, t_cord *point2);
void	destroy_win(t_data *env);
void	print_error(int flag, t_data *data, char **str);
void	init_tab_int(t_data *data);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
#endif