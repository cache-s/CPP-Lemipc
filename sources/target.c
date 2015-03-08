/*
** target.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Sat Mar  7 13:17:14 2015 Sebastien Cache-Delanos
** Last update Sun Mar  8 18:59:12 2015 Sebastien Cache-Delanos
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
  t.x = X / 2;
  t.y = Y / 2;
  while (++i < X)
    {
      j = -1;
      while (++j < Y)
	if (((t_battlefield*)addr)->battlefield[i][j] != w->army + 48 &&
	    ((t_battlefield*)addr)->battlefield[i][j] != 'X' &&
	    ((t_battlefield*)addr)->battlefield[i][j] != '.')
	  if (abs((w->posX - i) + (w->posY - j)) < distance)
	    {
	      t.x = i;
	      t.y = j;
	      distance = abs((w->posX - i) + (w->posY - j));
	    }
    }
  return (t);
}

void			chaseTarget2(t_warrior* w, void* addr, t_target t)
{
  if (w->posY < t.y)
    {
      if ((w->posY + 1) < Y &&
	  ((t_battlefield*)addr)->battlefield[w->posX][w->posY + 1] == '.')
	w->posY++;
    }
  else
    if ((w->posY - 1) >= 0 &&
	((t_battlefield*)addr)->battlefield[w->posX][w->posY - 1] == '.')
      w->posY--;
}
 
void			chaseTarget(t_warrior* w, void* addr, t_target t)
{
  int			dir;
  int			x;
  int			y;

  dir = (rand() % 2);
  x = w->posX;
  y = w->posY;
  if ((dir == 0 || w->posY == t.y) && w->posX != t.x)
    {
      if (w->posX > t.x)
	{
	  if ((w->posX - 1) >= 0 &&
	      ((t_battlefield*)addr)->battlefield[w->posX - 1][w->posY] == '.')
	    w->posX--;
	}
      else
        if ((w->posX + 1) < X &&
	    ((t_battlefield*)addr)->battlefield[w->posX + 1][w->posY] == '.')
	  w->posX++;
    }
  else
    chaseTarget2(w, addr, t);
  if (w->posX == x && w->posY == y)
    randomMove(w, addr);
}
