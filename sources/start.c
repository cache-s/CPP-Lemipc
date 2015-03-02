/*
** start.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc/sources
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 12:12:35 2015 Sebastien Cache-Delanos
** Last update Mon Mar  2 17:18:21 2015 Jordan Chazottes
*/

#include			"lemipc.h"

int				start(int team)
{
  int		map[250][250];
  key_t		key;
  int		shm_id;
  void		*addr;

  (void)team;
  key = ftok("_KEY", 0);
  printf("Key = %d\n", key);

  if ((shm_id = shmget(key, 42, SHM_R  | SHM_W)) == -1)
    { /* Init */
      memset(map, 0, sizeof(map));
      shm_id = shmget(key, 42, IPC_CREAT | SHM_R  | SHM_W);
      printf("Created shm segment %d\n", shm_id);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      memcpy(addr, map, sizeof(map));
      //      (int**)addr = map;
    }
  else
    { /* Init done */
      printf("Using shm segment %d\n", shm_id);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      showMap((int**)addr);
      shmctl(shm_id, IPC_RMID, NULL);
    }
  return (0);
}
