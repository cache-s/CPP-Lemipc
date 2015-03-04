/*
** lemipc.h for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 11:40:49 2015 Sebastien Cache-Delanos
** Last update Wed Mar  4 10:10:15 2015 Sebastien Cache-Delanos
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
# include			<sys/sem.h>
# include			<unistd.h>

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

typedef	struct			s_battlefield
{
  char				battlefield[X][Y];
  int				recap[4];
}				t_battlefield;

typedef	struct			s_warrior
{
  int				id;
  State				state;
  int				posX;
  int				posY;
  int				army;
}				t_warrior;

/* PROTOTYPES */

int				main(int, char**);
int				checkNb(char*);
int				checkHelp(char*);
int				checkUsage(char*);
int				start(int);
void				showBattlefield(t_battlefield*);
void				showWarrior(t_warrior*);
t_battlefield*			initBattlefield();
t_warrior*			initWarrior(int);
void				loop(t_battlefield*, t_warrior*);
int				getArmy(char*);
int				pickArmy();
void				algo(t_battlefield*, t_warrior*);

#endif				/*LEMIPC_H_*/
