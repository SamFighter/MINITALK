/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:38:21 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/27 11:47:46 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*beg;
	unsigned char	*end;

	i = 0;
	if (dest == 0)
		return (NULL);
	beg = (unsigned char *) src;
	end = (unsigned char *) dest;
	while (i != n)
	{
		end[i] = beg[i];
		i++;
	}
	return (dest);
}
