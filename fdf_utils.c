/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:03:32 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/03/25 20:03:32 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"


void	free_matrix(int **matrix, int target_ind)
{
	int i;

	i = 0;
	while (i < target_ind)
		free(matrix[i]);
	free(matrix);
}



int	matrix_len(char **str)
{
	int	i;

	i = 0;
	while (ft_strcmp(*str, "") != 0)
	{
		i++;
		++str;
	}
	return (i);
}

void	throw_error(int error_status)
{
	if (error_status == -1)
	{
		perror("Memory allocation for matrix failed - main program exited with status -1");
		exit(-1);
	}
	else if (error_status == -3)
	{
		perror("Memory allocation for matrix[i] failed - main program exited with status -2");
		exit(-2);
	}
	else if (error_status == 1)
	{
		perror("Failed to open the file. - exit status 1");
		exit(1);
	}
	else if (error_status == 2)
	{
		perror("Wrong arguments count. - exit status 2");
		exit(2);
	}
}
