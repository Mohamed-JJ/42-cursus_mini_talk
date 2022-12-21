/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:52:56 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/21 20:01:43 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	send_bits(char c, int pid)
// {
// 	int		i;
// 	char	s;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		s = c & i;
// 		kill(pid, s);
// 		i++;
// 	}
// }
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
			usleep(300);
		}
		e++;
	}
}

int main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
		return (ft_puts("not enough arguments"), 0);
	ft_sender(av[2], atoi(av[1]));
}
