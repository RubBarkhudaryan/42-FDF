/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:57:27 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/04/01 17:51:56 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

int		ft_atoi(char *str);
int		ft_isdigit(int c);
char	**ft_split(char const *str, char c);
int		ft_strcmp(const char *str1, const char *str2);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
void	*ft_calloc(size_t count, size_t size);

#endif