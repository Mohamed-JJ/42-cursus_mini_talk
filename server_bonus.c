/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:26:43 by mjarboua          #+#    #+#             */
/*   Updated: 2023/03/19 21:55:06 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_p_id;

static int	count_bytes(int c)
{
	if (c == 240)
		return (4);
	else if (c == 192)
		return (2);
	else if (c == 224)
		return (3);
	else
		return (1);
}

static void	ft_handler(int sig, siginfo_t *t, void *v)
{
	static unsigned char	f = 0b11111111;
	static char				c[4];
	static int				e;
	static int				h;
	static int				counter;

	(void)v;
	if (g_p_id != t->si_pid)
	{
		g_p_id = 0;
		e = 0;
		f = 0b11111111;
		counter = 0;
		h = 0;
		while (c[e])
		{
			c[e] = 0;
			e++;
		}
		e = 0;
	}
	g_p_id = t->si_pid;
	f = f ^ 128 >> e;
	if (sig == SIGUSR1)
		f = f | 128 >> e;
	e++;
	if (e == 8 && (f & 0x80) && h == 0)
		h = count_bytes(f);
	if (e == 8)
	{
		c[counter++] = f;
		if (!(f & 128))
		{
			if (f == '\0')
				kill(g_p_id, SIGUSR1);
			write(1, &f, 1);
			e = 0;
			f = 0b11111111;
			h = 0;
			counter = 0;
		}
		else if ((counter) == h)
		{
			if (f == '\0')
				kill(g_p_id, SIGUSR1);
			else
				write(1, c, h);
			e = 0;
			f = 0b11111111;
			h = 0;
			counter = 0;
			e = 0;
		}
		else
		{
			e = 0;
			f = 0b1111111;
		}
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
