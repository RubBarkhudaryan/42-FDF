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

int	get_color(int z, int z_min, int z_max, t_fdf *dt)
{
	float	frac;

	if (z_max == z_min)
		frac = 0.0f;
	else
		frac = (float)(z - z_min) / (z_max - z_min);
	return (interpolate_color(dt->low_color, dt->high_color, frac));
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

double	pseudo_rand(float seed)
{
	double	r;

	seed = sin(seed) * 1000000;
	r = seed - floor(seed);
	return (r);
}

int	pseudo_random_color(float seed)
{
	int	r;
	int	g;
	int	b;

	r = (int)(pseudo_rand(seed) * 256);
	if (r < 64)
		r += 64;
	g = (int)(pseudo_rand(seed + 1) * 256);
	if (g < 64)
		g += 64;
	b = (int)(pseudo_rand(seed + 2) * 256);
	if (b < 64)
		b += 64;
	return (r << 16 | g << 8 | b);
}
