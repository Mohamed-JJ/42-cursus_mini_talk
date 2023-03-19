/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:56:37 by mjarboua          #+#    #+#             */
/*   Updated: 2023/03/19 20:47:00 by mjarboua         ###   ########.fr       */
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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
