/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:18:59 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/03/25 00:18:59 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	file_length(char *file_path)
{
	int		fd;
	int		len;
	char	*str;

	len = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &str))
	{
		++len;
		free(str);
	}
	close(fd);
	return (len);
}

int	is_valid_file(char *str)
{
	int	fd;

	if (!(ft_strlen(str) > 4 && \
	ft_strcmp(str + (ft_strlen(str) - 4), ".fdf") == 0))
		return (0);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (close(fd), 0);
	if (file_length(str) > 0)
		return (close(fd), 1);
	return (close(fd), 0);
}
