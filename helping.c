/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:56:37 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/20 23:35:22 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_puts(char *str)
{
	while (*str)
		ft_putc(*str++);
}

void	ft_putc(char c)
{
	write(1, &c, 1);
}

void	ft_putn(int n)
{
	long	num;

	num = n;
	if (n < 0)
	{
		ft_putc('-');
		num *= -1;
	}
	if (num < 10)
		ft_putc(num + '0');
	if (num > 9)
	{
		ft_putn((num / 10));
		ft_putn((num % 10));
	}
}

void	mini_printf(char *s, int num, char c)
{
	ft_puts(s);
	ft_putn(num);
	ft_putc(' ');
	ft_putc(c);
}