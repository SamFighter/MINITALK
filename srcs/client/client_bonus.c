/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:50:46 by salabbe           #+#    #+#             */
/*   Updated: 2025/04/17 17:40:40 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_bonus.h"

void	reception_sig(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("We recieved the mail captain\n");
	else
		ft_printf("Mail get swallowed by a blackhole\n");
}

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
	int					pid;
	int					i;
	struct sigaction	newsig;

	newsig.sa_handler = &reception_sig;
	sigemptyset(&newsig.sa_mask);
	newsig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &newsig, NULL);
	sigaction(SIGUSR2, &newsig, NULL);
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
			send_char(pid, av[2][i++]);
		send_char(pid, av[2][i]);
	}
	else
		ft_printf("Error in number of argument\n");
	return (0);
}
