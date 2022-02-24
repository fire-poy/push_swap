# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpons <mpons@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 17:30:16 by mpons             #+#    #+#              #
#    Updated: 2022/02/24 14:28:51 by mpons            ###   ########.fr        #
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
			  ./algos/find_pos_min_max.c\
			  ./algos/push_min_max.c\
			  ./algos/find_pos_pivot.c\
			  ./algos/info_stk.c\
			  ./algos/push_piv.c\
			  ./algos/trier.c\
			  ./algos/replace.c\
			  ./algos/find_next.c\
			  
# OBJS_DIR = ./objs

# OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

# vpath %.c $(SRCS_DIR)

INC			= -I./inc 

LIB			= ./libft/libft.a 

all: $(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) -o $(NAME) $(INC) $(SRC) $(LIB)

# $(OBJS_DIR) :
# 	@mkdir -p $(OBJS_DIR)

# $(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
# 	@$(CC) $(CFLAGS) -o $@ $(INC) -I $(LIBFT_DIR) -c $^

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
