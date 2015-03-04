/*
** main.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Mar  2 11:37:11 2015 Jordan Chazottes
** Last update Wed Mar  4 10:24:38 2015 Jordan Chazottes
*/

#include			"lemipc.h"

int				usage()
{
  printf("Usage : ./lemipc --usage\n");
  printf("\t./lemipc --help\n");
  printf("\t./lemipc [--army=x]\n");
  return (0);
}

int				help()
{
  usage();
  printf("\n\tx must be a valid number between 1 and 5 included\n");
  printf("\tArmies :\n\t\t1 - Humans\n\t\t2 - Elves\n\t\t");
  printf("3 - Dwarves\n\t\t4 - Orcs\n\t\t5 - Goblins\n");
  return (0);
}

int				main(int ac, char** av)
{
  int				army;

  if (ac > 2)
    return (usage());
  srand(time(NULL));
  if (ac == 1)
    return (start(pickArmy()));
  if (ac == 2 && checkHelp(av[1]) == 0)
    return (help());
  if (ac == 2 && checkUsage(av[1]) == 0)
    return (usage());
  army = getArmy(av[1]);
  if (army != -1)
    return (start(army));
  return (-1);
}
