/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:59:12 by mjarboua          #+#    #+#             */
/*   Updated: 2023/03/20 18:40:04 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/signal.h>

char	*ft_itoa(int num);
void	ft_puts(char *str);
void	ft_putc(char c);
void	mini_printf(char *s, int num, char c);
int		ft_atoi(char *str);

#endif