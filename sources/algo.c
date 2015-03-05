/*
** algo.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Wed Mar  4 10:08:32 2015 Sebastien Cache-Delanos
** Last update Thu Mar  5 13:17:29 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

typedef struct			s_target
{
  int				x;
  int				y;
}				t_target;

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
	      ((t_battlefield*)addr)->battlefield[i][j] != '.')
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

void				chaseTarget(t_warrior* w, void* addr, t_target t)
{
  int				dir;

  dir = (rand() % 2);
  if ((dir == 0 || w->posY == t.y) && w->posX != t.x)
    {
      if (w->posX > t.x)
	{
	  if (((t_battlefield*)addr)->battlefield[w->posX - 1][w->posY] == '.')
	    w->posX--;
	}
      else
	if (((t_battlefield*)addr)->battlefield[w->posX + 1][w->posY] == '.')
	  w->posX++;
    }
  else
    {
      if (w->posY < t.y)
	{
	  if (((t_battlefield*)addr)->battlefield[w->posX][w->posY + 1] == '.')
	    w->posY++;
	}
      else
	if (((t_battlefield*)addr)->battlefield[w->posX][w->posY - 1] == '.')
	  w->posY--;
    }
}

void                            move(t_warrior *w)
{
  void				*addr;
  struct sembuf			sops;
  t_target			t;

  addr = shmat(w->shm_id, NULL, SHM_R | SHM_W);
  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  semop(w->shm_id, &sops, 1);
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

void				algo(t_warrior* w)
{
  move(w);
  sleep(1);
}
