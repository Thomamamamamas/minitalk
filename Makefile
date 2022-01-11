# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 15:25:37 by tcasale           #+#    #+#              #
#    Updated: 2022/01/11 16:56:30 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk
SERVER	= server
CLIENT	= client

SERVERSRC	= server.c
CLIENTSRC	= client.c

SERVEROBJ	=${SERVERSRC:.c=.o}
CLIENTOBJ	=${CLIENTSRC:.c=.o}

HEADER	= includes

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

%.o: %.c
			${CC} ${CFLAGS} -I./libft/libft.a -c $< -o $@

all:	$(NAME)

$(NAME):	$(SERVER)
			$(CLIENT)

$(SERVER):	$(SERVEROBJ) ./libft/libft.a
			$(CC) $(SERVEROBJ) ./libft/libft.a -o $(SERVER)

$(CLIENT):	$(CLIENTOBJ) ./libft/libft.a
			$(CC) $(CLIENTOBJ) ./libft/libft.a -o $(CLIENT)

./libft/libft.a:
	$(MAKE) -C ./libft

clean:
		$(MAKE) -C ./libft $@
		${RM} ${SERVEROBJ}
		${RM} ${CLIENTOBJ}

fclean:	clean
		$(MAKE) -C ./libft $@
		${RM} ${SERVER}
		${RM} ${CLIENT}

re:	fclean all

.PHONY:	all clean fclean re
