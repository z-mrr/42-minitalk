/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:16:36 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/02/08 18:26:09 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#	define MINITALK_H

#	include <sys/types.h>
#	include <unistd.h>
#	include <signal.h>
#	include <stdlib.h>

//server
void			get_msg(int sig, siginfo_t *info, void *context);
//client
void			send_msg(int spid, char *str);
void			sighandler(int sig);
//utils
void			ft_putchar(char c);
void			ft_putnbr(int n);
long int	ft_atoi(const char *nptr);

#endif
