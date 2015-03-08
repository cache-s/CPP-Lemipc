/*
** check.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc/sources
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 12:11:18 2015 Sebastien Cache-Delanos
** Last update Sun Mar  8 13:33:38 2015 Jordan Chazottes
*/

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
