/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:18:44 by salabbe           #+#    #+#             */
/*   Updated: 2024/10/30 16:58:37 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//\\=========================LIBRARY=========================//

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//\\=======================FUNCTION=========================//

int		ft_putnbr_hexa_low(unsigned long nb);
int		ft_putnbr_hexa_up(unsigned long nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_printf(const	char *str, ...);
int		ft_putstr(const char *str);
int		ft_putchar(const char c);
int		ft_printadd(void *ptr);
int		ft_putnbr(int n);

#endif