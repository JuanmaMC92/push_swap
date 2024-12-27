# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 20:27:29 by natferna          #+#    #+#              #
#    Updated: 2024/12/27 20:27:29 by natferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap


CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
