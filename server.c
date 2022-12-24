/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:26:43 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/23 17:06:51 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *t, void *v)
{
	static char	c = 0b11111111;
	static int	e;
	static int	pid;

	(void)v;
	if (pid != t->si_pid)
	{
		pid = 0;
		e = 0;
		c = 0b11111111;
	}
	pid = t->si_pid;
	if (sig == SIGUSR1)
		c = c | 128 >> e;
	else
		c = c ^ 128 >> e;
	e++;
	if (e == 8)
	{
		ft_putc(c);
		e = 0;
		c = 0b11111111;
	}
}

int	main(void)
{
	struct sigaction	var;
	int					pid;
	siginfo_t			info;

	pid = getpid();
	var.__sigaction_u.__sa_sigaction = &ft_handler;
	mini_printf("this is the process id --> ", pid, '\n');
	while (1)
	{
		sigaction(SIGUSR1, &var, NULL);
		sigaction(SIGUSR2, &var, NULL);
		pause();
	}
	return (0);
}
