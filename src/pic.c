/*
** pic.c for  in /home/belfio_u/rendu/Allum1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Feb 12 19:17:22 2015 ugo belfiore
** Last update Thu Feb 12 19:24:43 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"
/*
** normize
*/

static void	pic_one(t_data *d)
{
  d->p.back_1 = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/back_1.xpm",
				      &d->p.save1, &d->p.save2);
  d->p.back_2 = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/back_2.xpm",
				      &d->p.save1, &d->p.save2);
  d->p.back_3 = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/back_3.xpm",
				      &d->p.save1, &d->p.save2);
  d->p.back_4 = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/back_4.xpm",
				      &d->p.save1, &d->p.save2);
  d->p.back_5 = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/back_5.xpm",
				      &d->p.save1, &d->p.save2);
  d->p.back_6 = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/back_6.xpm",
				      &d->p.save1, &d->p.save2);
  d->p.allu_1 = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/allu_1.xpm",
                                      &d->p.save1, &d->p.save2);
  d->p.allu_2 = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/allu_2.xpm",
                                      &d->p.save1, &d->p.save2);
  d->p.gree_1 = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/gree_1.xpm",
                                      &d->p.save1, &d->p.save2);
  d->p.gree_2 = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/gree_2.xpm",
                                      &d->p.save1, &d->p.save2);
  d->p.red_1 = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/red_1.xpm",
				     &d->p.save1, &d->p.save2);
  d->p.red_2 = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/red_2.xpm",
				     &d->p.save1, &d->p.save2);
}

/*
** test des erreur des initialisation des picture
*/

static void	pic_error(t_data *d)
{
  (!d->p.back_1) ? quitt(d) : 1;
  (!d->p.back_2) ? quitt(d) : 1;
  (!d->p.back_3) ? quitt(d) : 1;
  (!d->p.back_4) ? quitt(d) : 1;
  (!d->p.back_5) ? quitt(d) : 1;
  (!d->p.back_6) ? quitt(d) : 1;
  (!d->p.allu_1) ? quitt(d) : 1;
  (!d->p.allu_2) ? quitt(d) : 1;
  (!d->p.gree_1) ? quitt(d) : 1;
  (!d->p.gree_2) ? quitt(d) : 1;
  (!d->p.red_1) ? quitt(d) : 1;
  (!d->p.red_2) ? quitt(d) : 1;
  (!d->p.aide) ? quitt(d) : 1;
  (!d->p.mini_a) ? quitt(d) : 1;
  (!d->p.allu_r) ? quitt(d) : 1;
  (!d->p.allu_g) ? quitt(d) : 1;
  (!d->p.del) ? quitt(d) : 1;
}

/*
** initialise les imags du jeu
*/

void	pic_init(t_data *d)
{
  pic_one(d);
  d->p.aide = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/aide.xpm",
				    &d->p.save1, &d->p.save2);
  d->p.mini_a = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/mini_a.xpm",
                                      &d->p.save1, &d->p.save2);
  d->p.allu_r = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/allu_r.xpm",
                                      &d->p.save1, &d->p.save2);
  d->p.allu_g = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/allu_g.xpm",
                                      &d->p.save1, &d->p.save2);
  d->p.del = mlx_xpm_file_to_image(d->mlx_ptr,"./texture/pic/del.xpm",
				   &d->p.save1, &d->p.save2);
  pic_error(d);
}
