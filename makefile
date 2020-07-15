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

OBJS = get_next_line.o comands.o check.o algorithm.o algorithm_help.o

CH_MAIN = checker.o

PSH_MAIN = push_swap.o

NAME = PUSH_SWAP

CHECK = checker

PUSH = push_swap

USE_LIB = ./libft/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(CH_MAIN) $(PSH_MAIN)
	$(CC) $(FLAGS) $(OBJS) $(CH_MAIN) $(USE_LIB) -o $(CHECK)
	$(CC) $(FLAGS) $(OBJS) $(PSH_MAIN) $(USE_LIB) -o $(PUSH)

%.o : %.c includes/%.h
	$(CC) $(FLAGS) -c $<

clean:
	-rm -f $(OBJS) $(CH_MAIN) $(PSH_MAIN)

fclean: clean
	-rm -f $(CHECK)
	-rm -f $(PUSH)
	
re: fclean all
