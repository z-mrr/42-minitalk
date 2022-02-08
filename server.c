/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:22:48 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/02/08 17:26:29 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
/*
void sighandler(int sig)
{
    static int     i = 8;
    static char    c = 0;

    if (sig == SIGUSR1)
        c |= 1;
    else if (sig == SIGUSR2)
        c |= 0;
    if (--i)
        c <<= 1;
    else
    {
        if (!c)
        {
            write(1, "\n", 1);
           g_received = 1;
        }
        else
            write(1, &c, 1);
        i = 8;
        c = 0;
    }
}*/

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

void    get_msg(int sig, siginfo_t *info, void *context)
{
    static int      cpid;
    static int      i = 8;
    static char     c = 0;

    (void)context;
    if (!cpid)
        cpid = info->si_pid;
    if (sig == SIGUSR1)
        c |= 1;
    else if (sig == SIGUSR2)
        c |= 0;
    if (--i)
        c <<= 1;
    else
    {
        if (!c)
        {
            write(1, "\n", 1);
            write(1, "Message received from Client PID: ", 34);
            ft_putnbr(cpid);
            write(1, "\n", 1);
            write(1, "Waiting for another message...\n", 31);
            usleep(100);
            kill(cpid, SIGUSR1);
            cpid = 0;
        }
        else
            write(1, &c, 1);
        i = 8;
        c = 0;
    }
}

int main(void)
{
    struct sigaction    sa = {0};
    
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_msg;
    write(1, "Server is up.\nServer PID: ", 26);
    ft_putnbr(getpid());
    write(1, "\n", 1);
    write(1, "Waiting for incoming message...\n", 32);
    sigaction(SIGUSR1, &sa, 0);
    sigaction(SIGUSR2, &sa, 0);
    while(1)
        pause();
    return (0);
}