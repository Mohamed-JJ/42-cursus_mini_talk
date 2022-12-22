/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:26:43 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/22 19:02:50 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig)
{
	static char	c = 0b11111111;
	static int	e;

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

	pid = getpid();
	var.sa_handler = ft_handler;
	mini_printf("this is the process id --> ", pid, '\n');
	while (1)
	{
		sigaction(SIGUSR1, &var, NULL);
		sigaction(SIGUSR2, &var, NULL);
		pause();
	}
	return (0);
}
