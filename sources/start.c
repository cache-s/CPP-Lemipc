/*
** start.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 19:32:25 2015 Sebastien Cache-Delanos
** Last update Wed Mar  4 10:32:40 2015 Jordan Chazottes
*/

#include			"lemipc.h"

int				start(int army)
{
  t_battlefield			*b;
  t_warrior			*w;

  if ((b = initBattlefield()) == NULL)
    return (-1);
  if ((w = initWarrior(army, b)) == NULL)
    return (-1);
  b->recap[w->army - 1] += 1;
  showBattlefield(b);
  showWarrior(w);
  loop(b, w);
  return (0);
}
