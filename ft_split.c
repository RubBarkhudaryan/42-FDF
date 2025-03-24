/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:44:51 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/03/25 00:44:51 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static int	ft_inset(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static int	words_count(const char *str)
{
	int	i;
	int	inside_token;
	int	count;

	i = 0;
	inside_token = 0;
	count = 0;
	while (str[i])
	{
		if (ft_inset(" \t\n", str[i]))
		{
			if (inside_token)
				inside_token = 0;
		}
		if (!ft_inset(" \t\n", str[i]) && !inside_token)
		{
			inside_token = 1;
			++count;
		}
		++i;
	}
	return (count);
}

static int	fill(char **res, const char *str, int len, int ind)
{
	int	i;

	i = 0;
	res[ind] = (char *)malloc(len + 1);
	if (!res[ind])
	{
		while (i < ind)
		{
			free(res[i]);
			++i;
		}
		free(res);
		res = NULL;
		return (0);
	}
	while (i < len)
	{
		res[ind][i] = *str;
		++str;
		++i;
	}
	res[ind][i] = '\0';
	return (1);
}

char	**ft_split(const char *str)
{
	char	**res;
	int		i;
	int		j;
	int		ind;

	i = 0;
	j = 0;
	ind = 0;
	res = (char **)malloc(sizeof(char *) * (words_count(str) + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		while (ft_inset(" \n\t", str[i]) && str[i])
			++i;
		j = i;
		while (str[i] && !ft_inset(" \n\t", str[i]))
			++i;
		if (!fill(res, str + j, (i - j), ind++))
			return (NULL);
	}
	res[ind] = NULL;
	return (res);
}
