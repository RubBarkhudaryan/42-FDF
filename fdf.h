/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/03/24 14:44:31 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/03/24 14:44:31 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define WIDTH 1920
# define HEIGHT 1080

# include "./includes/gnl/get_next_line.h"
# include "./includes/libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct fdf
{
	int		rows;
	int		cols;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		**color;
	int		**matrix;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
}	t_fdf;

typedef struct line
{
	char	*str;
	char	**split;
}	t_line;

typedef struct point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

/* file manipulating functions */
int	file_length(char *file_path);
int	is_valid_file(char *str);
t_fdf	*parse_map(char *file_path);

/* parser helper functions */
void	free_matrix(int ***matrix, int target_ind);
void	free_split(char ***split);
int		row_len(char **split);
void	throw_error(int error_status);

/* drawing functions */
void	draw_line(t_point *pt1, t_point *pt2, t_fdf *data);
void	draw(t_fdf *data);
void	slope_less_than_one(t_point *delta, t_point *a, t_fdf *data);
void	slope_bigger_than_one(t_point *delta, t_point *a, t_fdf *data);

#endif