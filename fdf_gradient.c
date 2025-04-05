/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_gradient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:15:14 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/05 15:15:14 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static int	interpolate(int start, int end, float t)
{
	return ((int)((1 - t) * start + t * end));
}

int	get_color(int z, int z_min, int z_max)
{
	float	frac;

	if (z_max == z_min)
		frac = 0.0f;
	else
		frac = (float)(z - z_min) / (z_max - z_min);
	return (interpolate_color(LOW_COLOR, HIGH_COLOR, frac));
}

int	interpolate_color(int s_color, int e_color, float fraction)
{
	int	r;
	int	g;
	int	b;

	r = interpolate((s_color >> 16) & 0xFF, (e_color >> 16) & 0xFF, fraction);
	g = interpolate((s_color >> 8) & 0xFF, (e_color >> 8) & 0xFF, fraction);
	b = interpolate(s_color & 0xFF, e_color & 0xFF, fraction);
	return ((r << 16) | (g << 8) | b);
}
