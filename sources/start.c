/*
** start.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 19:32:25 2015 Sebastien Cache-Delanos
** Last update Fri Mar  6 12:07:01 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

int				start(int army)
{
  t_warrior			*w;

  if (initBattlefield() == NULL)
    return (-1);
  if ((w = initWarrior(army)) == NULL)
    return (-1);
  loop(w);
  return (0);
}
