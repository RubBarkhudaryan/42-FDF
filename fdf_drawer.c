/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:49:15 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/01 18:49:15 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"


static void	isometric(float *x, float *y, int z)
{
	float original_x = *x;
	float original_y = *y;

	*x = (original_x - original_y) * cos(0.78);
	*y = (original_x + original_y) * sin(0.78) - z;
}

void	draw_line(t_point pt1, t_point pt2, t_fdf *data)
{
	float x_step = 0;
	float y_step = 0;
	float max = 0;
	int z;
	int z1;

	z = data->matrix[(int)y][(int)x];
	z1 = data->matrix[(int)y1][(int)x1];

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	if (z > 0 || z1 > 0)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;

	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

	x_step = x1 - x;
	y_step = y1 - y;

	max = fmax(fabs(x_step), fabs(y_step));

	x_step /= max;
	y_step /= max;

	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			if (x < data->cols - 1)
				draw_line(x, y, x + 1, y, data);
			if (y < data->rows - 1)
				draw_line(x, y, x, y + 1, data);
			++x;
		}
		++y;
	}
}
