/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:57:38 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/01 18:57:38 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static t_fdf	*malloc_fdf(void)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (NULL);
	data->z_min = 2147483647;
	data->z_max = -2147483648;
	data->cols = 0;
	return (data);
}

static void	check_cols(t_fdf *data, t_line *ln, int ind, int *fd)
{
	if (data->cols == 0)
		data->cols = row_len(ln->split);
	else if (data->cols > 0 && data->cols != row_len(ln->split))
	{
		get_next_line(-1, NULL);
		free(ln->str);
		free_split(&ln->split);
		free_matrix(&data->matrix, ind);
		close(*fd);
		free(data);
		throw_error(3);
	}
}

static void	fill_row(int **row, char **split, int *max, int *min)
{
	int		len;
	int		i;

	len = row_len(split);
	i = 0;
	*row = (int *)ft_calloc(len, sizeof(int));
	if (!row)
	{
		free_split(&split);
		throw_error(-2);
	}
	while (split[i] && i < len)
	{
		(*row)[i] = ft_atoi(split[i]);
		if (*min > (*row)[i])
			*min = (*row)[i];
		if (*max < (*row)[i])
			*max = (*row)[i];
		++i;
	}
}

t_fdf	*parse_map(char *file_path)
{
	int		fd;
	int		i;
	t_fdf	*data;
	t_line	ln;

	fd = open(file_path, O_RDONLY);
	data = malloc_fdf();
	if (!data || fd < 0)
		return (throw_error(1), free(data), NULL);
	data->rows = file_length(file_path);
	data->matrix = (int **)ft_calloc(data->rows, sizeof(int *));
	if (!data->matrix)
		return (NULL);
	i = 0;
	while (get_next_line(fd, &ln.str))
	{
		if (!ln.str)
			return (free_matrix(&data->matrix, i), NULL);
		ln.split = ft_split(ln.str, ' ');
		check_cols(data, &ln, i, &fd);
		fill_row(&data->matrix[i++], ln.split, &data->z_max, &data->z_min);
		free(ln.str);
		free_split(&ln.split);
	}
	return (close(fd), data);
}
