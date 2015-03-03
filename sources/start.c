/*
** start.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 19:32:25 2015 Sebastien Cache-Delanos
** Last update Tue Mar  3 11:24:45 2015 Jordan Chazottes
*/

#include			"lemipc.h"

int				start(int team)
{
  t_map				*m;
  t_player			*p;

  if ((m = initMap()) == NULL)
    return (-1);
  showMap(m);
  if ((p = initPlayer(team)) == NULL)
    return (-1);
  showPlayer(p);
  loop();
  return (0);
}
