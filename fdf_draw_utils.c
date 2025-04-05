/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:12:53 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/06 00:47:54 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static void	check_x_y(int *delta_elem, int *elem)
{
	if (*delta_elem > 0)
		*elem += 1;
	else
		*elem -= 1;
}

static void	put_pixel_to_image(t_fdf *data, t_point *point)
{
	char	*dst;
	int		bytes_per_pixel;

	if (!data->img_dt)
		return ;
	if (point->x < 0 || point->x >= WIDTH || point->y < 0 || point->y >= HEIGHT)
		return ;
	bytes_per_pixel = data->bpp / 8;
	dst = data->img_dt + (point->y * data->sz_ln + point->x * bytes_per_pixel);
	*(unsigned int *)dst = point->color;
}

void	slope_less_than_one(t_point *delta, t_point *st, t_fdf *dt, t_clr c)
{
	int		p;
	int		i;
	float	frac;

	p = 2 * abs(delta->y) - abs(delta->x);
	i = 0;
	while (i < abs(delta->x))
	{
		frac = 0.0;
		if (abs(delta->x) != 0)
			frac = ((float) i / (float) abs(delta->x));
		st->color = interpolate_color(c.start_color, c.end_color, frac);
		put_pixel_to_image(dt, st);
		check_x_y(&delta->x, &st->x);
		if (p < 0)
			p += 2 * abs(delta->y);
		else
		{
			check_x_y(&delta->y, &st->y);
			p += 2 * abs(delta->y) - 2 * abs(delta->x);
		}
		i++;
	}
}

void	slope_bigger_than_one(t_point *delta, t_point *st, t_fdf *dt, t_clr c)
{
	int		p;
	int		i;
	float	frac;

	p = 2 * abs(delta->x) - abs(delta->y);
	i = 0;
	while (i < abs(delta->y))
	{
		frac = 0.0;
		if (abs(delta->y) != 0)
			frac = (float) i / (float) abs(delta->y);
		st->color = interpolate_color(c.start_color, c.end_color, frac);
		put_pixel_to_image(dt, st);
		check_x_y(&delta->y, &st->y);
		if (p < 0)
			p += 2 * abs(delta->x);
		else
		{
			check_x_y(&delta->x, &st->x);
			p += 2 * abs(delta->x) - 2 * abs(delta->y);
		}
		i++;
	}
}
