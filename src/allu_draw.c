/*
** allu_draw.c for  in /home/belfio_u/rendu/Allum1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Feb 12 19:50:32 2015 ugo belfiore
** Last update Thu Feb 12 20:06:15 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
**test si c'est lock ou pas pour allumette rouge/vert ou normal
*/

static void	draw_pic_unlock(t_data *d)
{
  if (d->po.j + 1 != d->a.pos)
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			    d->p.allu_1,
			    d->m.recx + (d->po.i * d->po.pop) - d->po.imp,
			    d->m.recy + (d->po.j * d->po.pop2));
  else
    {
      if (d->a.play == 1)
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
				d->p.allu_g,
				d->m.recx + (d->po.i * d->po.pop) - d->po.imp,
				d->m.recy + (d->po.j * d->po.pop2));
      else
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
				d->p.allu_r,
				d->m.recx + (d->po.i * d->po.pop) - d->po.imp,
				d->m.recy + (d->po.j * d->po.pop2));
    }
}

static void	draw_pic_pos(t_data *d)
{
  if (d->a.lock == 0)
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.allu_1,
			    d->m.recx + (d->po.i * d->po.pop) - d->po.imp,
			    d->m.recy + (d->po.j * d->po.pop2));
  else
    draw_pic_unlock(d);
}

/*
** draw les allumettes
*/

void    allu_draw(t_data *d)
{
  d->po.i = -1;
  d->po.j = -1;
  d->po.imp = 0;
  d->m.recx = 265;
  d->m.recy = 50;
  d->po.pop = 713 / d->m.x_file;
  d->po.pop2 = 576 / d->m.y_file;
  rec(d);
  while (++d->po.j < d->m.y_file)
    {
      while (++d->po.i < d->m.x_file)
        {
          count_one(d, d->po.j);
	  d->po.imp = (d->m.z_left != d->m.z_right) ? d->po.pop / 2 : 0;
          if (d->m.tab[d->po.j][d->po.i] == 1)
	    draw_pic_pos(d);
        }
      d->po.i = -1;
    }
}
