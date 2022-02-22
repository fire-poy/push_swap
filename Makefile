# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpons <mpons@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 17:30:16 by mpons             #+#    #+#              #
#    Updated: 2022/02/22 15:16:37 by mpons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror -fsanitize=address

OBJS		= ${SRC:.c=.o}

RM			= rm -f

LIBFT_DIR	= ./libft

SRC 		= ./src/main.c\
			  ./src/err.c\
			  ./src/node.c\
			  ./operation/operation.c\
			  ./operation/push.c\
			  ./operation/swap.c\
			  ./operation/rotate.c\
			  ./algos/push_swap.c\
			  ./algos/sort_3_5.c\
			  ./algos/find_min_max.c\
			  ./algos/push_min_max.c\
			  ./algos/find_min_pivot.c\
			  ./algos/trier.c\
			#   ./failed_delta/delta.c\
			#   ./failed_delta/petit_big_choix.c\


#INC			= -I./inc -I./libft/libft.h
INC			= -I./inc 

#LIB			= -L ./libft -lft 
LIB			= ./libft/libft.a 

all: $(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) -o $(NAME) $(INC) $(SRC) $(LIB)
#$(NAME):	$(OBJS)
#			$(MAKE) -C $(LIBFT_DIR)
#			$(CC) $(CFLAGS) -o $(NAME) $(INC) $(SRC) $(LIB)

easy:		
			$(CC) -o $(NAME) $(INC) $(SRC) $(LIB)

lldb:		
			$(CC) -g $(CFLAGS) -o $(NAME) $(INC) $(SRC) $(LIB)

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
