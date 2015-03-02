/*
** main.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Mar  2 11:37:11 2015 Jordan Chazottes
** Last update Mon Mar  2 12:15:15 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

int				main(int ac, char** av)
{
  int				teams;

  teams = 2;
  if (ac == 1)
    return (start(teams));
  if (ac == 2)
    if (checkNb(av[1]) == 0 && (teams = atoi(av[1])) > 2)
      return (start(teams));
  printf("Usage : ./lemipc [TEAMS]\n");
  printf("[TEAMS] Must be a valid number greater than 1\n");
  return (-1);
}
