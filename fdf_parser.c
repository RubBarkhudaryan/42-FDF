/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:14:40 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/01 01:14:40 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static void	fill_row(int **row, char *str)
{
	char	**split;
	int		len;
	int		i;

	split = ft_split(str, ' ');
	len = row_len(split);
	i = 0;
	*row = (int *)malloc(sizeof(int) * len);
	if (!row)
		throw_error(-2);
	while (split[i] && i < len)
	{
		(*row)[i] = ft_atoi(split[i]);
		++i;
	}
	free_split(split);
}

t_fdf	*parse_map(char *file_path)
{
	int		fd;
	int		i;
	t_fdf	*data;
	t_line	ln;

	fd = open(file_path, O_RDONLY);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (fd < 0)
		throw_error(1);
	data->rows = file_length(file_path);
	data->matrix = (int **)malloc(sizeof(int *) * data->rows);
	if (!data->matrix)
	{
		data->matrix = NULL;
		return (data);
	}
	i = 0;
	while (get_next_line(fd, &ln.str))
	{
		fill_row(&data->matrix[i], ln.str);
		data->cols = row_len(ft_split(ln.str, ' '));
		free(ln.str);
		++i;
	}
	return (close(fd), data);
}
