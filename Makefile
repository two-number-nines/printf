# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vmulder <vmulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/22 14:18:40 by vmulder        #+#    #+#                 #
#    Updated: 2019/05/23 13:41:13 by vmulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

## EXECUTABLE ##
NAME = libftprintf.a

## INCLUDES ##
SRC_PATH = srcs
HEADER = ../incl/

## SOURCES ##
SOURCES = main.c checkflags.c checkwidth.c checkpresicion.c checklengmodif.c \
			checkspecifier.c converter_csp.c utils_csp.c converter_di.c utils_di.c \
			utils_main.c converter_uox.c utils_uox.c utils_f.c converter_f.c \
			whileloops.c

## OBJECTS ##
SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(SOURCES:.c=.o)

## COMPILATION ##
CC = gcc
FLAGS = -Wall -Werror -Wextra -c

## RULES ##
all: $(NAME)

$(NAME):
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@$(CC) $(FLAGS) $(SRCS) -I $(HEADER)
	@ar rc $(NAME) $(OBJS)
	@echo "Project successfully compiled"

clean:
	@echo "Cleaning..."
	@make clean -C libft
	@rm -rf *.o

fclean:
	@echo "Fcleaning..."
	@rm -rf *.o
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean
	@$(MAKE) all -j

.PHONY: temporary, re, fclean, clean
