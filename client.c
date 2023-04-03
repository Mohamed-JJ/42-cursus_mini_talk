/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:52:56 by mjarboua          #+#    #+#             */
/*   Updated: 2023/04/03 15:32:56 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
}

int	ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	parse_p_id(char *v)
{
	int	i;

	i = 0;
	while (v[i])
	{
		if (ft_isnum(v[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	p_id;

	p_id = ft_atoi(av[1]);
	if (ac != 3)
		return (ft_puts("too many/few arguments\n"), 0);
	if (p_id <= 0)
		return (ft_puts("please enter a valid process id\n"), 0);
	if (parse_p_id(av[1]))
		return (ft_puts("p_id must be strictly an integer\n"), 0);
	ft_sender(av[2], p_id);
	return (0);
}
