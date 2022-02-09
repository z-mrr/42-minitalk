/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:22:45 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/02/09 14:43:27 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(int spid, char *str)
{
	int	i;

	while (*str)
	{
		i = 8;
		while (i--)
		{
			if ((*str >> i) & 1)
				kill(spid, SIGUSR1);
			else
				kill(spid, SIGUSR2);
			usleep(100);
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

void	sighandler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Message was received by Server.\n", 32);
		write(1, "Closing client!\n", 16);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int					spid;
	struct sigaction	sa;

	if (ac != 3 || ft_atoi(av[1]) < 1 || !av[2])
		return (1);
	spid = ft_atoi(av[1]);
	write(1, "Message sent from Client PID: ", 30);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_handler = sighandler;
	sigaction(SIGUSR1, &sa, 0);
	send_msg(spid, av[2]);
	while (1)
		pause();
	return (0);
}
