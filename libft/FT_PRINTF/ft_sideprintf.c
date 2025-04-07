/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sideprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:18:05 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/27 11:51:06 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_printadd(void *ptr)
{
	unsigned long	add;
	int				len;

	add = (unsigned long) ptr;
	len = 0;
	if (ptr == NULL)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	len += ft_putnbr_hexa_low(add);
	return (len);
}

int	ft_putnbr_hexa_low(unsigned long nb)
{
	int		len;
	char	hexc;

	len = 0;
	if (nb > 15)
		len += ft_putnbr_hexa_low(nb / 16);
	hexc = "0123456789abcdef"[nb % 16];
	write(1, &hexc, 1);
	len += 1;
	return (len);
}

int	ft_putnbr_hexa_up(unsigned long nb)
{
	int		len;
	char	hexc;

	len = 0;
	if (nb > 15)
		len += ft_putnbr_hexa_up(nb / 16);
	hexc = "0123456789ABCDEF"[nb % 16];
	write(1, &hexc, 1);
	len += 1;
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
		len += ft_putnbr_unsigned(nb / 10);
	len += ft_putchar((nb % 10) + 48);
	return (len);
}
