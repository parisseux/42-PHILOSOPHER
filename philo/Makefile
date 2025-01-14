# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 14:11:10 by parissachat       #+#    #+#              #
#    Updated: 2025/01/14 14:41:51 by parissachat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
SRCDIR = src
OBJDIR = obj

FILES = main.c \
		check_input.c

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIR)/, $(FILES:.c=.o))

SUCCESS = "\033[1;35mSuccessful compilation of PHILO!\033[0m"

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo $(SUCCESS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true  

fclean: clean 
	@$(RM) $(NAME)

re: fclean all 

.phony: all clean fclean re