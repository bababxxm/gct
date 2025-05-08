# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:44:55 by sklaokli          #+#    #+#              #
#    Updated: 2025/05/08 11:52:23 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	gct.a

SRC_DIR		:=	sources
OBJ_DIR		:=	objects
INC_DIR		:=	include

FILES		:=	gct.c

SRC			:=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ			:=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

INC			:=	-I $(INC_DIR)

CC			:=	cc
RM			:=	rm -rf
AR			:=	ar rcs
WFLAGS		:=	-Wall -Wextra -Werror
VFLAGS		:=	--track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all

CYAN		:=	\033[0;36m
GREEN		:=	\033[0;32m
RED			:=	\033[0;31m
BLUE		:=	\033[0;34m
YELLOW		:=	\033[0;33m
RESET		:=	\033[0m

TOTAL_FILES	:=	$(words $(OBJ))
COMPILED	:=	0

all: 			$(NAME)

$(NAME):		$(OBJ)
				@ $(AR) $(NAME) $(OBJ)
				@ echo "$(GREEN)[OK] $(NAME) built succesfully.$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@ mkdir -p $(dir $@)
				@ $(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
				@ PERCENT=$$(($(COMPILED)*100/$(TOTAL_FILES))); \
				echo "$(BLUE)[$(COMPILED)/$(TOTAL_FILES)] Compiling $< ($$PERCENT%)$(RESET)\r"
				@ $(CC) $(WFLAGS) $(INC) -c $< -o $@

clean:
				@ $(RM) $(OBJ_DIR)
				@ echo "$(CYAN)All $(NAME) object files have been cleaned.$(RESET)"

fclean:			clean
				@ $(RM) $(NAME)
				@ echo "$(CYAN)All $(NAME) executable files have been cleaned.$(RESET)"

re:				fclean all

valgrind:		$(NAME)
				@ valgrind $(VFLAGS) ./$(NAME)

.PHONY:			all clean fclean re valgrind