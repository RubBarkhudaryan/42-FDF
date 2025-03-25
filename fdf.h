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

//file operationing functions
int		file_length(int fd);
int		is_valid_file(const char *str);

//fdf libft functions
char	**ft_split(const char *str);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif