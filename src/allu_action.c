/*
** allu_action.c for  in /home/belfio_u/rendu/Allum1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Feb 12 19:25:52 2015 ugo belfiore
** Last update Thu Feb 12 19:38:05 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** enleve une allumette a la bonne ligne
*/

void	less_one(t_data *d, int j)
{
  int	i;
  int	test;

  i = -1;
  test = 0;
  while (++i < d->m.x_file)
    {
      if (test == 0 && d->m.tab[j][i] == 1)
        {
          test = 1;
          if (d->m.z_left == d->m.z_right)
            d->m.tab[j][i] = 0;
          else
            test = 2;
        }
      if (test == 2 && d->m.tab[j][i] == 0)
        d->m.tab[j][i - 1] = 0;
      if (test == 2 && i + 1 == d->m.x_file)
        d->m.tab[j][i] = 0;
    }
}

/*
** ajoute les allumette à la bonne ligne
*/

void	add_one(t_data *d, int j)
{
  int	i;
  int	test;

  i = -1;
  test = 0;
  while (++i < d->m.x_file)
    {
      if (test == 0 && d->m.tab[j][i] == 1)
        {
          test = 1;
          if (d->m.z_left != d->m.z_right)
            d->m.tab[j][i - 1] = 1;
          else
            test = 2;
        }
      if (test == 2 && d->m.tab[j][i] == 0)
        {
          d->m.tab[j][i] = 1;
          test = 3;
        }
    }
  if (test == 0)
    d->m.tab[j][d->m.x_file / 2] = 1;
}

/*
** ajjoute NBR allumette
*/

void	allu_add(t_data *d, int nbr, int pos)
{
  int	j;
  int	ti;

  j = -1;
  ti = -1;
  while (++j < d->m.y_file)
    {
      if (j + 1 == pos)
        {
          while (++ti < nbr)
            {
              count_one(d, j);
              add_one(d, j);
            }
        }
    }
}

/*
** soustrait une allumette
*/

void	allu_sous(t_data *d, int pos)
{
  int	j;

  j = -1;
  while (++j < d->m.y_file)
    {
      if (j + 1 == pos)
        {
          if (!test_one(d, j))
            {
              d->a.lock--;
              d->a.sous1--;
            }
          else
            {
              count_one(d, j);
              less_one(d, j);
            }
        }
    }
}

/*
** compte le nombre de 0 à gauche, à droite et le nombre d'allu au centre
*/

void	count_one(t_data *d, int j)
{
  int	i;
  int	test;

  i = -1;
  test = 0;
  d->m.z_left = 0;
  d->m.z_right = 0;
  d->m.one = 0;
  while (++i < d->m.x_file)
    {
      if (test == 0 && d->m.tab[j][i] == 0)
        d->m.z_left++;
      if (test == 0 && d->m.tab[j][i] == 1)
        test = 1;
      if (test == 1 && d->m.tab[j][i] == 0)
        d->m.z_right++;
      if (d->m.tab[j][i] == 1)
        d->m.one++;
    }
}
