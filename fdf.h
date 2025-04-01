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

typedef struct fdf
{
	int		rows;
	int		cols;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		**matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

typedef struct line
{
	char	*str;
	char	**split;
}	t_line;

/* file manipulating functions */
int		file_length(char *file_path);
int		is_valid_file(char *str);
t_fdf	*parse_map(char *file_path);

/* parser helper functions */
void	free_matrix(int ***matrix, int target_ind);
void	free_split(char **split);
int		row_len(char **split);
void	throw_error(int error_status);

/* drawing functions */
void	draw_line(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);

#endif