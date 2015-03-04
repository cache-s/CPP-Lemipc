/*
** args.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Tue Mar  3 19:08:40 2015 Sebastien Cache-Delanos
** Last update Wed Mar  4 09:09:52 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

int				pickArmy()
{
  printf("la on pick l'army qui est dans le mal\n");
  return (0);
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
