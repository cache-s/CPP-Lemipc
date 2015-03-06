##
## Makefile for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
## 
## Made by Sebastien Cache-Delanos
## Login   <cache-_s@epitech.net>
## 
## Started on  Mon Mar  2 11:40:21 2015 Sebastien Cache-Delanos
## Last update Fri Mar  6 13:06:41 2015 Jordan Chazottes
##

NAME	= lemipc

D_NAME	= disp

SRCS	= ./sources/main.c			\
	  ./sources/check.c			\
	  ./sources/start.c			\
	  ./sources/init.c			\
	  ./sources/show.c			\
	  ./sources/args.c			\
	  ./sources/algo.c			\
	  ./sources/loop.c			\

OBJS	= $(SRCS:.c=.o)

D_SRCS	= ./sources/display/main.c		\
	  ./sources/display/createSprite.c	\
	  ./sources/display/createRect.c	\
	  ./sources/display/eventHandler.c	\
	  ./sources/display/getShm.c		\
	  ./sources/display/applySurface.c	\
	  ./sources/display/displayLoop.c	\

D_OBJS	= $(D_SRCS:.c=.o)

CFLAGS	= -W -Wall -Wextra -Werror -I ./includes

CC	= gcc

RM	= rm -rf

all: $(NAME) display

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

display: $(D_OBJS)
	@echo ' '
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	$(CC) -lSDLmain -lSDL -lSDL_image -o $(D_NAME) $^
	@echo 'Finished building target: $@'
	@echo ' '

clean:
	$(RM) $(OBJS)
	$(RM) $(D_OBJS)
	@find ./ -name '*~' -exec rm '{}' \;
	@find ./ -name '*#' -exec rm '{}' \;

fclean: clean
	$(RM) $(NAME)
	$(RM) $(D_NAME)

re: fclean all
