# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 17:30:16 by mpons             #+#    #+#              #
#    Updated: 2022/01/26 11:41:36 by mpons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

OBJS		= ${SRC:.c=.o}

RM			= rm -f

LIBFT_DIR	= ./libft

SRC 		= ./src/main.c\
			  ./src/err.c\
			  ./src/node.c\
			  ./src/operation.c\
			  ./src/push.c\
			  ./src/swap.c\
			  ./src/rotate.c\
			  ./src/quick_sort.c\
			  ./src/push_swap.c\

INC			= -I./inc -I./libft/libft.h

LIB			= -L ./libft -lft 

all: $(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) -o $(NAME) $(INC) $(SRC) $(LIB)

easy:		
			$(CC) -o $(NAME) $(INC) $(SRC) $(LIB)

clean:
			$(MAKE) -C $(LIBFT_DIR) clean
		   	$(RM) $(OBJS)

fclean: 
			$(MAKE) -C $(LIBFT_DIR) fclean
		   	$(RM) $(OBJS)
	   		$(RM) $(NAME)

re:			fclean all

norm:
			norminette -d ./gnl ./inc ./libft ./src

.PHONY : all clean fclean re bonus
