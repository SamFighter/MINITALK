/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:45:28 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/27 11:50:08 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		beg;
	int		end;
	char	*str;

	i = 0;
	beg = 0;
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	end = ft_strlen(s1) - 1;
	while (beg < end && ft_strchr(set, s1[end]))
		end--;
	str = malloc(sizeof(char) * (end - beg + 2));
	if (!str)
		return (NULL);
	while (beg <= end)
	{
		str[i] = s1[beg];
		i++;
		beg++;
	}
	str[i] = 0;
	return (str);
}
