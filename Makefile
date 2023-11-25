# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 17:36:33 by shamsate          #+#    #+#              #
#    Updated: 2023/11/22 23:27:01 by shamsate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo


CFLAGS	= -Wall -Wextra -Werror
CC = cc
RM = rm -Rf

FILES = philo  \
		dependencies/utils_function/libft_utils dependencies/utils_function/take_time \
		dependencies/utils_function/print_msg dependencies/utils_function/ft_lst_add_last_ph \
		dependencies/src/philo_function/create_init_ph dependencies/src/philo_function/ph_eating \
		dependencies/src/philo_function/ph_end_died dependencies/src/philo_function/ph_put_take_forks \
		dependencies/src/philo_function/ph_routine dependencies/src/philo_function/ph_thinking \
		dependencies/src/parsing/check_take_input dependencies/src/parsing/init_phil \
		dependencies/src/parsing/the_error_handling dependencies/src/parsing/free_all_mem\

SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
HEADER = include/philo.h


all : $(NAME)

$(NAME): $(OBJ) $(HEADER)
		@echo "- Compilation Starting $(NAME)..\n"
		@ $(CC) $(OBJ) $(INCLUDE)  -o  $(NAME)
		@echo "- Execution ready..✔️\n"

%.o: %.c $(HEADER)
	@echo "- Making Object file $(notdir $@) from source file $(notdir $<)...\n"
	@ $(CC) -Wall -Wextra -Werror $(OPT) -c $< -o $@

clean:
	@ $(RM) $(OBJ)
	@echo "\n-Removing object file ..\n"
	@echo "-Object file Removed..✔️\n"

fclean: clean
	@ $(RM) $(NAME)
	@echo "-Removing $(NAME) ..\n"
	@echo "-Removed..✔️\n"

re: fclean all

.PHONY: all clean fclean re