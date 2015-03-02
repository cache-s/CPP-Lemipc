/*
** lemipc.h for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 11:40:49 2015 Sebastien Cache-Delanos
** Last update Mon Mar  2 19:56:41 2015 Sebastien Cache-Delanos
*/

#ifndef				LEMIPC_H_
# define			LEMIPC_H_

/* INCLUDES */

# include			<stdio.h>
# include			<stdlib.h>
# include			<string.h>
# include			<sys/ipc.h>
# include			<sys/types.h>
# include			<sys/shm.h>

/* DEFINES */

# define			X	50
# define			Y	100

/* ENUM */

typedef	enum			State
  {
    ALIVE			= 0,
    DEAD			= 1
  }				State;

/* STRUCTURE */

typedef	struct			s_struct
{
  char				map[X][Y];
}				t_struct;

typedef	struct			s_player
{
  State				state;
  int				posX;
  int				posY;
  int				team;
}				t_player;

/* PROTOTYPES */

int				main(int, char**);
int				checkNb(char*);
int				start(int);
void				showMap(t_struct*);
int				initMap();

#endif				/*LEMIPC_H_*/
