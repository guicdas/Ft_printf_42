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

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I.	 # -fsanitize=address
RM				= rm -fr

OBJS_DIR		= objs
SRCS_DIR		= srcs
NAME			= ft_printf
HEADER			= ft_printf.h

SOURCES			= $(SRCS_DIR)/ft_printf.c $(SRCS_DIR)/ft_printloop.c $(SRCS_DIR)/ft_utils_2.c  \
				 $(SRCS_DIR)/ft_types.c $(SRCS_DIR)/ft_utils.c
BONUS			=  $(SRCS_DIR)/*.c

SOURCES_O		= $(SOURCES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
BONUS_O		= $(BONUS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all:	$(NAME)

$(NAME):		$(SOURCES_O)
	clear
	${CC} ${CFLAGS} $(SOURCES_O) -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -o ${NAME} -c $< -o $@

$(OBJS_DIR):
	mkdir -p objs

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	${CC} ${CFLAGS} -c $^ -o $@

clean:
	$(RM) $(OBJS_DIR)

#bonus:			$(NAME) $(BONUS_O)
#	ar -rcs $(NAME) $(BONUS_O)

fclean:			clean
	$(RM) $(NAME)

re:				fclean $(NAME)

rebonus:		fclean #bonus

.PHONY:			all clean fclean re