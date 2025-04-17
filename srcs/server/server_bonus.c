/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:50:50 by salabbe           #+#    #+#             */
/*   Updated: 2025/04/17 17:52:44 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_bonus.h"

char	*char_paste_to_str(char const *str, char c)
{
	char				*result;
	unsigned long		len;
	int					i;
	int					j;

	i = 0;
	j = 0;
	if (!str || !c)
		return (0);
	len = ft_strlen(str) + 1;
	result = ft_calloc(sizeof(char *), len + 1);
	if (!result)
		return (0);
	while (str[i])
		result[j++] = str[i++];
	result[j++] = c;
	result[j] = 0;
	free((char *) str);
	return (result);
}

char	*init_str(char *str)
{
	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (0);
		*str = 0;
	}
	return (str);
}

void	get_signal(int signal, siginfo_t *siginfo, void *s)
{
	static char					*str;
	static int					i;
	static unsigned char		c;

	(void)s;
	str = init_str(str);
	c |= (signal == SIGUSR1);
	if ((++i) == 8)
	{
		if (c == 0)
		{
			ft_printf("%s", str);
			free(str);
			str = 0;
			kill(siginfo->si_pid, SIGUSR1);
		}
		else
			str = char_paste_to_str(str, c);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sig;
	
	ft_printf("Server PID : %d\n", getpid());
	sig.sa_sigaction = get_signal;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
