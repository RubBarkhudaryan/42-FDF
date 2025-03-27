/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:44:31 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/03/24 14:44:31 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define ESC_KEY 65307

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "./mlx/mlx.h"
# include "./includes/gnl/get_next_line.h"
# include "./includes/libft/libft.h"

typedef struct fdf_
{
	int	rows;
	int	cols;
	int	**matrix;
} fdf;


//file operationing functions
int		file_length(int fd);
int		is_valid_file(const char *str);


//fdf utlis
void	free_matrix(int **matrix, int target_ind);
void	throw_error(int error_status);
void	free_split(char **split);
int		matrix_len(char **str);


#endif