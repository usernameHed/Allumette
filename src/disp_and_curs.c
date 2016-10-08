/*
** disp_and_curs.c for  in /home/belfio_u/rendu/Allum1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Feb 12 19:40:42 2015 ugo belfiore
** Last update Thu Feb 12 20:16:35 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** s'il y a une seul allumette dans une rangée, retourne 1
*/

int	test_one(t_data *d, int j)
{
  int	i;

  i = -1;
  while (++i < d->m.x_file)
    if (d->m.tab[j][i] == 1)
      return (1);
  return (0);
}

/*
** test la position du curseur
*/

void	test_pos_curs(t_data *d, int uu)
{
  int	wii;

  wii = 0;
  while (!test_one(d, d->a.pos - 1) && wii < 21)
    {
      wii++;
      d->a.pos += (uu == 1) ? -1 : 1;
      d->a.pos2 += (uu == 1) ? 1 : -1;
      d->a.pos = (d->a.pos < 1) ? d->m.y_file : d->a.pos;
      d->a.pos = (d->a.pos > d->m.y_file) ? 1 : d->a.pos;
      d->a.pos2 = (d->a.pos2 < 1) ? d->m.y_file : d->a.pos2;
      d->a.pos2 = (d->a.pos2 > d->m.y_file) ? 1 : d->a.pos2;
    }
  if (wii >= 21)
    {
      d->a.win = 1;
      d->a.help = 1;
      d->a.play *= -1;
    }
}

/*
** affiche la deuxieme partie sur le term
*/

static void	aff_allu_two(t_data *d, int i, int j)
{
  while (++i < d->m.x_file)
    {
      if (d->m.tab[j][i] == 0)
	my_printf(" ");
      else
	my_printf("|");
    }
  if (d->a.pos == j + 1)
    {
      if (d->a.play == 1)
	my_printf("%s<%s\n", "\e[92m", "\e[0m");
      else
	my_printf("%s<%s\n", "\e[91m", "\e[0m");
    }
  else
    my_printf(" \n");
}

/*
** affiche sur le term
*/

void    aff_allu_term(t_data *d)
{
  int   j;
  int   i;

  i = -1;
  j = -1;
  my_printf("\033[H\033[2J");
  while (++j < d->m.y_file)
    {
      if (d->a.pos == j + 1)
        {
          if (d->a.play == 1)
            my_printf("%s>%s", "\e[92m", "\e[0m");
          else
            my_printf("%s>%s", "\e[91m", "\e[0m");
        }
      else
        my_printf(" ");
      aff_allu_two(d, i, j);
      i = -1;
    }
}

