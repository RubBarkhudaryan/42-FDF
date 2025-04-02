/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:12:38 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/03 03:48:45 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static int	end_session(t_fdf *data)
{
	if (!data)
		return (0);
	if (data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_matrix(&(data->matrix), data->rows);
	free(data);
	return (0);
}

static int	close_window(t_fdf *data)
{
	end_session(data);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	deal_key(int key, t_fdf *data)
{
	if (key == 65362 || key == 119)
		data->shift_y += 10;
	else if (key == 65364 || key == 115)
		data->shift_y -= 10;
	else if (key == 65361 || key == 97)
		data->shift_x += 10;
	else if (key == 65363 || key == 100)
		data->shift_x -= 10;
	else if (key == 65307)
		close_window(data);
	else if (key == 122 && data->zoom < 100)
		data->zoom += 5;
	else if (key == 120 && data->zoom > -100)
		data->zoom -= 5;
	else
		return (0);
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img_data = mlx_get_data_addr(data->img, &data->bpp, &data->size_line, &data->endian);
	draw(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fdf	*data;

	if (argc == 2)
	{
		data = parse_map(argv[1]);
		if (!data)
		{
			throw_error(-1);
			return(EXIT_FAILURE);
		}
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, argv[1]);
		data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		data->img_data = mlx_get_data_addr(data->img, &data->bpp, &data->size_line, &data->endian);
		data->zoom = 1;
		data->shift_x = WIDTH / 2;
		data->shift_y = HEIGHT / 4;
		draw(data);
		mlx_hook(data->win_ptr, 2, 1L << 0, deal_key, data);
		mlx_hook(data->win_ptr, 17, 1L << 0, close_window, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		throw_error(2);
	return (0);
}
