# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 17:26:30 by gcatarin          #+#    #+#              #
#    Updated: 2023/04/01 15:45:25 by gcatarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I./ # -fsanitize=address
RM				= rm -fr

NAME			= libftprintf.a
HEADER			= ft_printf.h
EXE				= ft_printf

SOURCES			= srcs/ft_printf.c srcs/ft_printloop.c srcs/ft_utils_2.c  \
				 srcs/ft_types.c srcs/ft_utils.c
BONUS			=  srcs/*.c

SOURCES_O		= $(SOURCES:srcs/%.c=objs/%.o)
BONUS_O		= $(BONUS:srcs/%.c=objs/%.o)

all:		objs $(NAME)

$(NAME):		$(SOURCES_O)
	ar -rcs $(NAME) $(SOURCES_O)
	${CC} ${NAME} -o ${EXE}

objs:
	mkdir -p objs

run:		${NAME}
	clear && ${CC} ${NAME} -o ${EXE} && ./${EXE}.exe

objs/%.o: srcs/%.c
	${CC} ${CFLAGS} -c $^ -o $@

clean:
	$(RM) $(SOURCES_O) $(BONUS_O)

bonus:			$(NAME) $(BONUS_O)
	ar -rcs $(NAME) $(BONUS_O)

fclean:			clean
	$(RM) $(NAME)

re:				fclean $(NAME)

rebonus:		fclean bonus

.PHONY:			all clean fclean re