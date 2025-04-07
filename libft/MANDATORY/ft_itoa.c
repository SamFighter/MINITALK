/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:11:10 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/27 11:47:21 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

static int	len_tab(long n)
{
	int		size;

	size = 1;
	if (n == 0)
		return (size);
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	if (n < 10 && n > 0)
		return (size);
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		i;
	int		size;
	char	*str;

	nbr = n;
	size = len_tab(nbr);
	str = ft_calloc(sizeof(char), size + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	i = size - 1;
	while (nbr > 0)
	{
		str[i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}
