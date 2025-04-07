/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:45:18 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/31 12:07:47 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

int	ft_putnbr(int n)
{
	int		len;

	len = len_int(n);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar('-');
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
		}
		n = n % 10;
		ft_putchar(n + '0');
	}
	return (len);
}
