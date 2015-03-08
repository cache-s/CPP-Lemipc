/*
** algo.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Wed Mar  4 10:08:32 2015 Sebastien Cache-Delanos
** Last update Sun Mar  8 17:27:50 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

void				randomMove(t_warrior* w, void* addr)
{
  if (w->posY + 1 < Y &&
      ((t_battlefield*)addr)->battlefield[w->posX][w->posY + 1] == '.')
    w->posY++;
  else
    if (w->posY - 1 >= 0 &&
	((t_battlefield*)addr)->battlefield[w->posX][w->posY - 1] == '.')
      w->posY--;
    else
      if (w->posX + 1 < X &&
	  ((t_battlefield*)addr)->battlefield[w->posX + 1][w->posY] == '.')
	w->posX++;
      else
	if (w->posX - 1 >= 0 &&
	    ((t_battlefield*)addr)->battlefield[w->posX - 1][w->posY] == '.')
	  w->posX--;
}

void				algo(t_warrior *w, void* addr)
{
  t_target			t;

  addr = shmat(w->shm_id, NULL, SHM_R | SHM_W);
  ((t_battlefield*)addr)->battlefield[w->posX][w->posY] = '.';
  if (checkDeath(w, addr) == 0)
    {
      w->state = DEAD;
      return;
    }
  if (checkAlone(w, addr) == 0)
    {
      t = getTarget(w, addr);
      chaseTarget(w, addr, t);
    }
  ((t_battlefield*)addr)->battlefield[w->posX][w->posY] = w->army + 48;
}
