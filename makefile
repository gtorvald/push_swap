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

NAME = PUSH_SWAP
CC = gcc
FLAGS = -Wall -Werror -Wextra
OBJS = comands.o check.o algorithm.o algorithm_help.o
CH_MAIN = checker.o
PSH_MAIN = push_swap.o
CHECK = checker
PUSH = push_swap
LIB_NAME = libftprintf.a
LIB_OBJS = pr_stuff.o pr_char.o pr_integer.o pr_integer_help.o pr_double.o \
	pr_double_help.o pr_printf.o pr_get_next_line.o ft_putstr.o ft_putchar.o \
	ft_atoi.o ft_strlen.o ft_strcmp.o ft_strncmp.o ft_strcpy.o ft_strncpy.o \
	ft_isdigit.o ft_itoa.o ft_toupper.o ft_strcat.o ft_strsplit.o \
	ftb_itoa_unsigned.o ftb_putchar.o ftb_putstr.o ftb_nputstr.o

.PHONY: all clean fclean re

all: $(LIB_NAME) $(NAME)

$(CHECK) : $(LIB_NAME) $(OBJS) $(CH_MAIN)
	$(CC) $(FLAGS) $(OBJS) $(CH_MAIN) ./$(LIB_NAME) -o $(CHECK)

$(PUSH) : $(LIB_NAME) $(OBJS) $(PSH_MAIN)
	$(CC) $(FLAGS) $(OBJS) $(PSH_MAIN) ./$(LIB_NAME) -o $(PUSH)

$(NAME): $(OBJS) $(CH_MAIN) $(PSH_MAIN)
	$(CC) $(FLAGS) $(OBJS) $(CH_MAIN) ./$(LIB_NAME) -o $(CHECK)
	$(CC) $(FLAGS) $(OBJS) $(PSH_MAIN) ./$(LIB_NAME) -o $(PUSH)

%.o : %.c includes/checker.h includes/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

$(LIB_NAME): $(LIB_OBJS)
	ar rc $(LIB_NAME) $(LIB_OBJS)
	ranlib $(LIB_NAME)

pr_%.o : libft/pr_%.c libft/includes/printf.h libft/includes/get_next_line.h
	$(CC) $(FLAGS) -c $< -o $@

ft_%.o : libft/libft/ft_%.c libft/includes/libft.h
	$(CC) $(FLAGS) -c $< -o $@

ftb_%.o : libft/libftbonus/ftb_%.c libft/includes/libftbonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS) $(CH_MAIN) $(PSH_MAIN) $(LIB_OBJS)

fclean: clean
	-rm -f $(CHECK) $(PUSH) $(LIB_NAME)
	
re: fclean all
