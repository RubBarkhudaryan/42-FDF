/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:10:10 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/03/24 15:10:10 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		char *str;
		while ((str = get_next_line(fd)))
		{
			printf("%s", str);
			free(str);
		}
	}
	else
		printf("Arguments count is wrong");
	return 0;
}
