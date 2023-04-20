# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 17:23:41 by gmacias-          #+#    #+#              #
#    Updated: 2022/05/19 16:09:09 by gmacias-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Se viene texto, para ver si me ayuda a entenderlo y tambien si esque alguien#
# lo lee (cosa que dudo).													#
# INCLUDE; añade todos los .c y .h al ejecutable de una LIBRERIA, de ahi libft#
# /bin/; es un ejecutable, (el del sistema), esto sirve para evitar renombres.#
# $(MAKE) xxx -C; llama a otro make para que se cree antes que este mismo.	#
# $@; variabble que guarda el valor antes de los dos puntos ($xxx : ...)	#
# $^; variable que guarda TODO despues de los dos puntos (... : $xxx $xxx)	#
# Si se ejecuta bien este make, deberian salir 3 nuevos archivos:			#
# Carpeta "objects/"; guarda los objetos de este directorio.				#
# Archivador "libft.a"; es un archivo con los obj del libft para compilar.	#
# Ejecutable "pushswap"; es el programa que no depende de nada por los INCLUDE#


NAME		=	push_swap

SRCS		=	checkers.c		fill.c			finish_him.c	ft_utils.c		\
				make_position.c move_stack.c	operation_r.c 	operations.c	\
				order.c 		push_swap.c 	utils_algoritmia.c
OBJS 		=	$(SRCS:%.c=%.o)
OBJS_DIR	=	object	

CC		=	gcc
RM		=	/bin/rm -rf

CFLAGS		=	-g -Wall -Wextra -Werror

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@echo "Compiling push swap..."
	@$(CC) $(CFLAGS) -o $@ $^
	@mkdir $(OBJS_DIR)
	@/bin/mv $(OBJS) $(OBJS_DIR)
	@echo "Done !"

clean :
	@echo "Removing push swap objects..."
	@$(RM) $(OBJS_DIR)
	@echo "Done !"

fclean	:	clean
	@echo "Removing execute push swap..."
	@$(RM) $(NAME)
	@echo "Done !"

re	:	fclean all

.PHONY	:	all clean fclean re