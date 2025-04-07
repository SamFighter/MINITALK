/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:40:17 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/27 11:42:37 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

static int	count_diff(const char *str, char diff)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (0);
	while (str[i] == diff)
		i++;
	while (str[i])
	{
		if (str[i] != diff)
		{
			j++;
			while (str[i] != diff && str[i])
				i++;
		}
		else
			i++;
	}
	return (j);
}

static void	*free_all(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static void	sep_str(const char *s, char c, char **str)
{
	unsigned int	i;
	unsigned int	j;
	int				ping;

	i = 0;
	j = 0;
	ping = -1;
	while (i <= ft_strlen(s))
	{
		if (ping < 0 && s[i] != c)
			ping = i;
		else if ((s[i] == c || s[i] == '\0') && ping >= 0)
		{
			str[j] = ft_substr(s, ping, i - ping);
			if (!str[j])
				free_all(str);
			j++;
			ping = -1;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char				**str;

	if (!s)
		return (NULL);
	str = ft_calloc((count_diff(s, c) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	sep_str(s, c, str);
	return (str);
}
