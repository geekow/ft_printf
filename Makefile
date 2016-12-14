# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 14:41:45 by jjacobi           #+#    #+#              #
#    Updated: 2016/12/14 23:05:01 by jjacobi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
FLAGS		= -Wall -Wextra -Werror

SRC_FILES	= ft_printf.c stock_info.c
OBJ			= $(SRC_FILES:.c=.o)

H_DIR		= ./includes
SRC_FOLDER	= ./srcs
LIBFT_PATH	= ./libft

GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m

ifeq ($(shell uname),Darwin)
	ECHO	= echo
else
	ECHO	= echo -e
endif

all: $(NAME)

$(NAME): $(OBJ) libft.a
	@ar rc $@ $(OBJ)
	@ar -s $@
	@$(ECHO) "$(GREEN)$(NAME)$(DEFAULT) created."

libft.a:
	@$(ECHO) "$(DEFAULT)"
	@(cd $(LIBFT_PATH) && $(MAKE))

%.o: $(SRC_FOLDER)/%.c
	@$(CC) $(FLAGS) -c -o $@ $< -I $(H_DIR)
	@$(ECHO) "$(GREEN). \c"

clean:
	@rm -rf $(OBJ)
	@(cd $(LIBFT_PATH) && $(MAKE) $@)
	@$(ECHO) "All $(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean:
	@rm -rf $(NAME) $(OBJ)
	@(cd $(LIBFT_PATH) && $(MAKE) $@)
	@$(ECHO) "All $(RED).o $(DEFAULT) are now deleted for $(NAME)."
	@$(ECHO) "$(RED)$(NAME)$(DEFAULT) deleted."

re: fclean all

.PHONY: clean fclean re all
