/*
** start.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc/sources
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 12:12:35 2015 Sebastien Cache-Delanos
** Last update Wed Mar  4 10:24:08 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

t_battlefield				initStruct(t_battlefield b)
{
  int				i;
  int				j;

  i = -1;
  while (++i < X)
    {
      j = -1;
      while (++j < Y)
	b.battlefield[i][j] = '.';
    }
  i = -1;
  while (++i < 5)
    b.recap[i] = 0;
  return (b);
}

t_battlefield*				initBattlefield()
{
  t_battlefield			b;
  key_t				key;
  int				shm_id;
  void				*addr;

  key = ftok("/dev", 0);
  if ((shm_id = shmget(key, sizeof(b), SHM_R | SHM_W)) == -1)
    {
      b = initStruct(b);
      shm_id = shmget(key, sizeof(b), IPC_CREAT | SHM_R  | SHM_W);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      memcpy(addr, &b, sizeof(b));
    }
  addr = shmat(shm_id, NULL, SHM_R | SHM_W);
  shmctl(shm_id, IPC_RMID, NULL);
  return ((t_battlefield*)addr);
}

t_warrior*			initWarrior(int army)
{
  t_warrior			*w;

  w = malloc(sizeof(*w));
  if (w != NULL)
    {
      w->id = 0;
      w->state = ALIVE;
      w->posX = 50;
      w->posY = 50;
      w->army = army;
    }
  else
    printf("Malloc fail in initWarrior()\n");
  return (w);
}
