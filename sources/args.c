/*
** args.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Tue Mar  3 19:08:40 2015 Sebastien Cache-Delanos
** Last update Wed Mar  4 10:01:36 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

int				pickArmy()
{
  t_battlefield			*b;
  int				nb;
  int				i;
  int				j;

  i = 0;
  j = 1;
  if ((b = initBattlefield()) == NULL)
    return (-1);
  nb = b->recap[0];
  while (++i < 5)
    if (b->recap[i] < nb)
      {
	nb = b->recap[i];
	j = i + 1;
      }
  return (j);
}

int				getArmy(char* arg)
{
  char*				tmp;
  int				army;

  tmp = malloc(1 * sizeof(*tmp));
  if (tmp == NULL)
    {
      printf("Malloc fail in getArmy()");
      return (-1);
    }
  if (strncmp(arg, "--army=", 7) == 0 && strlen(arg) == 8)
    {
      strncpy(tmp, arg + 7, 1);
      army = atoi(tmp);
      free(tmp);
      if (army >= 1 && army <= 5)
	return (army);
    }
  printf("Invalid argument\n");
  free(tmp);
  return (-1);
}
