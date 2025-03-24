/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:58:20 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/03/24 23:58:20 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i] || str2[j])
	{
		if (str1[i] != str2[j])
			return (str1[i] - str2[j]);
		++i;
		++j;
	}
	return (0);
}
