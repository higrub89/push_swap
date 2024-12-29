# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 12:53:56 by rhiguita          #+#    #+#              #
#    Updated: 2024/12/06 16:07:06 by rhiguita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
LIBFT = libft/libft.a
RM = rm -rf
GREEN = \033[1;32m

SRCS = main.c \
	stack_init.c \
	stack_utils.c \
	swap.c  \
	errors.c \
	init_a_to_b.c \
	init_b_to_a.c \
	push.c \
	rev_rotate.c \
	rotate.c \
	sort_three.c \
	sort_stacks.c \
	split_push_swap.c \

OBJ = $(SRCS:.c=.o)

%.o :%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : $(OBJ) $(LIBFT)
	@echo "$(GREEN)Compiling PUSH_SWAP ..."
	cp $(LIBFT) $(NAME) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

$(LIBFT) :
	make bonus -C libft

all : $(NAME)

clean :
	$(RM) $(OBJ)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : all clean fclean re
