/*
** main.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Mar  2 11:37:11 2015 Jordan Chazottes
** Last update Mon Mar  2 16:59:34 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

int				usage()
{
  printf("Usage : ./lemipc TEAM\n");
  printf("TEAM must be a valid number between 1 and 5 included\n");
  return (-1);
}

int				main(int ac, char** av)
{
  int				team;

  if (ac == 2)
    if (checkNb(av[1]) == 0 && (team = atoi(av[1])) > 2)
      return (start(team));
  return (usage());
}
