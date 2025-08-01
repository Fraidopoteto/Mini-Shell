# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 17:23:59 by joschmun          #+#    #+#              #
#    Updated: 2025/07/15 14:41:58 by joschmun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# config
NAME	:= minishell
CC		:= cc
SRC_DIR	:= src/
INC_DIR	:= inc/
OBJ_DIR	:= obj/

CFLAGS	:=
CFLAGS	+= -O2
CFLAGS	+= -Wall
CFLAGS	+= -Wextra
CFLAGS	+= -Werror
CFLAGS	+= $(ADDFLAGS)

CPPFLAGS	:=
CPPFLAGS	+= -I$(INC_DIR)

LDFLAGS	:=

LDLIBS	+= -lreadline
LDLIBS	+= -ltermcap
LDLIBS	+= -lncurses

ifeq ($(DEBUG), 1)
	CFLAGS	+= -ggdb3 -O0
	LDFLAGS	+= -ggdb3 -O0
endif

ifeq ($(TSAN), 1)
	CFLAGS	+= -fsanitize=thread
	LDFLAGS	+= -fsanitize=thread
endif

ifeq ($(LSAN), 1)
	CFLAGS	+= -fsanitize=leak
	LDFLAGS	+= -fsanitize=leak
endif

ifeq ($(ASAN), 1)
	CFLAGS	+= -fsanitize=address
	LDFLAGS	+= -fsanitize=address
endif

# sources
SRC		:=

vpath %.c src/
SRC		+= main.c
SRC		+= lexing.c
SRC		+= loop.c
SRC		+= tokenize.c
SRC		+= debug.c
SRC		+= cleanup.c


OBJ		:= $(SRC:.c=.o)
OBJ		:= $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

$(OBJ_DIR)/%.o:%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@make fclean
	@make all

valtest:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME) $(ARGS)

heltest:
	valgrind --tool=helgrind ./$(NAME) $(ARGS)

.PHONY: all clean fclean re
.PHONY: valtest heltest
