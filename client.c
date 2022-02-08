/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:22:45 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/02/08 17:26:28 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int		i;
	int		nbr[11];

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


void    send_msg(int spid, char *str)
{
    int     i;

    while (*str)
    { 
        i = 8;
        while (i--)
        {
            if ((*str >> i) & 1)
            {
                kill(spid, SIGUSR1);
                usleep(100);
            }
            else
            {
                kill(spid, SIGUSR2);
                usleep(100);
            }
        }
        str++;
    }
    i = 8;
    while (i--)
    {
        kill(spid, SIGUSR2);
        usleep(100);
    }
}

void    sighandler(int sig)
{
    if (sig == SIGUSR1)
    {
        write(1, "Message was delivered to server!\n", 33);
        write(1, "Exiting client\n", 15);
        exit(0);
    }
}

int main(int ac, char **av)
{
    int spid;
    struct sigaction    sa = {0};

    if (ac != 3 || ft_atoi(av[1]) < 1 || !av[2])
        return (1);
    sa.sa_handler = sighandler;
    spid = ft_atoi(av[1]);
    write(1, "Message sent from Client PID: ", 30);
    ft_putnbr(getpid());
    write(1, "\n", 1);
    send_msg(spid, av[2]);
    sigaction(SIGUSR1, &sa, 0);
    while (1)
        pause();
    return (0);
}