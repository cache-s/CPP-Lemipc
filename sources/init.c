/*
** start.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc/sources
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 12:12:35 2015 Sebastien Cache-Delanos
** Last update Tue Mar  3 19:43:19 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

t_battlefield*				initBattlefield()
{
  t_battlefield			b;
  key_t				key;
  int				shm_id;
  void				*addr;
  int				i;
  int				j;

  i = 0;
  j = 0;
  key = ftok("/dev", 0);
  printf("Key = %d\n", key);
  if ((shm_id = shmget(key, sizeof(b), SHM_R | SHM_W)) == -1)
    {
      for (i = 0; i < X; ++i)
	for (j = 0; j < Y; ++j)
	  b.battlefield[i][j] = '.';
      shm_id = shmget(key, sizeof(b), IPC_CREAT | SHM_R  | SHM_W);
      printf("Created shm segment %d\n", shm_id);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      memcpy(addr, b.battlefield, sizeof(b.battlefield));
    }
  printf("Using shm segment %d\n", shm_id);
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
