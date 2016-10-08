/*
** allu.c for  in /home/belfio_u/rendu/Allum1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Feb  3 00:57:23 2015 ugo belfiore
** Last update Thu Feb 12 20:15:10 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** affiche les images de fond pendant la partie
*/

static void	disp_background(t_data *d)
{
  if (d->a.win == 0)
    if (d->a.play == 1)
      if (d->m.ia == 2)
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.back_1, 0, 0);
      else
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.back_3, 0, 0);
    else
      if (d->m.ia == 2)
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.back_2, 0, 0);
      else
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.back_4, 0, 0);
  else
    if (d->a.play == -1)
      mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.back_5, 0, 0);
    else
      mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.back_6, 0, 0);
  d->m.recy = (576 / d->m.y_file * (d->a.pos));
  d->m.recx = 138 + (d->a.pos2 * 300 / d->m.y_file);
  d->m.recx2 = 1018 - (d->a.pos2 * 300 / d->m.y_file);
  recp(d);
}

/*
** affiche les image de fond pendant la partie
*/

static void	disp_background_ia(t_data *d)
{
  if (d->a.win == 0)
    {
      if (d->a.play == 1)
	{
	  mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.gree_1,
				  d->m.recx, d->m.recy);
	  mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.gree_2,
				  d->m.recx2, d->m.recy);
	}
      else
	{
	  mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.red_1,
				  d->m.recx, d->m.recy);
	  mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.red_2,
				  d->m.recx2, d->m.recy);
	}
    }
}

/*
** fonction d'affichage globale, est appelé au début, à l'expose et à chaque
** évenement clavier.
*/

void	allu_disp(t_data *d)
{
  disp_background(d);
  disp_background_ia(d);
  allu_draw(d);
  if (d->a.help == 1)
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.mini_a, 20, 20);
  else
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.aide, 0, 0);
  if (d->a.lock != 0)
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.del, 870, 20);
  aff_allu_term(d);
}
