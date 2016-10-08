/*
** rec.c for  in /home/belfio_u/rendu/Allum1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Feb  3 16:46:35 2015 ugo belfiore
** Last update Thu Feb 12 20:07:54 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** rectifie l'alignement des allumettes en fonction du nombre de rangée
*/

void	recp(t_data *d)
{
  d->m.recy += (d->m.y_file == 3) ? -24 : 0;
  d->m.recy += (d->m.y_file == 3) ? -8 : 0;
  d->m.recy += (d->m.y_file == 7) ? 7 : 0;
  d->m.recy += (d->m.y_file > 7) ? 16 : 0;
  d->m.recy += (d->m.y_file > 13) ? 5 : 0;
  d->m.recy += (d->m.y_file == 17) ? 10 : 0;
  d->m.recy += (d->m.y_file >= 17) ? 5 : 0;
}

static void	rec_bis(t_data *d)
{
  d->m.recx += (d->m.y_file == 3) ? 35 : 0;
  d->m.recy += (d->m.y_file == 3) ? 80 : 0;
  d->m.recx += (d->m.y_file == 4) ? 17 : 0;
  d->m.recy += (d->m.y_file == 4) ? 53 : 0;
  d->m.recx += (d->m.y_file == 5) ? 4 : 0;
  d->m.recy += (d->m.y_file == 5) ? 32 : 0;
  d->m.recy += (d->m.y_file == 6) ? 18 : 0;
  d->m.recx += (d->m.y_file == 7) ? -4 : 0;
  d->m.recy += (d->m.y_file == 7) ? 11 : 0;
  d->m.recx += (d->m.y_file == 8) ? -7 : 0;
  d->m.recy += (d->m.y_file == 8) ? 7 : 0;
  d->m.recx += (d->m.y_file == 9) ? -6 : 0;
  d->m.recx += (d->m.y_file == 10) ? -11 : 0;
  d->m.recx += (d->m.y_file == 11) ? -8 : 0;
  d->m.recy += (d->m.y_file == 11) ? -5 : 0;
  d->m.recx += (d->m.y_file == 12) ? -19 : 0;
  d->m.recy += (d->m.y_file == 12) ? -12 : 0;
  d->m.recx += (d->m.y_file == 13) ? -13 : 0;
  d->m.recy += (d->m.y_file == 13) ? -12 : 0;
  d->m.recx += (d->m.y_file == 14) ? -15 : 0;
  d->m.recy += (d->m.y_file == 14) ? -15 : 0;
}

void	rec(t_data *d)
{
  rec_bis(d);
  d->m.recx += (d->m.y_file == 15) ? -13 : 0;
  d->m.recy += (d->m.y_file == 15) ? -15 : 0;
  d->m.recx += (d->m.y_file == 16) ? -22 : 0;
  d->m.recy += (d->m.y_file == 16) ? -19 : 0;
  d->m.recx += (d->m.y_file == 17) ? -12 : 0;
  d->m.recy += (d->m.y_file == 17) ? -12 : 0;
  d->m.recx += (d->m.y_file == 18) ? -16 : 0;
  d->m.recy += (d->m.y_file == 18) ? -22 : 0;
  d->m.recx += (d->m.y_file == 19) ? -18 : 0;
  d->m.recy += (d->m.y_file == 19) ? -22 : 0;
  d->m.recx += (d->m.y_file == 20) ? -18 : 0;
  d->m.recy += (d->m.y_file == 20) ? -19 : 0;
}
