##
## Makefile for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
## 
## Made by Sebastien Cache-Delanos
## Login   <cache-_s@epitech.net>
## 
## Started on  Mon Mar  2 11:40:21 2015 Sebastien Cache-Delanos
## Last update Thu Mar  5 11:19:10 2015 Sebastien Cache-Delanos
##

NAME	= lemipc

SRCS	= ./sources/main.c			\
	  ./sources/check.c			\
	  ./sources/start.c			\
	  ./sources/init.c			\
	  ./sources/show.c			\
	  ./sources/args.c			\
	  ./sources/algo.c			\
	  ./sources/loop.c			\

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -g -W -Wall -Wextra -Werror -I ./includes

CC	= gcc

RM	= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo ' '
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	$(CC) -o $@ $^
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
