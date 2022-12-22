/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:26:43 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/22 23:52:22 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t	*sa)
{
	static char	c = 0b11111111;
	static int	e;
	static int	pid;

	if (pid != sa->si_pid)
	{
		pid = 0;
		e = 0;
		c = 0b11111111;
	}
	pid = sa->si_pid;
	if (sig == SIGUSR1)
		c = c | 128 >> e;
	else
		c = c ^ 128 >> e;
	e++;

	if (e == 8)
	{
		if (c == '\0')
		{
			kill(pid, SIGUSR1);
			// pid = 0;
			// printf("\n%d\n", pid);
		}
		ft_putc(c);
		e = 0;
		c = 0b11111111;
	}
}

int	main(void)
{
	struct sigaction	var;
	int					pid;
	siginfo_t			sa;
	int					c_pid;

	pid = getpid();
	var.sa_handler = (void *)ft_handler;
	mini_printf("this is the process id --> ", pid, '\n');
	while (1)
	{
		sigaction(SIGUSR1, &var, NULL);
		sigaction(SIGUSR2, &var, NULL);
		pause();
	}
	return (0);
}
