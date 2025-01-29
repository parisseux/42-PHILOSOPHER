# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 14:11:10 by parissachat       #+#    #+#              #
#    Updated: 2025/01/29 17:08:56 by pchatagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -lpthread
RM = rm -f
SRCDIR = src
OBJDIR = obj

FILES = main.c \
		check_input.c \
		set_up.c \
		routine.c \
		end.c \
		stop.c \
		utils.c

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIR)/, $(FILES:.c=.o))

SUCCESS = "\033[1;35mSuccessful compilation of PHILO!\033[0m"
SUCCESS_CLEANING = "\033[1;32mSuccessful cleaning of PHILO!!\033[0m"

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo $(SUCCESS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true  
	@echo $(SUCCESS_CLEANING)

fclean: clean 
	@$(RM) $(NAME)

re: fclean all 

.phony: all clean fclean re