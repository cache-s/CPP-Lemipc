/*
** target.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Sat Mar  7 13:17:14 2015 Sebastien Cache-Delanos
** Last update Sat Mar  7 14:53:20 2015 Jordan Chazottes
*/

#include		"lemipc.h"

t_target		getTarget(t_warrior *w, void* addr)
{
  int			i;
  int			j;
  int			distance;
  t_target		t;
 
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
	    if (abs((w->posX - i) + (w->posY - j)) < distance)
	      {
                t.x = i;
                t.y = j;
		distance = abs((w->posX - i) + (w->posY - j));
	      }
	}
    }
  return (t);
}

void			chaseTarget2(t_warrior* w, void* addr, t_target t)
{
  if (w->posY < t.y)
    {
      if (w->posY + 1 < Y &&
	  ((t_battlefield*)addr)->battlefield[w->posX][w->posY + 1] == '.')
	w->posY++;
    }
  else
    if (w->posY - 1 >= 0 &&
	((t_battlefield*)addr)->battlefield[w->posX][w->posY - 1] == '.')
      w->posY--;
    else
      randomMove(w, addr);
}
 
void			chaseTarget(t_warrior* w, void* addr, t_target t)
{
  int			dir;

  dir = (rand() % 2);
  if ((dir == 0 || w->posY == t.y) && w->posX != t.x)
    {
      if (w->posX > t.x)
	{
	  if (w->posX - 1 >= 0 &&
	      ((t_battlefield*)addr)->battlefield[w->posX - 1][w->posY] == '.')
	    w->posX--;
	}
      else
        if (w->posX + 1 < X &&
	    ((t_battlefield*)addr)->battlefield[w->posX + 1][w->posY] == '.')
	  w->posX++;
        else
	  randomMove(w, addr);
    }
  else
    chaseTarget2(w, addr, t);
}
