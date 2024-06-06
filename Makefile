# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 15:00:22 by agoldber          #+#    #+#              #
#    Updated: 2024/06/06 15:17:54 by agoldber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
FILES	=	fdf.c coordinates.c get_window.c utils.c line_draw.c
FLAGS	=	-lmlx -framework OpenGL -framework AppKit -O3
LIBFT	=	libft.a

all:	${NAME}

${NAME}:	${LIBFT}
	gcc ${FILES} ${LIBFT} ${FLAGS}

${LIBFT}:
	make -C libft/
	mv libft/libft.a .

clean:
	make clean -C libft/

fclean:	clean
	make fclean -C libft/

re:		fclean all

.PHONY:		all clean fclean re