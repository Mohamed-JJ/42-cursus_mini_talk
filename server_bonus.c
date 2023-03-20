/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:26:43 by mjarboua          #+#    #+#             */
/*   Updated: 2023/03/20 18:53:21 by mjarboua         ###   ########.fr       */
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

static void	wrong_p_id(char *str, unsigned char *c, int *e, int *f)
{
	int	i;

	i = -1;
	if (str)
		while (str[++i])
			str[i] = '\0';
	*e = 0;
	*c = 0b11111111;
	*e = 0;
	*f = 0;
	g_p_id = 0;
}

static void	print_reset(unsigned char *c, int *f, int *x, int *h)
{
	if (*c == '\0')
		kill(g_p_id, SIGUSR1);
	write(1, c, 1);
	*c = 0b11111111;
	*f = 0;
	*x = 0;
	*h = 0;
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
		wrong_p_id(c, &f, &counter, &h);
		e = 0;
	}
	g_p_id = t->si_pid;
	f = f ^ 128 >> e;
	if (sig == SIGUSR1)
		f = f | 128 >> e;
	e++;
	if (e == 8 && (f & 128) && h == 0)
		h = count_bytes(f);
	if (e == 8)
	{
		c[counter++] = f;
		if (!(f & 128))
			print_reset(&f, &h, &counter, &e);
		else if (counter == h)
		{
			if (f == '\0')
				kill(g_p_id, SIGUSR1);
			else
				write(1, c, h);
			e = 0;
			f = 0b11111111;
			h = 0;
			counter = 0;
		}
		else
			print_reset(&f, &h, &counter, &e);
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
