/*
** ia_test.c for  in /home/belfio_u/rendu/Allum1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Feb 12 21:19:52 2015 ugo belfiore
** Last update Thu Feb 12 21:25:29 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** fonction de test du xor de l'ia qui déconne...
*/

void    xor_test_hard(t_data *d)
{
  if (d->ia.test3 == 1 && d->ia.test4 == 0 && d->ia.test2 != 0)
    {
      allu_sous(d, d->ia.ligne);
      d->ia.test5 = 1;
    }
  if (d->ia.test4 == 1 && d->ia.test3 == 0)
    {
      d->ia.test5 = 1;
      d->ia.j = -1;
      while (++d->ia.j < d->m.y_file)
        {
          count_one(d, d->ia.j);
          if (d->m.one > 1)
            {
              allu_sous(d, d->ia.j + 1);
              d->ia.j = d->m.y_file;
            }
        }
    }
}

/*
** fonction de test du xor si aucun autre test n'a réussi mais
** que ça plante toujours...
*/

static void	xor_test_if_last_test_are_bad_modulo(t_data *d)
{
  if (d->ia.test7 == 2)
    {
      allu_sous(d, d->ia.test2);
      d->ia.j = -1;
      d->ia.test = 0;
      d->ia.test4 = 0;
      while (++d->ia.j < d->m.y_file)
	{
	  count_one(d, d->ia.j);
	  d->ia.tab[d->ia.j] = d->m.one;
	  if (d->m.one == 1)
	    d->ia.test++;
	  if (d->m.one > 1)
	    d->ia.test4++;
	}
      if ((d->ia.test % 2) != 0 && d->ia.test == 1 && d->ia.test4 > 0)
	allu_add(d, 1, d->ia.test2);
    }
}

void    xor_test_if_last_test_are_bad(t_data *d)
{
  if (d->ia.test5 == 0)
    {
      d->ia.test2 = d->ia.j;
      d->ia.j = -1;
      d->ia.test = 0;
      while (++d->ia.j < d->m.y_file)
        {
          count_one(d, d->ia.j);
          d->ia.tab[d->ia.j] = d->m.one;
          if (d->m.one == 1)
            d->ia.test++;
        }
      if ((d->ia.test % 2) == 0)
        {
          d->ia.j = -1;
          while (++d->ia.j < d->m.y_file)
            {
              count_one(d, d->ia.j);
              d->ia.tab[d->ia.j] = d->m.one;
              if (d->m.one >= 1)
                d->ia.test7++;
            }
	  xor_test_if_last_test_are_bad_modulo(d);
        }
    }
}
