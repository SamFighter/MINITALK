/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:19:25 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/27 11:47:37 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*mem1;
	unsigned char	*mem2;

	i = 0;
	mem1 = (unsigned char *) s1;
	mem2 = (unsigned char *) s2;
	while (i < n)
	{
		if (mem1[i] != mem2[i])
			return (mem1[i] - mem2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (0);
}
