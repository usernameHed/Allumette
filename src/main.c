/*
** main.c for  in /home/belfio_u/rendu/MUL_2014_wolf3d
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Dec  5 17:23:50 2014 ugo belfiore
** Last update Thu Feb 12 18:20:18 2015 ugo belfiore
*/

#include "../include/my.h"
#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"

int		main()
{
  t_data	d;
  extern char	**environ;

  if (environ[0] == NULL)
    return (-1);
  d.m.mod = 1;
  d.m.ia = 1;
  d.m.row = 3;
  aff_win(&d);
  return (0);
}
