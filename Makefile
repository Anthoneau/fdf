# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 15:00:22 by agoldber          #+#    #+#              #
#    Updated: 2024/06/17 15:53:22 by agoldber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#BASE

NAME		=	fdf
INCLUDES	=	include
SRCS_DIR 	=	src/
OBJS_DIR	=	obj/
CC			=	gcc
C_FLAGS		=	-Wall -Werror -Wextra -I${INCLUDES}
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit -O3
LIBFT		=	libft.a
RM			=	rm -rf

#COLORS

BGREEN		=	\033[1;32m
BBLUE		=	\033[1;34m
BCYAN		=	\033[1;36m
BPURPLE		=	\033[1;35m
BWHITE		=	\033[1;37m
COLOR_END	=	\033[0m

#SOURCES

FILES		=	fdf coordinates get_window hook line_draw utils

SRCS		=	${addprefix ${SRCS_DIR}, ${addsuffix .c, ${FILES}}}
OBJS		=	${addprefix ${OBJS_DIR}, ${addsuffix .o, ${FILES}}}

# ---------------------------------------------------------------------------- #

OBJSF		=	.cache_exists

all:	${NAME}

${NAME}:	${LIBFT} | ${OBJS}
			@${CC} -o ${NAME} ${OBJS} ${LIBFT} ${MLX_FLAGS}
			@echo "${BGREEN}Fdf compiled!${COLOR_END}"

${LIBFT}:
			@make -C libft/
			@mv libft/libft.a .
			@make clean -C libft/
			
${OBJS_DIR}%.o : ${SRCS_DIR}%.c | ${OBJSF}
			@echo "${BPURPLE}Compiling: $< ${COLOR_END}"
			@${CC} ${C_FLAGS} -c $< -o $@


${OBJSF}:
			@mkdir -p ${OBJS_DIR}

clean:
			@${RM} ${OBJS_DIR}
			@${RM} ${OBJSF}
			@echo "${BCYAN}Fdf .o files cleaned!${COLOR_END}"

fclean:	clean
			@${RM} ${NAME}
			@${RM} ${LIBFT}
			@echo "${BBLUE}Fdf .a and executable files cleaned!${COLOR_END}"

re:		fclean all

.PHONY:		all clean fclean re