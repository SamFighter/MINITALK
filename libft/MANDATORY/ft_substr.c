/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:30:11 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/27 11:50:15 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	unsigned int	size;

	i = 0;
	size = ft_strlen(s);
	if (start > size || s == 0)
	{
		str = malloc(1);
		str[0] = 0;
		return (str);
	}
	if (len > (size - start))
		len = size - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i != len && start < size)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
