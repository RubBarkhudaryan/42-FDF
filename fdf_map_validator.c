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
	int		len;
	char	*str;
	int		fd;

	len = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		++len;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (len);
}

int	is_valid_file(const char *str)
{
	int	fd;

	if (!(ft_strlen(str) > 4 && \
	ft_strcmp(str + (ft_strlen(str) - 4), ".fdf") == 0))
		return (0);
	fd = open(str, O_RDONLY);
	if (!fd)
		return (0);
	if (file_length((char *)str) > 1)
		return (1);
	return (0);
}
