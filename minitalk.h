/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:59:12 by mjarboua          #+#    #+#             */
/*   Updated: 2023/03/21 19:28:51 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/signal.h>

typedef struct l_mini
{
	int	g_p_id;
	int	e;
	int	counter;
	int	h;
}				t_mini;

char	*ft_itoa(int num);
void	ft_puts(char *str);
void	ft_putc(char c);
void	mini_printf(char *s, int num, char c);
int		ft_atoi(char *str);
int		count_bytes(int c);
void	if_character(unsigned char *f, t_mini *p);
void	do_bitwise_op(unsigned char *f, t_mini *p, int sig);


#endif