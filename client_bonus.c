/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:52:56 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/22 23:08:02 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig)
{
	(void)sig;
	write(1, "received", 8);
}

void	ft_send_zero(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		i++;
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	ft_sender(char *str, int pid)
{
	int		i;
	int		e;
	char	c;

	e = 0;
	while (str[e])
	{
		i = 0;
		while (i < 8)
		{
			if ((str[e] & 128 >> i) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(150);
		}
		e++;
		usleep(150);
	}
	ft_send_zero(pid);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3)
		return (ft_puts("not enough arguments"), 0);
	// printf("\n%d\n", getpid());
	signal(SIGUSR1, ft_handler);
	ft_sender(av[2], atoi(av[1]));
	usleep(200);
}
