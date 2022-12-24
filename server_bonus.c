/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:26:43 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/23 17:07:30 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *sa, void *ptr)
{
	static char	c = 0b11111111;
	static int	e;
	static int	pid;

	(void)ptr;
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
			kill(pid, SIGUSR1);
		ft_putc(c);
		e = 0;
		c = 0b11111111;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;
	int					c_pid;

	pid = getpid();
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SIGINFO;
	mini_printf("this is the process id --> ", pid, '\n');
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
