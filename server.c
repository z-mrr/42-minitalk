/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:22:48 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/02/08 14:29:30 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

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
          write(1, "\n", 1);
        else
            write(1, &c, 1);
        i = 8;
        c = 0;
    }
}

int main(int ac, char **av)
{
    struct sigaction    sa = {0};
    
    sa.sa_handler = sighandler;
    printf("Server is up.\nServer PID: %d\n", getpid());
    printf("Waiting for incoming message...\n");
    sigaction(SIGUSR1, &sa, 0);
    sigaction(SIGUSR2, &sa, 0);
    while(1)
        pause();
    return (0);
}