/*
** ia.c for  in /home/belfio_u/rendu/Allum1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Feb  5 07:16:47 2015 ugo belfiore
** Last update Thu Feb 12 21:23:10 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** initialise toute les variable de l'IA
** et prépare à la fin pour que le joueur joue ensuite
*/

static void	init_ia(t_data *d, int i)
{
  if (i == 1)
    {
      d->ia.j = -1;
      d->ia.test = 0;
      d->ia.test2 = 0;
      d->ia.test3 = 0;
      d->ia.test5 = 0;
      d->ia.test6 = 0;
      d->ia.test7 = 0;
      d->ia.xor_total = 0;
      d->ia.allum_s = 0;
      d->ia.ligne = 0;
      d->ia.xxx = 0;
      d->ia.i = -1;
    }
  else
    {
      d->a.lock = 0;
      d->a.play *= -1;
      d->a.sous1 = 0;
      d->a.sous2 = 0;
      d->a.ia_p = 0;
    }
}

/*
** xor de l'ia
*/

static void	xor_ia(t_data *d)
{
  while (++d->ia.j < d->m.y_file)
    {
      count_one(d, d->ia.j);
      d->ia.tab[d->ia.j] = d->m.one;
      d->ia.xor_total = d->ia.xor_total ^ d->ia.tab[d->ia.j];
    }
  if (d->ia.xor_total == 0)
    d->ia.xor_total = 1;
  d->ia.j = -1;
  while (++d->ia.j < d->m.y_file)
    {
      count_one(d, d->ia.j);
      if ((d->m.one ^ d->ia.xor_total) < d->m.one)
        {
          d->ia.xxx = d->m.one - d->ia.xor_total;
          if (d->ia.xxx < 0)
            d->ia.xxx *= -1;
          d->ia.allum_s = d->m.one - d->ia.xxx;
          d->ia.ligne = d->ia.j + 1;
          d->ia.j = d->m.y_file;
        }
    }
}

/*
** xor test
*/

static void	xor_test(t_data *d)
{
  if (d->ia.allum_s == d->m.one)
    d->ia.test2 = 1;
  if (d->ia.allum_s == 1)
    d->ia.test3 = 1;
  if (d->ia.allum_s == 0)
    d->ia.test4 = 1;
  while (++d->ia.i < d->ia.allum_s)
    allu_sous(d, d->ia.ligne);
  d->ia.j = -1;
  while (++d->ia.j < d->m.y_file)
    {
      count_one(d, d->ia.j);
      d->ia.tab[d->ia.j] = d->m.one;
      if (d->m.one == 1)
	d->ia.test++;
    }
}

/*
** xor test modulo
*/

static void	xor_test_modulo(t_data *d)
{
  if ((d->ia.test % 2) == 0 && d->ia.test2 == 0
      && d->ia.test != 0 && d->ia.allum_s <= 2)
    {
      d->ia.j = -1;
      while (++d->ia.j < d->m.y_file)
	{
	  count_one(d, d->ia.j);
	  d->ia.tab[d->ia.j] = d->m.one;
	  if (d->m.one >= 1)
	    d->ia.test6++;
	}
      if (d->ia.test6 < 3)
	allu_sous(d, d->ia.ligne);
      d->ia.test5 = 1;
    }
  else if ((d->ia.test % 2) == 0 && d->ia.test2 == 1)
    {
      allu_add(d, 1, d->ia.ligne);
      d->ia.test5 = 1;
    }
  else if ((d->ia.test % 2) != 0 && d->ia.test2 == 0 && d->ia.allum_s > 2)
    {
      allu_add(d, 2, d->ia.ligne);
      d->ia.test5 = 1;
    }
}

/*
** fonction main de l'IA
*/

void	ia_start(t_data *d)
{
  init_ia(d, 1);
  xor_ia(d);
  xor_test(d);
  xor_test_modulo(d);
  xor_test_hard(d);
  xor_test_if_last_test_are_bad(d);
  test_pos_curs(d, 1);
  init_ia(d, 2);
  allu_disp(d);
}
