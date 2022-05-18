# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 17:23:41 by gmacias-          #+#    #+#              #
#    Updated: 2022/05/16 17:33:48 by gmacias-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS		= 	$(wildcard *.c)
OBJS 		=	${SRCS:%.c=%.o}
LIB_DIR		=	../libft/
LIB		=	libft.a

CC		=	gcc
RM		=	/bin/rm -rf

INCLUDE		= 	-I ./ -I $(LIB_DIR)
CFLAGS		=	-g -Wall -Wextra -Werror $(INCLUDE)

.PHONY	:	all clean fclean re

all	:	$(NAME)

$(NAME)	:	${OBJS} &(LIB)
	@echo "Compiling push swap..."
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "Done !"
	
&(LIB)	:
	@$(MAKE) -C $(LIB_DIR)
	@echo "Moving libft.a into this directory..."
	@/bin/mv $(LIB_DIR)&(LIB) .

clean	:
	@echo "Removing push swap and libft objects..."
	@$(MAKE) clean -C $(LIB_DIR)
	@${RM} ${OBJS}
	@echo "Done !"

fclean	:	clean
	@echo "Removing execute push swap and libft.a..."
	@$(MAKE) fclean -C $(LIB_DIR)
	@${RM} $(LIB)
	@${RM} $(NAME)
	@echo "Done !"

re	:	fclean all
