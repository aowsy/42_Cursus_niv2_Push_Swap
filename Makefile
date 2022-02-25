# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 14:00:18 by mdelforg          #+#    #+#              #
#    Updated: 2022/02/19 15:53:52 by mdelforg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c \
	   push_swap_parsing.c \
	   push_swap_radix.c \
	   push_swap_push.c \
	   push_swap_reverse_rotate.c \
	   push_swap_rotate.c \
	   push_swap_small_stack.c \
	   push_swap_swap.c \
	   push_swap_libc_dup.c \
	   push_swap_libc_int.c \
	   push_swap_libc_str.c \
	   push_swap_libc_lst.c \
	   push_swap_libc_lst_utils.c

OBJS = $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror


-g -fsanitize=address

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:	$(NAME)

exe:	all clean

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
