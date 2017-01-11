# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 14:41:45 by jjacobi           #+#    #+#              #
#    Updated: 2017/01/11 05:06:35 by jjacobi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
FLAGS		= -Wall -Wextra -Werror

SRC_FILES   = ft_printf.c stock_info.c parse_info.c parse_s.c parse_maj_s.c \
				parse_p.c parse_d.c parse_maj_d.c parse_i.c parse_o.c \
				parse_maj_o.c parse_u.c parse_maj_u.c parse_x.c \
			   	parse_maj_x.c parse_c.c parse_maj_c.c
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
