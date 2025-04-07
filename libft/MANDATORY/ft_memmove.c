/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:12 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/27 11:47:54 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

void	*ft_memmove( void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*mem1;
	unsigned char	*mem2;

	i = 0;
	mem1 = (unsigned char *) dest;
	mem2 = (unsigned char *) src;
	if (dest > src)
	{
		while (n > i)
		{
			mem1[n - 1] = mem2[n - 1];
			n--;
		}
	}
	else if (dest <= src)
	{
		ft_memcpy(mem1, mem2, n);
	}
	return (dest);
}
