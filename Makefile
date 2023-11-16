# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ***REMOVED*** <***REMOVED***@student.***REMOVED***.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:24:04 by ***REMOVED***             #+#    #+#              #
#    Updated: 2023/11/16 13:02:21 by ***REMOVED***            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	:= server
NAME_CLIENT := client

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -Wunreachable-code-return
DFLAGS 	:= -g

LIBPRINTF := ./libs/printf
LIBFT := ./libs/libft

HEADERS	:= -I $(LIBFT) -I $(LIBPRINTF) -I ./include
LIBS	:= $(LIBPRINTF)/libftprintf.a $(LIBFT)/libft.a

SERVER_SRCS	:= src_server/main.c src_server/server_utils.c src_server/decoding_utils.c
CLIENT_SRCS := src_client/main.c

SERVER_OBJS	:= ${SERVER_SRCS:.c=.o}
CLIENT_OBJS	:= ${CLIENT_SRCS:.c=.o}

all: $(NAME_SERVER) $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME_SERVER): $(SERVER_OBJS)
	$(MAKE) -C $(LIBFT) bonus
	$(MAKE) -C $(LIBPRINTF) bonus
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBS) $(HEADERS) -o $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_OBJS)
	$(MAKE) -C $(LIBFT) bonus
	$(MAKE) -C $(LIBPRINTF) bonus
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBS) $(HEADERS) -o $(NAME_CLIENT)

clean:
	$(MAKE) -C $(LIBPRINTF) clean
	$(MAKE) -C $(LIBFT) clean
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(MAKE) -C $(LIBPRINTF) fclean
	$(MAKE) -C $(LIBFT) fclean
	@rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re: clean all

.PHONY: all, server, client, clean, fclean, re
