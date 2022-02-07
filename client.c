/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:22:45 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/02/07 16:56:32 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

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


void    process(int pid, char *str)
{
    int i;

    while (*str)
    {
        i = 8;
        while (i--)
        {
            if ((*str >> i) & 1)
            {
                kill(pid, SIGUSR1);
                usleep(100);
            }
            else
            {
                kill(pid, SIGUSR2);
                usleep(100);
            }
        }  
        str++;  
    }
}

int main(int ac, char **av)
{
    int pid;

    if (ac != 3 || ft_atoi(av[1]) < 1 || !av[2])
        return (1);
    pid = ft_atoi(av[1]);
    process(pid, av[2]);
    return (0);
}