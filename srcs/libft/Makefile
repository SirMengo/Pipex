# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 12:46:46 by msimoes           #+#    #+#              #
#    Updated: 2025/04/28 10:15:37 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS =  ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memset.c ft_strchr.c ft_strrchr.c \
		ft_strdup.c ft_strlen.c ft_tolower.c ft_toupper.c \
		ft_bzero.c ft_calloc.c ft_memcpy.c ft_memchr.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c \
		ft_memcmp.c ft_strnstr.c ft_substr.c ft_strjoin.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstmap.c ft_lstclear.c ft_lstlast.c ft_lstiter.c
				
				
COMP_LIB = ar rcs
RM = rm -f
CC = cc
CC_FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)


%.o : %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	$(COMP_LIB) $(NAME) $(OBJS) $(OBJS_BONUS)
	@touch bonus

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	@touch bonus
	@rm bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all


$(NAME): $(OBJS) 
	$(COMP_LIB) $(NAME) $(OBJS)

.PHONY: all clean fclean re
