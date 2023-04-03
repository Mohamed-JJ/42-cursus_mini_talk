/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:20:43 by mjarboua          #+#    #+#             */
/*   Updated: 2023/04/03 14:37:10 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	count_bytes(int c)
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

void	do_bitwise_op(unsigned char *f, t_mini *p, int sig)
{
	*f = *f ^ 128 >> p->e;
	if (sig == SIGUSR1)
		*f = *f | 128 >> p->e;
	p->e++;
}

void	if_character(unsigned char *f, t_mini *p)
{
	if (*f == '\0')
		kill(p->g_p_id, SIGUSR1);
	write(1, f, 1);
	p->e = 0;
	*f = 0b11111111;
	p->h = 0;
	p->counter = 0;
}
