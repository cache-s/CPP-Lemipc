/*
** lemipc.h for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 11:40:49 2015 Sebastien Cache-Delanos
** Last update Sun Mar  8 20:42:42 2015 Jordan Chazottes
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
# include			<time.h>
# include			<SDL/SDL.h>
# include			<SDL/SDL_image.h>
# include			<SDL/SDL_ttf.h>

/* DEFINES */

# define			X	50
# define			Y	30

/* ENUM */

typedef	enum			State
  {
    ALIVE			= 0,
    DEAD			= 1
  }				State;

/* STRUCTURE */

typedef struct			s_target
{
  int				x;
  int				y;
}				t_target;

typedef	struct			s_battlefield
{
  char				battlefield[X][Y];
  int				recap[5];
  int				winner;
}				t_battlefield;

typedef	struct			s_warrior
{
  State				state;
  int				posX;
  int				posY;
  int				army;
  int				shm_id;
}				t_warrior;

/* PROTOTYPES */

int				main(int, char**);
int				checkNb(char*);
int				checkHelp(char*);
int				checkUsage(char*);
int				checkAlone(t_warrior*, void*);
int				checkDeath(t_warrior*, void*);
int				start(int);
void				showBattlefield(t_warrior* w);
void				showWarrior(t_warrior*);
t_battlefield*			initBattlefield();
t_warrior*			initWarrior(int);
void				loop(t_warrior*);
int				getArmy(char*);
int				pickArmy();
void				algo(t_warrior*, void*);
void				move(t_warrior*);
struct sembuf			*init_sembuf(struct sembuf*, int);
t_target			getTarget(t_warrior*, void*);
void				chaseTarget(t_warrior*, void*, t_target);
void				randomMove(t_warrior*, void*);

void				*getShm();
int				eventHandler();
void				displayLoop(SDL_Surface*);
void				createSprite(void*, int, int, SDL_Surface*);
void				createRect(void*, int, int, SDL_Surface*);
void				applySurface(int, int, SDL_Surface*, SDL_Surface*, SDL_Rect*);
void				resetBackground(void *, SDL_Surface*);
int				checkWin(void*);
void				displayWinScreen(int, SDL_Surface*);
int				my_SDL_Init(SDL_Surface **);

#endif				/*LEMIPC_H_*/
