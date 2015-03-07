/*
** handleShmNF.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sat Mar  7 13:05:56 2015 Jordan Chazottes
** Last update Sat Mar  7 13:24:15 2015 Jordan Chazottes
*/

#include	"lemipc.h"

void		handleShmNF(SDL_Surface *screen)
{
  SDL_Surface *but;
  SDL_Rect     butPos;



  butPos.x = 0;
  butPos.y = 0;
  but= SDL_CreateRGBSurface(0, 100, 50, 32, 0, 0, 0, 0);
  SDL_FillRect(but, NULL, SDL_MapRGB(but->format, 255, 0, 0));
  SDL_BlitSurface(but, NULL, screen, &butPos);
  SDL_Flip(screen);
  pause();
}
