# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 16:51:42 by mmaksymi          #+#    #+#              #
#    Updated: 2025/02/22 11:40:37 by mmaksymi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -pthread -Wno-unused-but-set-variable

NAME = philo

SRCS = srcs/main.c \
		srcs/parsing.c \
		srcs/utils.c \
		srcs/threads.c \
		srcs/philo.c \
		srcs/time.c
	
OFILES = $(SRCS:.c=.o)

CC = cc

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
