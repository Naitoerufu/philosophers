# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 16:51:42 by mmaksymi          #+#    #+#              #
#    Updated: 2025/02/20 11:28:38 by mmaksymi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra #-Wno-unused-but-set-variable

NAME = philo

SRCS = srcs/main.c \
		srcs/parsing.c \
		srcs/utils.c
	
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
	rm -rf $(NAME) $(OFILES)

re: fclean $(NAME)
