/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:19:15 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/03/25 00:19:15 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	main(int argc, char *argv[])
{
	int		fd;

	if (argc == 2)
	{
		if (is_valid_file(argv[1]))
		{
			fd = open(argv[1], O_RDONLY);
			if (!fd)
				perror("Failed to open the file.");
		}
	}
	else
		perror("Wrong arguments count.");
	return (0);
}
