# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 16:28:47 by jdias-mo          #+#    #+#              #
#    Updated: 2022/02/08 17:29:50 by jdias-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o 
	$(CC) -o $@ $<

client: client.o 
	$(CC) -o $@ $<
%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all bonus clean fclean server client re