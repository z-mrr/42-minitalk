/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:22:48 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/02/09 14:46:47 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
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
        }
        else
            write(1, &c, 1);
        i = 8;
        c = 0;
    }
}*/

void	print_text(int cpid)
{
	write(1, "\nMessage received from Client PID: ", 35);
	ft_putnbr(cpid);
	write(1, "\nWaiting for another message... (CTRL+C to EXIT)\n", 49);
}

void	print_exit(void)
{
	write(1, "\nShutting down Server!\n", 23);
	exit(0);
}

void	get_msg(int sig, siginfo_t *info, void *context)
{
	static int	cpid = 0;
	static int	i = 8;
	static char	c = 0;

	if (sig == SIGINT)
		print_exit();
	(void)context;
	if (!cpid)
		cpid = info->si_pid;
	c |= (sig == SIGUSR1);
	if (--i)
		c <<= 1;
	else
	{
		if (!c)
		{
			print_text(cpid);
			kill(cpid, SIGUSR1);
			cpid = 0;
		}
		else
			write(1, &c, 1);
		i = 8;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "Server is up. Server PID: ", 26);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	write(1, "Waiting for incoming message... (CTRL+C to EXIT)\n", 49);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = get_msg;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	sigaction(SIGINT, &sa, 0);
	while (1)
		pause();
	return (0);
}
