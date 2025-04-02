/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:12:53 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/02 20:15:28 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static void	put_pixel(t_fdf *data, t_point *point)
{
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->x, point->y, 0xffff);
}

void	slope_less_than_one(t_point *delta, t_point *start, t_fdf *data)
{
	int	p;
	int	i;

	p = 2 * abs(delta->y) - abs(delta->x);
	put_pixel(data, start);
	i = 0;
	while (i < abs(delta->x))
	{
		if (delta->x > 0)
			start->x += 1;
		else
			start->x -= 1;
		if (p < 0)
			p += 2 * abs(delta->y);
		else
		{
			if (delta->y > 0)
				start->y += 1;
			else
				start->y -= 1;
			p += 2 * abs(delta->y) - 2 * abs(delta->x);
		}
		put_pixel(data, start);
		i++;
	}
}

void	slope_bigger_than_one(t_point *delta, t_point *start, t_fdf *data)
{
	int	p;
	int	i;

	p = 2 * abs(delta->x) - abs(delta->y);
	put_pixel(data, start);
	i = 0;
	while (i < abs(delta->y))
	{
		if (delta->y > 0)
			start->y += 1;
		else
			start->y -= 1;
		if (p < 0)
			p += 2 * abs(delta->x);
		else
		{
			if (delta->x > 0)
				start->x += 1;
			else
				start->x -= 1;
			p += 2 * abs(delta->x) - 2 * abs(delta->y);
		}
		put_pixel(data, start);
		i++;
	}
}
