# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 12:46:46 by msimoes           #+#    #+#              #
#    Updated: 2025/06/18 16:01:59 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS = pipex.c utils.c errors.c \
		./srcs/ft_bzero.c ./srcs/ft_calloc.c ./srcs/ft_split.c \
		./srcs/ft_strjoin.c ./srcs/ft_strlen.c \
		./srcs/ft_strnstr.c ./srcs/ft_strchr.c

COMP_LIB = ar rcs
RM = rm -f
CC = cc
CC_FLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#$(NAME): $(OBJS) 
#	$(COMP_LIB) $(NAME) $(OBJS)

$(NAME): $(OBJS) 
	$(CC) $(CC_FLAGS) $(OBJS) -o$(NAME)

.PHONY: all clean fclean re
