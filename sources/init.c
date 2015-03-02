/*
** start.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc/sources
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 12:12:35 2015 Sebastien Cache-Delanos
** Last update Mon Mar  2 19:32:06 2015 Sebastien Cache-Delanos
*/

#include			"lemipc.h"

int				initMap()
{
  t_struct	s;
  key_t		key;
  int		shm_id;
  void		*addr;
  int		i;
  int		j;

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
    }
  else
    {
      printf("Using shm segment %d\n", shm_id);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      shmctl(shm_id, IPC_RMID, NULL);
      showMap((t_struct*)addr);
    }
  return (0);
}
