/*
** check.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc/sources
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 12:11:18 2015 Sebastien Cache-Delanos
** Last update Sat Mar  7 12:56:01 2015 Sebastien Cache-Delanos
*/

#include			<string.h>

#include			"lemipc.h"

int				checkAlone(t_warrior* w, void* addr)
{
  int				i;

  i = 0;
  while (i != 5)
    {
      if (i != w->army - 1)
	{
	  if (((t_battlefield*)addr)->recap[i] > 0)
	    return (0);
	}
      ++i;
    }
  return (-1);
}

int				checkDeath(t_warrior* w, void* addr)
{
  char				enemy[8] = ".";
  int				i;
  int				j;

  i = -1;
  if (w->posX - 1 >= 0)
    enemy[0] = ((t_battlefield*)addr)->battlefield[w->posX - 1][w->posY];
  if (w->posX + 1 <= X)
    enemy[1] = ((t_battlefield*)addr)->battlefield[w->posX + 1][w->posY];
  if (w->posY - 1 >= 0)
    enemy[2] = ((t_battlefield*)addr)->battlefield[w->posX][w->posY - 1];
  if (w->posY + 1 <= Y)
    enemy[3] = ((t_battlefield*)addr)->battlefield[w->posX][w->posY + 1];
  if (w->posX - 1 >= 0 && w->posY + 1 <= Y)
    enemy[4] = ((t_battlefield*)addr)->battlefield[w->posX - 1][w->posY + 1];
  if (w->posX + 1 <= X && w->posY + 1 <= Y)
    enemy[5] = ((t_battlefield*)addr)->battlefield[w->posX + 1][w->posY + 1];
  if (w->posX + 1 <= X && w->posY - 1 >= 0)
    enemy[6] = ((t_battlefield*)addr)->battlefield[w->posX + 1][w->posY - 1];
  if (w->posX - 1 >= 0 && w->posY - 1 >= 0)
    enemy[7] = ((t_battlefield*)addr)->battlefield[w->posX - 1][w->posY + 1];
  while (++i != 8)
    {
      j = -1;
      while (enemy[i] != '.' && enemy[i] != 'X' && enemy[i] != w->army + 48 && ++j != 4)
	{
	  if (j != i)
	    if (enemy[i] == enemy[j])
	      return (0);
	}
    }
  return (-1);
}

int				checkHelp(char* str)
{
  if (strcmp(str, "--help") == 0)
    return (0);
  return (-1);
}

int				checkUsage(char* str)
{
  if (strcmp(str, "--usage") == 0)
    return (0);
  return (-1);
}

int				checkNb(char* str)
{
  int				i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      ++i;
    }
  return (0);
}
