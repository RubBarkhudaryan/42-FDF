/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 01:24:40 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/03/26 01:24:40 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void foo(char *file_path, int fd)
{
	fdf		obj;
	char	*str;
	char	**row;

	obj.rows = file_length(file_path);
	obj.matrix = (int **)malloc(sizeof(int *) * obj.rows);

	if (!obj.matrix)
		printf("Matrix allocation failed.\n");

	int i = 0;
	int j = 0;

	str = get_next_line(fd);
	row = ft_split(str);
	obj.cols = matrix_len(row);

	while (i < obj.rows && str)
	{
		j = 0;
		obj.matrix[i] = (int *)malloc(sizeof(int) * obj.cols);
		if (!obj.matrix[i])
		{
			printf("Matrix[i] allocation failed.\n");
			break;
		}
		row = ft_split(str);
		while (j < obj.cols)
			obj.matrix[i][j] = ft_atoi(row[j++]);
		free(str);
		str = get_next_line(fd);
		++i;
	}
	close(fd);
}


int	main(int argc, char *argv[])
{
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);

		if (fd == -1)
		{
			printf("File opening failed.\n");
			return (0);
		}

		foo(argv[1], fd);
	}
	else
		printf("Arg counts error\n");
	return (0);
}
