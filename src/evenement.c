/*
** evenement.c for  in /home/belfio_u/rendu/Allum1
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Feb  2 18:47:55 2015 ugo belfiore
** Last update Thu Feb 12 19:19:42 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** evenememnt clavier
*/

int		manage_key(int keycode, void *param)
{
  t_data	*d;

  d = (t_data *)param;
  if (!(d->m.ia == 1 && d->a.play == -1))
    key_no_ia(d, keycode);
  if (keycode == KEY_KILL || keycode == KEY_ESC)
    quitt(d);
  if (keycode == KEY_REFRESH)
    init_data_key(d, 0);
  if (keycode == KEY_MORE && d->m.row <= 20)
    init_data_key(d, 1);
  if (keycode == KEY_LESS && d->m.row > 3)
    init_data_key(d, 2);
  if (keycode == KEY_HELP)
    d->a.help *= -1;
  if (keycode == KEY_IA)
    {
      d->m.ia = (d->m.ia == 1) ? 2 : 1;
      init_data_key(d, 0);
    }
  allu_disp(d);
  if (d->a.ia_p == 1)
    ia_start(d);
  return (0);
}

/*
** evenement expose
** est appelé dès que la fenêtre à besoin d'être recalculé
*/

int		manage_expose(void *param)
{
  t_data	*d;

  d = (t_data *)param;
  allu_disp(d);
  return (0);
}

/*
** c'est ici que s'opère toute les opérations de la fenêtre
** la boucle loop se répète et appelera tout les évenement nécessaire.
*/

void		aff_win(t_data *d)
{
  d->x_max = 1200;
  d->y_max = 900;
  d->a.safe = 0;
  d->a.lock = 0;
  d->a.sous1 = 0;
  d->a.sous2 = 0;
  d->a.help = 1;
  d->a.win = 0;
  d->a.ia_p = 0;
  d->mlx_ptr = mlx_init();
  if (d->mlx_ptr == NULL)
    exit(0);
  d->win_ptr = mlx_new_window(d->mlx_ptr, d->x_max, d->y_max, "allumulla");
  d->img_ptr = mlx_new_image(d->mlx_ptr, d->x_max, d->y_max);
  d->bigData = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->sizeline, &d->end);
  tab_init(d);
  d->a.play = 1;
  d->a.pos = d->m.row;
  d->a.pos2 = 1;
  pic_init(d);
  sound_init(d);
  allu_disp(d);
  mlx_expose_hook(d->win_ptr, &manage_expose, (void *)(d));
  mlx_hook(d->win_ptr, 3, 3, &manage_key, (void *)(d));
  mlx_loop(d->mlx_ptr);
}
