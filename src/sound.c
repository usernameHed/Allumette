/*
** sound.c for  in /home/belfio_u/rendu/Allum1
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Feb  2 18:53:38 2015 ugo belfiore
** Last update Wed Feb 11 08:05:31 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** focntion qui initialise les sons.
*/

void	sound_init(t_data *d)
{
  FMOD_System_Create(&d->sd.system);
  FMOD_System_Init(d->sd.system, 1, FMOD_INIT_NORMAL, NULL);
  FMOD_System_CreateSound(d->sd.system, "./texture/sound/intro_island.wav",
  				 FMOD_CREATESAMPLE, 0, &d->sd.intro);

  FMOD_Sound_SetLoopCount(d->sd.intro, -1);
  FMOD_System_PlaySound(d->sd.system, FMOD_CHANNEL_FREE,
			d->sd.intro, 0, NULL);
}

/*
** fonction echap qui clean et free ce qu'il y a à free.
*/

void	quitt(t_data *d)
{
  FMOD_Sound_Release(d->sd.intro);
  FMOD_System_Close(d->sd.system);
  FMOD_System_Release(d->sd.system);
  mlx_destroy_window(d->mlx_ptr, d->win_ptr);
  exit(1);
}
