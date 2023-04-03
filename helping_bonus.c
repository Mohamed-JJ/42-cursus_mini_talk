/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:37:48 by mjarboua          #+#    #+#             */
/*   Updated: 2023/04/03 14:38:12 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result = result + str[i++] - 48;
	}
	result *= sign;
	return (result);
}
