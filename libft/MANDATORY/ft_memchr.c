/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:54:38 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/27 11:47:29 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mem;

	i = 0;
	mem = (unsigned char *) s;
	while (i < n && mem[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	if (mem[i] == (unsigned char)c)
		return (mem + i);
	return (NULL);
}
