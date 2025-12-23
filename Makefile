# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 15:00:22 by agoldber          #+#    #+#              #
#    Updated: 2024/09/17 14:07:14 by agoldber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#BASE

NAME			=	fdf
INCLUDES		=	includes
SRCS_DIR 		=	src/
OBJS_DIR		=	obj/
CC				=	gcc
C_FLAGS			=	-Wall -Werror -Wextra -I${INCLUDES}
MLX_FLAGS		=	-lmlx -framework OpenGL -framework AppKit -O3
LIBFT			=	libft.a
RM				=	rm -rf

#COLORS

BGREEN			=	\033[1;32m
BBLUE			=	\033[1;34m
BCYAN			=	\033[1;36m
BPURPLE			=	\033[1;35m
BWHITE			=	\033[1;37m
BYELLOW			=	\033[1;33m
BRED			=	\033[1;31m
PASTEL_PINK		=	\033[38;5;210m
PASTEL_PURPLE	=	\033[38;5;183m
PASTEL_BLUE		=	\033[38;5;111m
COLOR_END		=	\033[0m

#GRADIENT LOGO FUNCTION

define gradient_logo
		@echo "${PASTEL_PINK}      ___                       ___                ___           ___                    ___           ___           ___     "
		@echo "${PASTEL_PINK}     /\\  \\          ___        /\\__\\              /\\  \\         /\\  \\                  /\\  \\         /\\  \\         /\\  \\    "
		@echo "${PASTEL_PURPLE}    /::\\  \\        /\\  \\      /:/  /             /::\\  \\       /::\\  \\                /::\\  \\       /::\\  \\       /::\\  \\   "
		@echo "${PASTEL_PURPLE}   /:/\\:\\  \\       \\:\\  \\    /:/  /             /:/\\:\\  \\     /:/\\:\\  \\              /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\  "
		@echo "${PASTEL_BLUE}  /::\\~\\:\\  \\      /::\\__\\  /:/  /             /:/  \\:\\__\\   /::\\~\\:\\  \\            /::\\~\\:\\  \\   /::\\~\\:\\  \\   /::\\~\\:\\  \\ "
		@echo "${PASTEL_BLUE} /:/\\:\\ \\:\\__\\  __/:/\\/__/ /:/__/             /:/__/ \\:|__| /:/\\:\\ \\:\\__\\          /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\"
		@echo "${PASTEL_BLUE} \\/__\\:\\ \\/__/ /\\/:/  /    \\:\\  \\             \\:\\  \\ /:/  / \\:\\~\\:\\ \/__/          \\/__\\:\\ \/__/ \\:\\~\\:\\ \/__/ \\/_|::\\/:/  /"
		@echo "${PASTEL_PURPLE}      \\:\\__\\   \\::/__/      \\:\\  \\             \\:\\  /:/  /   \\:\\ \\:\\__\\                 \\:\\__\\    \\:\\ \\:\\__\\      |:|::/  / "
		@echo "${PASTEL_PURPLE}       \\/__/    \\:\\__\\       \\:\\  \\             \\:\\/:/  /     \\:\\ \/__/                  \\/__/     \\:\\ \/__/      |:|\\/__/  "
		@echo "${PASTEL_PINK}                 \\/__/        \\:\\__\\             \\::/__/       \\:\\__\\                               \\:\\__\\        |:|  |    "
		@echo "${PASTEL_PINK}                               \\/__/              ~~            \\/__/                                \\/__/         \\|__|    ${COLOR_END}"
		@echo ""
endef

#SOURCES

FILES			=	fdf coordinates get_window hook line_draw utils retab

SRCS			=	${addprefix ${SRCS_DIR}, ${addsuffix .c, ${FILES}}}
OBJS			=	${addprefix ${OBJS_DIR}, ${addsuffix .o, ${FILES}}}

# Progress Bar Variables
TOTAL_FILES		=	$(words $(FILES))

# ---------------------------------------------------------------------------- #

OBJSF			=	.cache_exists

all: check

check:
	@if [ -f $(NAME) ] && [ $$(find $(SRCS) -newer $(OBJS_DIR) -type f | wc -l) -eq 0 ]; then \
		echo "${BGREEN}Everything up to date${COLOR_END}"; \
	else \
		$(MAKE) display_logo; \
		$(MAKE) ${NAME}; \
	fi

display_logo:
	$(gradient_logo)

${NAME}:	${LIBFT} | ${OBJS}
			@${CC} -o ${NAME} ${OBJS} ${LIBFT} ${MLX_FLAGS}
			@echo "\n${BGREEN}Fdf compiled!${COLOR_END}"

${LIBFT}:
			@make -C libft/
			@mv libft/libft.a .
			@make clean -C libft/
			
${OBJS_DIR}%.o : ${SRCS_DIR}%.c | ${OBJSF}
			@mkdir -p $(dir $@)
			@${CC} ${C_FLAGS} -c $< -o $@
			@PROGRESS=$$(echo "$$(find ${OBJS_DIR} -type f | wc -l | tr -d ' ') * 100 / ${TOTAL_FILES}" | bc); \
			BAR=$$(for i in `eval echo {1..$$((PROGRESS / 2))}`; do printf "▇"; done); \
			SPACES=$$(for i in `eval echo {1..50}`; do if [ $$i -gt $$((PROGRESS / 2)) ]; then printf " "; fi; done); \
			CURRENT_FILES=$$(find ${OBJS_DIR} -type f | wc -l | tr -d ' '); \
			printf "\r${BBLUE}Compiling: [$$BAR$$SPACES] $$PROGRESS%% ($$CURRENT_FILES/${TOTAL_FILES}) files${COLOR_END}"

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

.PHONY:	all clean fclean re