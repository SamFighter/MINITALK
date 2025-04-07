/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:41:38 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/27 11:49:48 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (i < n && s1[i])
	{
		j = 0;
		while (s1[i + j] && s2[j] && s2[j] == s1[i + j] && (i + j) < n)
		{
			if (s2[j + 1] == '\0')
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
