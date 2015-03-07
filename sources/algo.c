/*
** algo.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Wed Mar  4 10:08:32 2015 Sebastien Cache-Delanos
** Last update Sat Mar  7 12:21:23 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

t_target			getPos(t_warrior *w, void* addr)
{
  int				i;
  int				j;
  int				distance;
  t_target			t;

  distance = X * Y;
  i = -1;
  while (++i < X)
    {
      j = -1;
      while (++j < Y)
	{
	  if (((t_battlefield*)addr)->battlefield[i][j] != w->army + 48 &&
	      ((t_battlefield*)addr)->battlefield[i][j] >= '1' &&
	      ((t_battlefield*)addr)->battlefield[i][j] <= '5')
	    {
	      if (abs((w->posX - i) + (w->posY - j)) < distance)
		{
		  t.x = i;
		  t.y = j;
		  distance = abs((w->posX - i) + (w->posY - j));
		}
	    }
	}
    }
  return (t);
}

void				randomMove(t_warrior* w, void* addr)
{
  if (w->posY + 1 < Y && ((t_battlefield*)addr)->battlefield[w->posX][w->posY + 1] == '.')
    w->posY++;
  else
    if (w->posY - 1 >= 0 && ((t_battlefield*)addr)->battlefield[w->posX][w->posY - 1] == '.')
      w->posY--;
    else
      if (w->posX + 1 < X && ((t_battlefield*)addr)->battlefield[w->posX + 1][w->posY] == '.')
	w->posX++;
      else
	if (w->posX - 1 >= 0 && ((t_battlefield*)addr)->battlefield[w->posX - 1][w->posY] == '.')
	  w->posX--;
}

void				chaseTarget(t_warrior* w, void* addr, t_target t)
{
  int				dir;

  dir = (rand() % 2);
  if ((dir == 0 || w->posY == t.y) && w->posX != t.x)
    {
      if (w->posX > t.x)
	{
	  if (w->posX - 1 >= 0 && ((t_battlefield*)addr)->battlefield[w->posX - 1][w->posY] == '.')
	    w->posX--;
	}
      else
	if (w->posX + 1 < X && ((t_battlefield*)addr)->battlefield[w->posX + 1][w->posY] == '.')
	  w->posX++;
	else
	  randomMove(w, addr);
      return;
    }
  if (w->posY < t.y)
    {
      if (w->posY + 1 < Y && ((t_battlefield*)addr)->battlefield[w->posX][w->posY + 1] == '.')
	w->posY++;
    }
  else
    if (w->posY - 1 >= 0 && ((t_battlefield*)addr)->battlefield[w->posX][w->posY - 1] == '.')
      w->posY--;
    else
      randomMove(w, addr);
}

void				algo(t_warrior *w, void* addr)
{
  t_target			t;

  addr = shmat(w->shm_id, NULL, SHM_R | SHM_W);
  ((t_battlefield*)addr)->battlefield[w->posX][w->posY] = '.';
  if (checkDeath(w, addr) == 0)
    {
      w->state = DEAD;
      ((t_battlefield*)addr)->recap[w->army - 1] -= 1;
      return;
    }
  if (checkAlone(w, addr) == 0)
    {
      t = getPos(w, addr);
      chaseTarget(w, addr, t);
    }
  ((t_battlefield*)addr)->battlefield[w->posX][w->posY] = w->army + 48;
}
