/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:12:38 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/03/30 22:07:44 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int main(int argc, char *argv[])
{
	fdf	obj;

	if (argc == 2)
	{
		obj = parse_map(argv[1]);
		if (!obj.matrix)
			return (0);
		for(int i = 0; i < obj.rows; ++i)
		{
			for (int j = 0; j < obj.cols; ++j)
			{
				printf("%d, ", obj.matrix[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("Wrong args");
}