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

# Se viene texto, para ver si me ayuda a entenderlo y tambien si esque alguien #
# lo lee (cosa que dudo).                                                      #
# INCLUDE; añade todos los .c y .h al ejecutable.                              #
# /bin/; es un ejecutable, (el del sistema), esto sirve para evitar renombres. #
# $(MAKE) xxx -C; llama a otro make para que se cree antes que este mismo.     #
# $@; variabble que guarda el valor detras de los dos puntos ($xxx : ...)      #
# $^; variable que guarda TODO despues de los dos puntos (... : $xxx $xxx)     #
# Si se ejecuta bien este make, deberian salir 3 nuevos archivos:              #
# Carpeta "objects/"; guarda los objetos de este directorio.                   #
# Archivador "libft.a"; es un archivo con los obj del libft para compilar.     #
# Ejecutable "pushswap"; es el programa que no depende de nada por los INCLUDE #


NAME		=	push_swap

SRCS		= 	$(wildcard *.c)
OBJS 		=	${SRCS:%.c=%.o}
OBJS_DIR        =       objects/
LIB_DIR		=	../libft/
LIB		=	libft.a

CC		=	gcc
RM		=	/bin/rm -rf

INCLUDE		= 	-I ./ -I $(LIB_DIR)
CFLAGS		=	-g -Wall -Wextra -Werror $(INCLUDE)


.PHONY	:	all clean fclean re

all	:	$(NAME)

$(NAME)	:	${OBJS} $(LIB)
	@echo "Compiling push swap..."
	@$(CC) $(CFLAGS) -o $@ $^
	@mkdir $(OBJS_DIR)
	@/bin/mv $(OBJS) $(OBJS_DIR)
	@echo "Done !"
	
$(LIB)	:
	@$(MAKE) -C $(LIB_DIR)
	@echo "Moving libft.a into this directory..."
	@/bin/mv $(LIB_DIR)$(LIB) .

clean :
	@echo "Removing push swap and libft objects..."
	@$(MAKE) clean -C $(LIB_DIR)
	@${RM} ${OBJS_DIR}
	@echo "Done !"

fclean	:	clean
	@echo "Removing execute push swap and libft.a..."
	@$(MAKE) fclean -C $(LIB_DIR)
	@${RM} $(LIB)
	@${RM} $(NAME)
	@echo "Done !"

re	:	fclean all
