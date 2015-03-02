##
## Makefile for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
## 
## Made by Sebastien Cache-Delanos
## Login   <cache-_s@epitech.net>
## 
## Started on  Mon Mar  2 11:40:21 2015 Sebastien Cache-Delanos
## Last update Mon Mar  2 12:12:28 2015 Sebastien Cache-Delanos
##

NAME	= lemipc

SRCS	= ./sources/main.c			\
	  ./sources/check.c			\
	  ./sources/start.c			\

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
