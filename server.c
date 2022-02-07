/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:22:48 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/02/07 16:56:28 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void sighandler(int sig)
{
   if (sig == SIGUSR1)
   {
       printf("%d\n", 1);
   }
   else if (sig == SIGUSR2)
   {
       printf("%d\n", 0);
   }
}

int main(int ac, char **av)
{
    struct sigaction    sa;
//    char    *str;
    
    sa.sa_handler = sighandler;
    printf("%d\n", getpid());
    sigaction(SIGUSR1, &sa, 0);
    sigaction(SIGUSR2, &sa, 0);
//    printf("%s\n", str);
    while(1)
        pause();
    return (0);
}