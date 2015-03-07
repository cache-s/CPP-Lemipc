/*
** checkWin.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sat Mar  7 13:39:28 2015 Jordan Chazottes
** Last update Sat Mar  7 13:42:05 2015 Jordan Chazottes
*/

#include	"lemipc.h"

int		checkWin(void *addr)
{
  return (((t_battlefield*)addr)->winner);
}
