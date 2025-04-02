/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:04:54 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/02 20:18:01 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static void	isometric(int *x, int *y, int z)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(0.523599);
	*y = (tmp_x + tmp_y) * sin(0.523599) - z;
}

void	slope_less_than_one(t_point *delta, t_point *start, t_fdf *data)
{
	int		p;
	int		i;
	t_point	current;

	current = *start;
	p = 2 * abs(delta->y) - abs(delta->x);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
		current.x, current.y, 0xffffff);
	i = 0;
	while (i < abs(delta->x))
	{
		if (delta->x > 0)
			current.x += 1;
		else
			current.x -= 1;
		if (p < 0)
			p += 2 * abs(delta->y);
		else
		{
			if (delta->y > 0)
				current.y += 1;
			else
			current.y -= 1;
			p += 2 * abs(delta->y) - 2 * abs(delta->x);
		}
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			current.x, current.y, 0xffffff);
		i++;
	}
}

void	slope_bigger_than_one(t_point *delta, t_point *start, t_fdf *data)
{
	int		p;
	int		i;
	t_point	current;

	current = *start;
	p = 2 * abs(delta->x) - abs(delta->y);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
		current.x, current.y, 0xffff);
	i = 0;
	while (i < abs(delta->y))
	{
		if (delta->y > 0)
			current.y += 1;
		else
			current.y -= 1;
		if (p < 0)
			p += 2 * abs(delta->x);
		else
		{
			current.x += (delta->x > 0) ? 1 : -1;
			p += 2 * abs(delta->x) - 2 * abs(delta->y);
		}
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			current.x, current.y, 0xffff);
		i++;
	}
}

void	draw_line(t_point *pt1, t_point *pt2, t_fdf *data)
{
	t_point	tmp1;
	t_point	tmp2;
	t_point	delta;

	tmp1 = *pt1;
	tmp2 = *pt2;
	tmp1.z = data->matrix[tmp1.y][tmp1.x] * data->zoom;
	tmp2.z = data->matrix[tmp2.y][tmp2.x] * data->zoom;
	tmp1.x *= data->zoom;
	tmp1.y *= data->zoom;
	tmp2.x *= data->zoom;
	tmp2.y *= data->zoom;
	tmp1.x += data->shift_x;
	tmp1.y += data->shift_y;
	tmp2.x += data->shift_x;
	tmp2.y += data->shift_y;
	isometric(&tmp1.x, &tmp1.y, tmp1.z);
	isometric(&tmp2.x, &tmp2.y, tmp2.z);
	delta.x = tmp2.x - tmp1.x;
	delta.y = tmp2.y - tmp1.y;
	if (abs(delta.x) > abs(delta.y))
		slope_less_than_one(&delta, &tmp1, data);
	else
		slope_bigger_than_one(&delta, &tmp1, data);
}

void draw(t_fdf *data)
{
	t_point	pt1;
	t_point	pt2;

	pt1.y = 0;
	while (pt1.y < data->rows)
	{
		pt1.x = 0;
		while (pt1.x < data->cols)
		{
			if (pt1.x < data->cols - 1)
			{
				pt2.x = pt1.x + 1;
				pt2.y = pt1.y;
				draw_line(&pt1, &pt2, data);
			}
			if (pt1.y < data->rows - 1)
			{
				pt2.x = pt1.x;
				pt2.y = pt1.y + 1;
				draw_line(&pt1, &pt2, data);
			}
			pt1.x++;
		}
		pt1.y++;
	}
}
