/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:07:01 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/07 01:07:01 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_point	rotate_z(t_point *pt, double angle)
{
	t_point	res;

	res.x = pt->x * cos(angle) - pt->y * sin(angle);
	res.y = pt->x * sin(angle) + pt->y * cos(angle);
	res.z = pt->z;
	res.color = pt->color;
	return (res);
}

t_point	rotate_y(t_point *pt, double angle)
{
	t_point	res;

	res.x = pt->x * cos(angle) + pt->z * sin(angle);
	res.z = pt->z * cos(angle) - pt->x * sin(angle);
	res.y = pt->y;
	res.color = pt->color;
	return (res);
}

t_point	rotate_x(t_point *pt, double angle)
{
	t_point	res;

	res.x = pt->x;
	res.y = pt->y * cos(angle) - pt->z * sin(angle);
	res.z = pt->y * sin(angle) + pt->z * cos(angle);
	res.color = pt->color;
	return (res);
}

void	rotate_point(t_point *point, t_fdf *data)
{
	point->x -= WIDTH / 2;
	point->y -= HEIGHT / 2;
	point->z -= (data->z_max + data->z_min) / 2;
	if (data->alpha != 0.0)
		*point = rotate_x(point, data->alpha);
	if (data->theta != 0.0)
		*point = rotate_y(point, data->theta);
	if (data->gamma != 0.0)
		*point = rotate_z(point, data->gamma);
	point->x += WIDTH / 2;
	point->y += HEIGHT / 2;
	point->z += (data->z_max + data->z_min) / 2;
}
