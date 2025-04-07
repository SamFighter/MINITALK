/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:15:54 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/27 11:49:55 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	count;

	i = 0;
	count = -1;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			count = i;
		i++;
	}
	if (s[i] == (unsigned char) c)
		count = i;
	if (count < 0)
		return (NULL);
	return ((char *)&s[count]);
}
