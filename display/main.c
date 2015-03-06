/*
** main.c for lemi in /home/chazot_a/rendu/local_lemipc/display
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Thu Mar  5 11:00:27 2015 Jordan Chazottes
** Last update Fri Mar  6 10:51:40 2015 Jordan Chazottes
*/

#include	"lemipc.h"

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
  SDL_Rect offset;
 
  offset.x = x;
  offset.y = y;
 
  //On blitte la surface
  SDL_BlitSurface(source, clip, destination, &offset);
}

void		createSprite(void *addr, int i, int j, SDL_Surface *screen)
{
  SDL_Rect	clip[5];
  SDL_Surface	*clp;

  clp = IMG_Load("display/sprites.png");
  if (clp == NULL)
    {
      printf("\n\nTAMERE\n\n");
    }
  clip[0].x = 0;
  clip[0].y = 0;
  clip[0].w = 32;
  clip[0].h = 32;

  clip[1].x = 0;
  clip[1].y = 32;
  clip[1].w = 32;
  clip[1].h = 32;

  clip[2].x = 0;
  clip[2].y = 64;
  clip[2].w = 32;
  clip[2].h = 32;

  clip[3].x = 0;
  clip[3].y = 96;
  clip[3].w = 32;
  clip[3].h = 32;

  clip[4].x = 0;
  clip[4].y = 128;
  clip[4].w = 32;
  clip[4].h = 32;

  if (((t_battlefield*)addr)->battlefield[i][j] == '1')
    apply_surface(i*32, j*32, clp, screen, &clip[0]);
  if (((t_battlefield*)addr)->battlefield[i][j] == '2')
    apply_surface(i*32, j*32, clp, screen, &clip[1]);
  if (((t_battlefield*)addr)->battlefield[i][j] == '3')
    apply_surface(i*32, j*32, clp, screen, &clip[2]);
  if (((t_battlefield*)addr)->battlefield[i][j] == '4')
    apply_surface(i*32, j*32, clp, screen, &clip[3]);
  if (((t_battlefield*)addr)->battlefield[i][j] == '5')
    apply_surface(i*32, j*32, clp, screen, &clip[4]);
}

void		createRect(void *addr, int i, int j, SDL_Surface *screen)
{
  SDL_Surface	*rectangle;
  SDL_Rect	pos;

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
  if (((t_battlefield*)addr)->battlefield[i][j] == '1')
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 9, 0, 255));
  if (((t_battlefield*)addr)->battlefield[i][j] == '2')
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 87, 255, 0));
  if (((t_battlefield*)addr)->battlefield[i][j] == '3')
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 125, 125, 125));
  if (((t_battlefield*)addr)->battlefield[i][j] == '4')
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 255, 0, 15));
  if (((t_battlefield*)addr)->battlefield[i][j] == '5')
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 30, 84, 6));
  pos.x = i * 10;
  pos.y = j * 10;
  SDL_BlitSurface(rectangle, NULL, screen, &pos);
}

int		eventHandler()
{
  SDL_Event	event;

  while(SDL_PollEvent(&event))
    { 
      if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
	return (0);
      if (event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_UP)
	    printf("UP\n");
	  if (event.key.keysym.sym == SDLK_DOWN)
	    printf("DOWN\n");
	  if (event.key.keysym.sym == SDLK_LEFT)
	    printf("LEFT\n");
	  if (event.key.keysym.sym == SDLK_RIGHT)
	    printf("RIGHT\n");
	}
    }
  return (1);
}

void		*getShm()
{
  key_t		key;
  int		shm_id;

  key = ftok("/dev", 0);
  shm_id = shmget(key, sizeof(t_battlefield), SHM_R);
  //  printf("Shm_Id = %d\n", shm_id);
  return (shmat(shm_id, NULL, SHM_R));
}

void		displayLoop(SDL_Surface *screen)
{
  int i;
  int j;
  void	*addr;

  while (42)
    {
      i = 0;  
      addr = getShm();
      if (eventHandler() == 0)
      	return;
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 122, 122, 122));      
      while (i < X)
	{
	  j = 0;
	  while (j < Y)
	    {
	      if (((t_battlefield*)addr)->battlefield[i][j] != '.')
		createSprite(addr, i, j, screen);
	      /* createRect(addr, i , j, screen); */
	      ++j;
	    }
	  ++i;
	}
      SDL_Flip(screen);
    }
}

int		main(int ac, char **av)
{
  SDL_Surface	*screen;
  (void)ac;
  (void)av;

  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_putenv("SDL_VIDEODRIVER=directx"); 
  screen = SDL_SetVideoMode(X*32, Y*32, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption( "LemiPC", "favicon");
  displayLoop(screen);
  SDL_Quit();
  return (0);
}
