# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 15:29:29 by gtorvald          #+#    #+#              #
#    Updated: 2020/01/23 15:29:32 by gtorvald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wextra -Wall -Werror

LIB_OBJS = ft_putstr.o ft_putchar.o ft_atoi.o ft_strlen.o ft_isdigit.o \
	ft_strcmp.o ft_strcpy.o ft_strsplit.o ft_strncpy.o

OBJS = get_next_line.o comands.o check.o algorithm.o

CH_MAIN = checker.o

PSH_MAIN = push_swap.o

NAME = PUSH_SWAP

CHECK = checker

PUSH = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIB_OBJS) $(CH_MAIN) $(PSH_MAIN)
	$(CC) $(FLAGS) $(LIB_OBJS) $(OBJS) $(CH_MAIN) -o $(CHECK)
	$(CC) $(FLAGS) $(LIB_OBJS) $(OBJS) $(PSH_MAIN) -o $(PUSH)

ft_%.o : libft/ft_%.c
	$(CC) $(FLAGS) -c $<

#ftb_%.o : libftbonus/ftb_%.c
#	$(CC) $(FLAGS) -c $<

%.o : %.c
	$(CC) $(FLAGS) -c $<

clean:
	-rm -f $(OBJS) $(LIB_OBJS) $(CH_MAIN) $(PSH_MAIN)

fclean: clean
	-rm -f $(CHECK)
	-rm -f $(PUSH)
	
re: fclean all
