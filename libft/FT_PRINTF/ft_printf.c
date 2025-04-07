/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:27:49 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/04 14:25:13 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"
#include "../INCLUDES/libft.h"

static int	get_info(char c, int len, va_list arg)
{
	if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (c == 'x')
		len += ft_putnbr_hexa_low(va_arg(arg, unsigned int));
	else if (c == 'X')
		len += ft_putnbr_hexa_up(va_arg(arg, unsigned int));
	else if (c == '%')
		len += ft_putchar('%');
	else if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		len += ft_printadd(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else
	{
		len += ft_putchar ('%');
		len += ft_putchar(c);
	}
	return (len);
}

int	ft_printf(const	char *str, ...)
{
	va_list		arg;
	int			i;
	int			len;

	va_start(arg, str);
	i = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		else
		{
			len = get_info(str[i + 1], len, arg);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
