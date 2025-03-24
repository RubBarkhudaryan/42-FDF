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

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#include "./mlx/mlx.h"
#include "./includes/gnl/get_next_line.h"
// #include "./includes/libft/libft.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int	close_window(t_vars *vars);
int	handle_key(int keycode, t_vars *vars);

#endif 