/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:51:43 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/03/24 15:51:43 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

// Function to close window when 'X' button is clicked
int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

// Function to close window when ESC key is pressed
int	handle_key(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY) // 65307 = ESC key in X11
		close_window(vars);
	return (0);
}
