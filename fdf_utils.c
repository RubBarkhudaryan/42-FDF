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

void	free_matrix(int ***matrix, int target_ind)
{
	int	i;

	if (!matrix || !(*matrix))
		return ;
	i = 0;
	while (i < target_ind)
	{
		free((*matrix)[i]);
		++i;
	}
	free(*matrix);
	*matrix = NULL;
}

void	free_split(char ***split)
{
	int	i;

	if (!*split)
		return ;
	i = 0;
	while ((*split)[i])
	{
		free((*split)[i]);
		++i;
	}
	free(*split);
}

int	row_len(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && ft_strcmp(str[i], "\n") != 0)
		i++;
	return (i);
}

void	throw_error(int error_status)
{
	if (error_status == -1)
		perror("Memory allocation for matrix\
			 failed - main program exited with status -1");
	else if (error_status == -2)
		perror("Memory allocation for matrix[i]\
			 failed - main program exited with status -2");
	else if (error_status == 1)
		perror("Failed to open the file. - exit status 1");
	else if (error_status == 2)
	{
		perror("Wrong arguments. - exit status 2");
		perror("Make sure that:\n1. The given file's permissons are ok,\n\
2. Extension is *.fdf and the file exists in the given destination,\n\
3. Also check that the program will take 2 arguments: program\
 name and the map file destination");
	}
	else if (error_status == 3)
		perror("Ivalid map given - exit status 3");
	exit(EXIT_FAILURE);
}
