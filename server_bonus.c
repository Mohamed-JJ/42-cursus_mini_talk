/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:26:43 by mjarboua          #+#    #+#             */
/*   Updated: 2023/04/03 16:12:30 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	revert_to_original(char *str, unsigned char *c, t_mini *h)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			str[i] = 0;
			i++;
		}
	}
	*c = 0b11111111;
	h->e = 0;
	h->h = 0;
	h->counter = 0;
}

static void	print_reset_string(char *c, unsigned char *f, t_mini *p)
{
	if (*f == '\0')
		kill(p->g_p_id, SIGUSR1);
	else
		write(1, c, p->h);
	revert_to_original(c, f, p);
}

void	if__full(char *c, unsigned char *f, t_mini *p)
{
	c[p->counter++] = *f;
	if (!(*f & 0x80))
		if_character(f, p);
	else if ((p->counter) == p->h)
		print_reset_string(c, f, p);
	else
	{
		p->e = 0;
		*f = 0b1111111;
	}
}

static void	ft_handler(int sig, siginfo_t *t, void *v)
{
	static unsigned char	f = 0b11111111;
	static char				c[4];
	static t_mini			p;

	(void)v;
	if (p.g_p_id != t->si_pid)
		revert_to_original(c, &f, &p);
	p.g_p_id = t->si_pid;
	do_bitwise_op(&f, &p, sig);
	if (p.e == 8 && (f & 0x80) && p.h == 0)
		p.h = count_bytes(f);
	if (p.e == 8)
		if__full(c, &f, &p);
}

int	main(void)
{
	struct sigaction	var;
	t_mini				p;

	p.g_p_id = getpid();
	var.sa_flags = SA_SIGINFO;
	var.sa_sigaction = &ft_handler;
	mini_printf("this is the process id --> ", p.g_p_id, '\n');
	sigaction(SIGUSR1, &var, NULL);
	sigaction(SIGUSR2, &var, NULL);
	while (1)
		pause();
	return (0);
}
