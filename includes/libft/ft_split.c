/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:58:56 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/01/30 20:14:41 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	count_of_elems(char const *str, char c)
{
	int	inside_elem;
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		inside_elem = 0;
		while (str[i] && str[i] == c)
			++i;
		while (str[i] && str[i] != c)
		{
			if (!inside_elem)
			{
				++count;
				inside_elem = 1;
			}
			++i;
		}
	}
	return (count);
}

static int	safe_malloc(char **splited_str,	int pos, size_t len)
{
	int	i;

	i = 0;
	splited_str[pos] = malloc(len);
	if (!splited_str[pos])
	{
		while (i < pos)
		{
			free(splited_str[i]);
			++i;
		}
		free(splited_str);
		return (1);
	}
	return (0);
}

static int	fill(char **splited_str, const char *str, char delimeter)
{
	int		j;
	size_t	elem_len;

	j = 0;
	while (*str)
	{
		elem_len = 0;
		while (*str && *str == delimeter)
			++str;
		while (*str && *str != delimeter)
		{
			++elem_len;
			++str;
		}
		if (elem_len)
		{
			if (safe_malloc(splited_str, j, elem_len + 1))
				return (1);
			ft_strlcpy(splited_str[j], str - elem_len, elem_len + 1);
			++j;
		}
	}
	return (0);
}

char	**ft_split(char const *str, char c)
{
	int		res_len;
	char	**result;

	if (!str)
		return (NULL);
	res_len = count_of_elems(str, c);
	result = malloc((res_len + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[res_len] = NULL;
	if (res_len == 0)
		return (result);
	if (fill(result, str, c))
		return (NULL);
	return (result);
}
