#include "fdf.h"

fdf	parse_map(char *file_path)
{
	int		fd;
	fdf		obj;
	line	ln;

	fd = open(file_path, O_RDONLY);
	obj.rows = file_length(file_path);
	obj.matrix = (int **)malloc(sizeof(int *) * obj.rows);
	if (!obj.matrix)
	{
		obj.matrix = NULL;
		return (obj);
	}

	ln.str = get_next_line(fd);
	char	**temp = ft_split(ln.str, ' ');
	obj.cols = matrix_len(temp);

	int i = 0;
	int j = 0;

	while (ln.str)
	{
		j = 0;

		ln.split = ft_split(ln.str, ' ');
		obj.matrix[i] = (int *)malloc(sizeof(int) * obj.cols);

		if (!ln.split)
		{
			printf("split crashed");
			free_matrix(obj.matrix, i);
			obj.matrix = NULL;
			return (obj);
		}

		while (ln.split[j] && j < obj.cols)
		{
			obj.matrix[i][j] = ft_atoi(ln.split[j]);
			++j;
		}

		free_split(ln.split);
		free(ln.str);

		++i;
		ln.str = get_next_line(fd);

		if (!ln.str || !*ln.str)
		{
			free(ln.str);
			continue;
		}
	}
	close(fd);
	return (obj);
}

