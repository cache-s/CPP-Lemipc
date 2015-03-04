/*
** start.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 19:32:25 2015 Sebastien Cache-Delanos
** Last update Wed Mar  4 18:03:06 2015 Jordan Chazottes
*/

#include			"lemipc.h"

int				start(int army)
{
  t_warrior			*w;

  if (initBattlefield() == NULL)
    return (-1);
  if ((w = initWarrior(army)) == NULL)
    return (-1);
  showBattlefield(w);
  showWarrior(w);
  loop(w);
  return (0);
}
