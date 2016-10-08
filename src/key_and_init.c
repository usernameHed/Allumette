/*
** key_no_ia.c for  in /home/belfio_u/rendu/Allum1/src
**
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
**
** Started on  Thu Feb 12 18:45:09 2015 ugo belfiore
** Last update Thu Feb 12 20:54:51 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** key_hook d'action de jeu (action ou annuler l'action)
*/

static void	key_action(t_data *d, int keycode)
{
  if (keycode == KEY_BACKUP && d->a.lock != 0)
    {
      allu_add(d, d->a.lock, d->a.pos);
      d->a.lock = 0;
      if (d->a.play == 1)
	d->a.sous1 = 0;
      else
	d->a.sous2 = 0;
    }
  if (keycode == KEY_ENTER && d->a.safe == 1 && d->a.lock > 0)
    {
      test_pos_curs(d, 1);
      d->a.lock = 0;
      d->a.play *= -1;
      d->a.sous1 = 0;
      d->a.sous2 = 0;
      if (d->a.play == -1 && d->m.ia == 1)
	d->a.ia_p = 1;
    }
  d->a.safe = 1;
}

/*
** key_hook de déplacement haut/bas
*/

static void	key_move(t_data *d, int keycode)
{
  if (keycode == KEY_UP && d->a.lock == 0)
    {
      d->a.pos--;
      d->a.pos2++;
      d->a.pos = (d->a.pos < 1) ? d->m.y_file : d->a.pos;
      d->a.pos = (d->a.pos > d->m.y_file) ? 1 : d->a.pos;
      d->a.pos2 = (d->a.pos2 < 1) ? d->m.y_file : d->a.pos2;
      d->a.pos2 = (d->a.pos2 > d->m.y_file) ? 1 : d->a.pos2;
      test_pos_curs(d, 1);
    }
  if (keycode == KEY_DOWN && d->a.lock == 0)
    {
      d->a.pos++;
      d->a.pos2--;
      d->a.pos = (d->a.pos < 1) ? d->m.y_file : d->a.pos;
      d->a.pos = (d->a.pos > d->m.y_file) ? 1 : d->a.pos;
      d->a.pos2 = (d->a.pos2 < 1) ? d->m.y_file : d->a.pos2;
      d->a.pos2 = (d->a.pos2 > d->m.y_file) ? 1 : d->a.pos2;
      test_pos_curs(d, 2);
    }
}

/*
** evenement clavier qui sont activé uniquement si le joueur est en train de
** jouer (si l'ia ne joue pas).
*/

void	key_no_ia(t_data *d, int keycode)
{
  key_action(d, keycode);
  key_move(d, keycode);
  if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
    {
      d->a.lock++;
      if (d->a.play == 1)
	d->a.sous1++;
      else
	d->a.sous2++;
      allu_sous(d, d->a.pos);
    }
}

/*
** initialise lors de l'appruis sur certaine touche
*/

void	init_data_key(t_data *d, int i)
{
  free(d->m.tab);
  if (i == 1)
    {
      d->m.row++;
      d->m.row = (d->m.row > 20) ? 20 : d->m.row;
    }
  if (i == 2)
    {
      d->m.row--;
      d->m.row = (d->m.row < 3) ? 3 : d->m.row;
    }
  tab_init(d);
  d->a.play = 1;
  d->a.lock = 0;
  d->a.pos = d->m.row;
  d->a.pos2 = 1;
  d->a.sous1 = 0;
  d->a.sous2 = 0;
  d->a.win = 0;
  d->a.ia_p = 0;
  pic_init(d);
}

/*
** initialise le tableau !
*/

void    tab_init(t_data *d)
{
  int   j;
  int   i;
  int   dark;
  int   white;

  i = -1;
  j = -1;
  d->m.y_file = d->m.row;
  d->m.x_file = 1 + 2 * (d->m.row - 1);
  d->m.tab = malloc(d->m.y_file * sizeof(*d->m.tab));
  (d->m.tab == NULL) ? exit(0) : 1;
  while (++j < d->m.y_file)
    {
      d->m.tab[j] = malloc(d->m.x_file * sizeof(**d->m.tab));
      (d->m.tab[j] == NULL) ? exit(0) : 1;
      dark = d->m.y_file - 1 - j;
      white = 1 + 2 * j;
      while (++i < d->m.x_file)
	d->m.tab[j][i] = (i < dark || i >= dark + white) ? 0 : 1;
      i = -1;
    }
}
