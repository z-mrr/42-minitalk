# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 16:28:47 by jdias-mo          #+#    #+#              #
#    Updated: 2022/02/08 18:45:46 by jdias-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c utils.c

CSOURCES = client.c utils.c

SSOURCES = server.c utils.c

OBJECTS = $(SOURCES:.c=.o)

COBJECTS = $(CSOURCES:.c=.o)

SOBJECTS = $(SSOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: $(SOBJECTS)
	$(CC) -o $@ $(SOBJECTS)

client: $(COBJECTS)
	$(CC) -o $@ $(COBJECTS)
%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all bonus clean fclean re