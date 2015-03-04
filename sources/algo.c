/*
** algo.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Wed Mar  4 10:08:32 2015 Sebastien Cache-Delanos
** Last update Wed Mar  4 10:39:30 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

void                            move(t_battlefield **b, t_warrior **w)
{
  if ((*w)->posX < X && (*w)->posY < Y && (*b)->battlefield[(*w)->posX][(*w)->posY + 1] == '.')
    (*w)->posY += 1;
}

void				algo(t_battlefield* b, t_warrior* w)
{
  move(&b, &w);
  sleep(2);
}
