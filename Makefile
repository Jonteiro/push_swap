# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonteiro <jonteiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 14:09:25 by jonteiro          #+#    #+#              #
#    Updated: 2023/12/22 14:25:10 by jonteiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC_1 = srcs/push_swap/push_swap.c \

SRC_2 =	srcs/push_swap/algorithm.c \
		srcs/push_swap/ft_add_back.c \
		srcs/push_swap/ft_stack_new.c \
		srcs/push_swap/ft_check_utils.c \
		srcs/push_swap/ft_parse.c \
		srcs/push_swap/solver_utils_ab.c \
		srcs/push_swap/solver_utils_ba.c \
		srcs/push_swap/ft_rotate_and_push.c \
		srcs/push_swap/moves1.c \
		srcs/push_swap/moves_2.c \
		srcs/push_swap/moves_3.c \
		srcs/push_swap/ft_check_dup.c \
		srcs/push_swap/ft_check_sorted.c \
		srcs/push_swap/ft_error_print.c \
		srcs/push_swap/ft_free.c \
		srcs/push_swap/lst_utils.c \
		srcs/push_swap/lst_utils_2.c \
		srcs/push_swap/ft_parse_args_quoted.c \
		srcs/push_swap/ft_list_args.c \
		srcs/push_swap/ft_check_args.c \
		srcs/push_swap/ft_sort_big.c \
		srcs/push_swap/ft_sort_three.c \
		srcs/push_swap/ft_rotate_type.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

all: ${NAME}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all