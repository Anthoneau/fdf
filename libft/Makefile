# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 09:39:13 by agoldber          #+#    #+#              #
#    Updated: 2024/06/17 13:53:06 by agoldber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#BASE

NAME		=	libft.a
INCLUDES	=	include
SRCS_DIR 	=	src/
OBJS_DIR	=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -rf
AR			=	ar -rcs

#COLORS

BGREEN		=	\033[1;32m
BBLUE		=	\033[1;34m
BCYAN		=	\033[1;36m
BPURPLE		=	\033[1;35m
BWHITE		=	\033[1;37m
COLOR_END	=	\033[0m

#SOURCES

FTIS_DIR	=	ft_is/
FTIS		=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM_DIR	=	ft_mem/
FTMEM		=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset

FTPUT_DIR	=	ft_put/
FTPUT		=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO_DIR	=	ft_to/
FTTO		=	ft_atoi ft_itoa ft_tolower ft_toupper ft_atoi_base

FTSTR_DIR	=	ft_str/
FTSTR		=	ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
				ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
				ft_strnstr ft_strrchr ft_strtrim ft_substr

FTLST_DIR	=	ft_lst/
FTLST		=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
				ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

FTPRINTF_DIR=	ft_printf/
FTPRINTF	=	display ft_printf hexa_transfo print_string

GNL_DIR		=	gnl/
GNL			=	get_next_line2 get_next_line2_utils

FTADD_DIR	=	ft_add/
FTADD		=	ft_swap

SRC_FILES+=${addprefix ${FTIS_DIR},${FTIS}}
SRC_FILES+=${addprefix ${FTMEM_DIR},${FTMEM}}
SRC_FILES+=${addprefix ${FTPUT_DIR},${FTPUT}}
SRC_FILES+=${addprefix ${FTTO_DIR},${FTTO}}
SRC_FILES+=${addprefix ${FTSTR_DIR},${FTSTR}}
SRC_FILES+=${addprefix ${FTLST_DIR},${FTLST}}
SRC_FILES+=${addprefix ${FTPRINTF_DIR},${FTPRINTF}}
SRC_FILES+=${addprefix ${GNL_DIR}, ${GNL}}
SRC_FILES+=${addprefix ${FTADD_DIR}, ${FTADD}}

SRCS 		= 	${addprefix ${SRCS_DIR}, ${addsuffix .c, ${SRC_FILES}}}
OBJS 		= 	${addprefix ${OBJS_DIR}, ${addsuffix .o, ${SRC_FILES}}}

# ---------------------------------------------------------------------------- #

OBJSF		=	.cache_exists

all:		${NAME}

${NAME}:	${OBJS}
			@${AR} ${NAME} ${OBJS}
			@echo "${BGREEN}Libft compiled!${COLOR_END}"

${OBJS_DIR}%.o : ${SRCS_DIR}%.c | ${OBJSF}
			@echo "${BPURPLE}Compiling: $< ${COLOR_END}"
			@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${OBJSF}:
			@mkdir -p ${OBJS_DIR}
			@mkdir -p ${OBJS_DIR}${FTIS_DIR}
			@mkdir -p ${OBJS_DIR}${FTMEM_DIR}
			@mkdir -p ${OBJS_DIR}${FTPUT_DIR}
			@mkdir -p ${OBJS_DIR}${FTTO_DIR}
			@mkdir -p ${OBJS_DIR}${FTSTR_DIR}
			@mkdir -p ${OBJS_DIR}${FTLST_DIR}
			@mkdir -p ${OBJS_DIR}${FTPRINTF_DIR}
			@mkdir -p ${OBJS_DIR}${GNL_DIR}
			@mkdir -p ${OBJS_DIR}${FTADD_DIR}

clean:
			@${RM} ${OBJS_DIR}
			@${RM} ${OBJSF}
			@echo "${BCYAN}Libft .o files cleaned!${COLOR_END}"

fclean:		clean
			@${RM} ${NAME}
			@echo "${BBLUE}Libft .a files cleaned!${COLOR_END}"

re:			fclean all

.PHONY:		all clean fclean re
