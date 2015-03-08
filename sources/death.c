/*
** death.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Sat Mar  7 13:13:00 2015 Sebastien Cache-Delanos
** Last update Sun Mar  8 18:47:02 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

int				checkDeath2(t_warrior* w, char* enemy)
{
  int				i;
  int				j;

  i = -1;
  while (++i != 8)
    {
      j = -1;
      while (enemy[i] && enemy[i] != '.' && enemy[i] != 'X' &&
	     enemy[i] != w->army + 48 && ++j != 8)
	{
	  if (enemy[j] && j != i)
	    if (enemy[i] == enemy[j])
	      return (0);
	}
    }
  return (-1);
}
 
int				checkDeath(t_warrior* w, void* addr)
{
  char				enemy[8] = ".";

  if ((w->posX - 1) >= 0)
    enemy[0] = ((t_battlefield*)addr)->battlefield[w->posX - 1][w->posY];
  if ((w->posX + 1) < X)
    enemy[1] = ((t_battlefield*)addr)->battlefield[w->posX + 1][w->posY];
  if ((w->posY - 1) >= 0)
    enemy[2] = ((t_battlefield*)addr)->battlefield[w->posX][w->posY - 1];
  if ((w->posY + 1) < Y)
    enemy[3] = ((t_battlefield*)addr)->battlefield[w->posX][w->posY + 1];
  if ((w->posX - 1) >= 0 && (w->posY + 1) < Y)
    enemy[4] = ((t_battlefield*)addr)->battlefield[w->posX - 1][w->posY + 1];
  if ((w->posX + 1) < X && (w->posY + 1) < Y)
    enemy[5] = ((t_battlefield*)addr)->battlefield[w->posX + 1][w->posY + 1];
  if ((w->posX + 1) < X && (w->posY - 1) >= 0)
    enemy[6] = ((t_battlefield*)addr)->battlefield[w->posX + 1][w->posY - 1];
  if ((w->posX - 1) >= 0 && (w->posY - 1) >= 0)
    enemy[7] = ((t_battlefield*)addr)->battlefield[w->posX - 1][w->posY - 1];
  return (checkDeath2(w, enemy));
}
