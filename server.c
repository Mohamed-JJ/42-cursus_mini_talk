/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:26:43 by mjarboua          #+#    #+#             */
/*   Updated: 2023/03/30 15:20:32 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_p_id;

static void	ft_handler(int sig, siginfo_t *t, void *v)
{
	static char	c = 0b11111111;
	static int	e;

	(void)v;
	if (g_p_id != t->si_pid)
	{
		g_p_id = 0;
		e = 0;
		c = 0b11111111;
	}
	g_p_id = t->si_pid;
	c = c ^ 128 >> e;
	if (sig == SIGUSR1)
		c = c | 128 >> e;
	e++;
	if (e == 8)
	{
		write(1, &c, 1);
		e = 0;
		c = 0b11111111;
	}
}

int	main(void)
{
	struct sigaction	var;

	g_p_id = getpid();
	var.sa_flags = SA_SIGINFO;
	var.sa_sigaction = &ft_handler;
	mini_printf("this is the process id --> ", g_p_id, '\n');
	sigaction(SIGUSR1, &var, NULL);
	sigaction(SIGUSR2, &var, NULL);
	while (1)
		pause();
	return (0);
}
