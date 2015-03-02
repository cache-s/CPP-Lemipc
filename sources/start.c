/*
** start.c for lemipc in /home/cache-_s/rendu/PSU_2014_lemipc/sources
** 
** Made by Sebastien Cache-Delanos
** Login   <cache-_s@epitech.net>
** 
** Started on  Mon Mar  2 12:12:35 2015 Sebastien Cache-Delanos
** Last update Mon Mar  2 18:43:16 2015 Jordan Chazottes
*/

#include			"lemipc.h"

/* typedef struct tmp */
/* { */
/*   int	map[250][250]; */
/* }		tmp; */


int				start(int team)
{
  int		map[250][250];
  key_t		key;
  int		shm_id;
  void		*addr;

  (void)team;
  key = ftok("./", 0);
  printf("Key = %d\n", key);

  if ((shm_id = shmget(key, 42, SHM_R  | SHM_W)) == -1)
    { /* Init */
      memset(map, 0, sizeof(map));
      shm_id = shmget(key, sizeof(map), IPC_CREAT | SHM_R  | SHM_W);
      printf("Created shm segment %d\n", shm_id);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      printf("TMP\n");
      memcpy(addr, map, sizeof(map));
      printf("TMP2\n");
    }
  else
    { /* Init done */
      printf("Using shm segment %d\n", shm_id);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      shmctl(shm_id, IPC_RMID, NULL);
      /*showMap((int**)addr);*/
    }
  return (0);
}
