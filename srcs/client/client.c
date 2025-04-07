/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:50:46 by salabbe           #+#    #+#             */
/*   Updated: 2025/04/07 16:38:10 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	send_char(int pid, char c)
{
	unsigned char	tmp;
	int				i;

	i = 8;
	tmp = c;
	while (i > 0)
	{
		i--;
		tmp = c >> i;
		if (tmp % 2 == 1)
			kill(pid, SIGUSR1);
		else 
			kill(pid, SIGUSR2);
		usleep(300);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_printf("Wrong PID\n");
			return (0);
		}
		while (av[2][i])
			send_char(av[2][i++], pid);
		send(av[2][i], pid);
	}
	else
		ft_printf("Error in number of argument\n");
	return (0);
}