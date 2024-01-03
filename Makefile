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

SRC_1 = push_swap.c \

SRC_2 =	algorithm.c \
		ft_add_back.c \
		ft_stack_new.c \
		ft_check_utils.c \
		ft_parse.c \
		solver_utils_ab.c \
		solver_utils_ba.c \
		ft_rotate_and_push.c \
		moves1.c \
		moves2.c \
		moves3.c \
		ft_check_dup.c \
		ft_check_sorted.c \
		ft_error_print.c \
		ft_free.c \
		lst_utils.c \
		lst_utils_2.c \
		ft_parse_args_quoted.c \
		ft_list_args.c \
		ft_check_args.c \
		ft_sort_big.c \
		ft_sort_three.c \
		ft_rotate_type.c \

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