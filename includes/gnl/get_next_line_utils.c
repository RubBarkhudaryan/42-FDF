/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:41:16 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/02/14 23:41:16 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		ind;

	if (!str)
		return (NULL);
	ind = 0;
	dup = (char *)malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	while (str[ind])
	{
		dup[ind] = str[ind];
		++ind;
	}
	dup[ind] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		++str;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		return (ft_substr(str2, 0, ft_strlen(str2)));
	if (!str2)
		return (ft_substr(str1, 0, ft_strlen(str1)));
	new_str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (str1[++i])
		new_str[i] = str1[i];
	j = -1;
	while (str2[++j])
		new_str[i + j] = str2[j];
	new_str[i + j] = '\0';
	return (free(str1), new_str);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;
	size_t	i;

	i = 0;
	strlen = ft_strlen(str);
	if (start > strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		len = strlen - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len && str[start + i])
	{
		substr[i] = str[start + i];
		++i;
	}
	substr[i] = '\0';
	return (substr);
}
