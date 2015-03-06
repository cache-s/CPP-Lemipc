/*
** main.c for lemi in /home/chazot_a/rendu/local_lemipc/display
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Thu Mar  5 11:00:27 2015 Jordan Chazottes
** Last update Fri Mar  6 19:17:40 2015 Jordan Chazottes
*/

#include	"lemipc.h"

int		main(int ac, char **av)
{
  SDL_Surface	*screen;
  void		*addr;
  (void)ac;
  (void)av;

  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_putenv("SDL_VIDEODRIVER=directx"); 
  screen = SDL_SetVideoMode(X*32, Y*32, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("LemiPC", NULL);
  SDL_WM_SetIcon(IMG_Load("images/favicon.ico"), NULL);
  if ((addr = getShm()) == NULL || eventHandler() == 0)
    return -1;
  resetBackground(addr, screen);
  displayLoop(screen);
  SDL_FreeSurface(screen);
  SDL_Quit();
  return (0);
}
