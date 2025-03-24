/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:41:13 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/02/14 23:41:13 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	parse_buff(char **clean_line, char **tmp)
{
	char	*new_line_pos;
	char	*temp;

	new_line_pos = ft_strchr(*tmp, '\n');
	if (new_line_pos)
	{
		if (*clean_line)
			*clean_line = ft_strjoin(*clean_line, \
			ft_substr(*tmp, 0, new_line_pos - *tmp + 1));
		else
			*clean_line = ft_substr(*tmp, 0, new_line_pos - *tmp + 1);
		if (*(new_line_pos + 1))
			temp = ft_strdup(new_line_pos + 1);
		else
			temp = NULL;
		free(*tmp);
		*tmp = ft_strdup(temp);
		free (temp);
	}
	else
	{
		*clean_line = ft_strjoin(*clean_line, *tmp);
		free(*tmp);
		*tmp = NULL;
	}
}

static char	*read_line(int fd, char **tmp)
{
	char	*buff;
	int		size;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	size = 1;
	while (!ft_strchr(*tmp, '\n') && size > 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == 0)
			break ;
		if (size < 0)
		{
			free(*tmp);
			free(buff);
			return (NULL);
		}
		buff[size] = '\0';
		*tmp = ft_strjoin(*tmp, buff);
	}
	free(buff);
	return (*tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line = NULL;
	tmp = read_line(fd, &tmp);
	if (!tmp)
		return (NULL);
	parse_buff(&line, &tmp);
	return (line);
}
