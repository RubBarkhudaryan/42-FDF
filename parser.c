#include "fdf.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		char *str = get_next_line(fd);
		int i = 0;
		while (str)
		{
			i = 0;
			char **split = ft_split(str, ' ');
			if (!split)
			{
				printf("split crashed");
				return (0);
			}
			while (split[i])
			{
				printf("%d, ", ft_atoi(split[i]));
				++i;
			}
			printf("\n");
			free_split(split);
			free(str);
			str = get_next_line(fd);
			if (!str || !*str)
			{
				free(str);
				continue;
			}
		}
	}
	
	return (0);
}

