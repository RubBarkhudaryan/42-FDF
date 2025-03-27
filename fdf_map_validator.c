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

int	file_length(int fd)
{
	int		len;
	char	*str;

	len = 0;
	str = get_next_line(fd);
	while (str)
	{
		++len;
		free(str);
		str = get_next_line(fd);
	}
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
	if (file_length(fd) > 0)
		return (1);
	return (0);
}
