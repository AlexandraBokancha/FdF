/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:16:17 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:22:38 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_word(const char *s, char sep);

void	fill_map(char *line, int *z_line, t_data *data)
{
	int		i;
	char	**tab;

	tab = ft_split(line, ' ');
	i = 0;
	while (i < data->width)
	{
		z_line[i] = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

int	get_width(char **file_content, t_data *data)
{
	int	width;
	int	i;

	i = 1;
	width = count_word(file_content[0], ' ');
	while (i < data->height)
	{
		if (width != count_word(file_content[i], ' '))
			print_error(4, data, file_content);
		i++;
	}
	return (width);
}

char	**open_map(char *file_name, int lines)
{
	int		fd;
	char	*line;
	char	**buf;
	int		i;

	i = 0;
	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1 || BUFFER_SIZE < 0)
		exit(0);
	buf = malloc(sizeof(char *) * lines);
	if (!buf)
		return (NULL);
	buf[0] = 0;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		buf[i++] = line;
		line = get_next_line(fd);
	}
	close(fd);
	return (buf);
}

int	get_height(char *file_name, t_data *data)
{
	int		fd;
	char	*line;
	int		height;

	line = NULL;
	height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1 || BUFFER_SIZE < 0)
		print_error(2, data, NULL);
	line = get_next_line(fd);
	if (line == NULL)
		print_error(3, data, NULL);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (height);
}

t_data	*init_map(char *file_name, t_data *data)
{
	char	**file_content;
	int		i;

	data->height = get_height(file_name, data);
	if (data->height > 1080)
		print_error(1, data, NULL);
	file_content = open_map(file_name, data->height);
	data->width = get_width(file_content, data);
	init_tab_int(data);
	i = 0;
	while (i < data->height)
	{
		fill_map(file_content[i], data->z[i], data);
		i++;
	}
	free_tab(file_content, data->height);
	return (data);
}
