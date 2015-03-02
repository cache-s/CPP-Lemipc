##
## Makefile for AVM in /home/chazot_a/rendu/PSU_2014_philo
## 
## Made by Jordan Chazottes
## Login   <chazot_a@epitech.net>
## 
## Started on  Wed Feb 25 14:44:30 2015 Jordan Chazottes
## Last update Mon Mar  2 11:36:54 2015 Jordan Chazottes
##

NAME	= lemipc

SRCS	= ./sources/main.c			\

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Wall -Wextra -Werror -I ./includes

CC	= gcc

RM	= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo ' '
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	$(CC) -lpthread -o $@ $^
	@echo 'Finished building target: $@'
	@echo ' '

%.o: %.c
	@echo ' '
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo 'Finished building: $<'
	@echo ' '

clean:
	$(RM) $(OBJS)
	@find ./ -name '*~' -exec rm '{}' \;
	@find ./ -name '*#' -exec rm '{}' \;

fclean: clean
	$(RM) $(NAME)

re: fclean all
