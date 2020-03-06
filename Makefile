# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 16:52:45 by ismelich          #+#    #+#              #
#    Updated: 2020/02/28 13:48:05 by ismelich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =  ft_printf.c modifie.c help_func.c display_char.c convert.c \
		display_str.c display_uint.c display_pointer.c display_hex.c \
		display_octal.c display_int.c help_func_2.c display_float_1.c \
		display_float_2.c

FLAGS = -Wall -Wextra -Werror

CC = gcc

HEADER = ./includes/ft_printf.h

DIR_S = srcs

SRCS = $(addprefix $(DIR_S)/,$(SRC))

OBJ = $(SRC:.c=.o)

LIB_NAME = libft.a
LIB_PATH = ./libft/
LIB = $(LIB_PATH)$(LIB_NAME)

COLOR_RESET = \033[0m
COLOR_PENDING = \033[01;33m
COLOR_SUCCESS = \033[1;32m
COLOR_DEFAULT = \033[1;34m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(LIB_NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	@make -C $(LIB_PATH)
	@echo "\033[A\033[K\033[A"
	@echo "$(LIB_NAME) [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@cp $(LIB) $(NAME)
	@echo "$(NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	@$(CC) $(FLAGS) -I $(HEADER) -I $(LIB_PATH)/includes -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[A\033[K\033[A"
	@echo "$(NAME)     [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "        [$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"

test:
	$(CC) $(NAME) main.c 
	./a.out

norme:
	@echo "$(LIB_PATH)     [$(COLOR_PENDING)Libft Norm$(COLOR_RESET)]"
	norminette ./libft/
	@echo "$(HEADER)     [$(COLOR_PENDING)Header Norm$(COLOR_RESET)]"
	norminette ./$(HEADER)/
	@echo "$(DIR_S)     [$(COLOR_PENDING)Source Norm$(COLOR_RESET)]"
	norminette ./$(DIR_S)/
	
clean:
	@make -C $(LIB_PATH) clean
	@rm -f $(OBJ)
	@echo "$(NAME): $(COLOR_SUCCESS)$(OBJ) DELETED$(COLOR_RESET)"
	@echo "$(NAME): $(COLOR_SUCCESS)All object files were deleted$(COLOR_RESET)"

fclean: clean
	@make -C $(LIB_PATH) fclean
	@echo "$(NAME): $(COLOR_SUCCESS)$(LIB) DELETED$(COLOR_RESET)"
	@rm -rfv $(NAME)
	@echo "$(NAME): $(COLOR_SUCCESS)$(NAME) DELETED$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean norme re 
