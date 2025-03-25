/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:58:20 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/03/24 23:58:20 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (str1[i] || str2[j])
	{
		if (str1[i] != str2[j])
		return (str1[i] - str2[j]);
		++i;
		++j;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	return (res * sign);
}

static int	safe_malloc(int **res, )
{

}

int	**generate_matrix(int fd)
{
	int		i;
	int		j;
	int		**matrix;
	int		rows_count;
	char	**map_line;

	i = 0;
	j = 0;
	rows_count = file_length(fd);
	matrix = (int **)malloc(sizeof(int *) * rows_count);
	if (!matrix)
	{
		perror("Map memory allocation failed.");
		return (NULL);
	}
	map_line = ft_split(get_next_line(fd));
	while (map_line[i])
	{
		
	}
}
