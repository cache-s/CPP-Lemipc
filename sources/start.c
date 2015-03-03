/*
** start.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 19:32:25 2015 Sebastien Cache-Delanos
** Last update Tue Mar  3 10:38:44 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

/*void				loop()
{
  t_player			*p;

  while (p->state != DEAD || team victory)
    {
      //wait signal : get "mutex"
      //on change la pos
      //on catch les message msgq
    }
    //isLast() ? destroyIPCS
}*/

int				start(int team)
{
  t_map				*m;
  (void)team;

  if ((m = initMap()) == NULL)
    return (-1);
  showMap(m);
  //  loop();
  return (0);
}
