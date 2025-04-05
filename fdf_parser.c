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
	return (data);
}

static void	fill_row(int **row, char *str, int *max, int *min)
{
	char	**split;
	int		len;
	int		i;

	split = ft_split(str, ' ');
	if (!split)
		return ;
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
	free_split(&split);
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
		throw_error(1);
	data->rows = file_length(file_path);
	data->matrix = (int **)ft_calloc(data->rows, sizeof(int *));
	if (!data->matrix)
		return (NULL);
	i = 0;
	while (get_next_line(fd, &ln.str))
	{
		if (!ln.str)
			return (free_matrix(&data->matrix, i), NULL);
		fill_row(&data->matrix[i++], ln.str, &data->z_max, &data->z_min);
		ln.split = ft_split(ln.str, ' ');
		data->cols = row_len(ln.split);
		free(ln.str);
		free_split(&ln.split);
	}
	return (close(fd), data);
}
