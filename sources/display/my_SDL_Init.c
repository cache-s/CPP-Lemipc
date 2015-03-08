/*
** my_SDL_Init.c for lemipc in /home/chazot_a/rendu/PSU_2014_lemipc
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Mar  8 19:44:51 2015 Jordan Chazottes
** Last update Sun Mar  8 19:45:06 2015 Jordan Chazottes
*/

#include	"lemipc.h"

int             my_SDL_Init(SDL_Surface **screen)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
      printf("Error : Init SDL : %s\n", SDL_GetError());
      return (-1);
    }
  TTF_Init();
  SDL_putenv("SDL_VIDEODRIVER=directx");
  *screen = SDL_SetVideoMode(X*32, Y*32, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  return (0);
}
