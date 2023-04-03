/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:52:56 by mjarboua          #+#    #+#             */
/*   Updated: 2023/04/03 15:42:07 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handler(int sig)
{
	(void)sig;
	write(1, "received", 8);
	exit(0);
}

void	ft_send_zero(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		i++;
		kill(pid, SIGUSR2);
		usleep(800);
	}
}

void	ft_sender(char *str, int pid)
{
	int		i;
	int		e;

	e = 0;
	while (str[e])
	{
		i = 0;
		while (i < 8)
		{
			if ((str[e] & 128 >> i) == 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i++;
			usleep(600);
		}
		e++;
		usleep(200);
	}
	ft_send_zero(pid);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3)
		return (ft_puts("not enough arguments"), 0);
	sa.__sigaction_u.__sa_handler = ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	ft_sender(av[2], ft_atoi(av[1]));
	pause();
	return (0);
}
