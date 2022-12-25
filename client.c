/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:52:56 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/25 18:20:34 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
		return (ft_puts("not enough arguments"), 0);
	ft_sender(av[2], ft_atoi(av[1]));
	return (0);
}
