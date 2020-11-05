# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dyoung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 18:41:14 by dyoung            #+#    #+#              #
#    Updated: 2020/11/01 18:41:26 by dyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIBF = ../libft/
GNL = ../gnl/get_next_line.c
SRCS = Lemin_beta/
CCFL = -Wall -Wextra -Werror -lncurses -ltermcap -L $(LIBF) -lft

all: $(NAME)

$(NAME):
		@make -C $(LIBF) re
		@gcc $(CCFL) $(SRCS)*.c $(GNL) -o $(NAME)

clean:
		@make -C $(LIBF) clean

fclean:
		@make -C $(LIBF) fclean
		@/bin/rm -rf $(NAME)

re: fclean all
