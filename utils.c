/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:15:11 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/02/08 20:58:10 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int	i;
	int	nbr[11];

	if (n == -2147483648 || n == 0)
	{
		if (n == -2147483648)
			write(1, "-2147483648", 11);
		else if (n == 0)
			ft_putchar('0');
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		nbr[i] = n % 10;
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(nbr[i] + '0');
}

long int	ft_atoi(const char *nptr)
{
	int			i;
	int			sig;
	long int	res;

	i = 0;
	sig = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sig = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sig);
}
