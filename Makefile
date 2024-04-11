# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbilly <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 12:27:02 by mbilly            #+#    #+#              #
#    Updated: 2023/03/27 11:06:03 by mbilly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = ft_substr.c get_next_line_bonus.c ft_strlen.c\
       here_doc.c ft_strjoin.c process.c ft_split.c \
       ft_strncmp.c ft_calloc.c ft_bzero.c main.c utils.c \
       ft_strchr.c ft_strjoin2.c\

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
