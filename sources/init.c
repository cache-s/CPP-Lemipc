/*
** start.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc/sources
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 12:12:35 2015 Sebastien Cache-Delanos
** Last update Tue Mar  3 11:05:50 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

t_map*				initMap()
{
  t_map				s;
  key_t				key;
  int				shm_id;
  void				*addr;
  int				i;
  int				j;

  i = 0;
  j = 0;
  key = ftok("/dev", 0);
  printf("Key = %d\n", key);
  if ((shm_id = shmget(key, sizeof(s), SHM_R | SHM_W)) == -1)
    {
      for (i = 0; i < X; ++i)
	for (j = 0; j < Y; ++j)
	  s.map[i][j] = '.';
      shm_id = shmget(key, sizeof(s), IPC_CREAT | SHM_R  | SHM_W);
      printf("Created shm segment %d\n", shm_id);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      memcpy(addr, s.map, sizeof(s.map));
      return (NULL);
    }
  printf("Using shm segment %d\n", shm_id);
  addr = shmat(shm_id, NULL, SHM_R | SHM_W);
  shmctl(shm_id, IPC_RMID, NULL);
  return ((t_map*)addr);
}

t_player*			initPlayer(int team)
{
  t_player			*p;

  p = malloc(sizeof(*p));
  if (p != NULL)
    {
      p->id = 0;
      p->state = ALIVE;
      p->posX = 50;
      p->posY = 50;
      p->team = team;
    }
  else
    printf("Malloc fail in initPlayer()\n");
  return (p);
}
