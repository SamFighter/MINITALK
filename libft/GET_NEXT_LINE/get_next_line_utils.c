/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:31:13 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/05 09:36:42 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/get_next_line.h"

char	*gnl_strjoin(char *s1, char const *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*str;

	i = 0;
	len_s1 = gnl_strlen(s1);
	len_s2 = gnl_strlen(s2);
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	while (len_s1 != 0 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (len_s2 != 0 && s2[i])
	{
		str[len_s1 + i] = s2[i];
		i++;
	}
	str[len_s1 + len_s2] = 0;
	free(s1);
	return (str);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	char		*tab;
	size_t		i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tab = malloc(sizeof(char) * (nmemb * size));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		tab[i] = 0;
		i++;
	}
	return ((void *) tab);
}

int	gnl_strlen(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	gnl_isnewline(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
