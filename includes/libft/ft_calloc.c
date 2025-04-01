/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:49:05 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/01 18:03:13 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memset(void *buff, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) buff;
	while (len--)
		ptr[len] = (unsigned char) c;
	return (buff);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr)
		ft_memset(ptr, 0, total_size);
	return (ptr);
}