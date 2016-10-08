/*
** mini.h for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct 28 09:26:37 2014 ugo belfiore
** Last update Thu Feb 12 21:21:55 2015 ugo belfiore
*/

#ifndef MINI_H_
#define MINI_H_

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <time.h>
#include "fmod.h"

/*
** define: couleur en hexadécimale.
*/

#define COLOR_YELLOW 0xFFFF00
#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xFFFFFF
#define COLOR_RED 0xFF0000
#define COLOR_GREEN 0x33FF00
#define COLOR_PURPLE 0xFF00FF
#define COLOR_BLUE 0x0033FF

/*
** define: clavier.
*/

#define KEY_ENTER 65293
#define KEY_ESC 65307
#define KEY_REFRESH 65471
#define KEY_KILL 107
#define KEY_RIGHT 65363
#define KEY_LEFT 65361
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_MORE 65365
#define KEY_LESS 65366
#define KEY_BACKUP 65288
#define KEY_HELP 65470
#define KEY_IA 105
#define KEY_S 115

/*
** macro utiles
*/

#define MAX(a,b) ((a) > (b)) ? (a) : (b)
#define MIN(a,b) ((a) < (b)) ? (a) : (b)
#define PI 3.14159265

/*
** stucture des variables pour les différents mod
*/

typedef struct	s_mod
{
  int		mod;
  int		ia;
  int		row;
  int		ret;
  char		buff[40960];
  char		**tab;
  int		x_file;
  int		y_file;
  int		recx;
  int		recy;
  int		recx2;
  int		z_left;
  int		z_right;
  int		one;
}		t_mod;

/*
** structure son
*/

typedef struct	s_sound
{
  FMOD_SYSTEM	*system;
  FMOD_SOUND	*intro;
}		t_sound;

/*
** structure images
*/

typedef struct	s_pic
{
  void		*back_1;
  void		*back_2;
  void		*back_3;
  void		*back_4;
  void		*back_5;
  void		*back_6;
  void		*allu_1;
  void		*allu_2;
  void		*gree_1;
  void		*gree_2;
  void		*red_1;
  void		*red_2;
  void		*aide;
  void		*mini_a;
  void		*allu_r;
  void		*allu_g;
  void		*del;
  int		save1;
  int		save2;
}		t_pic;

typedef struct	s_pop
{
  int		i;
  int		j;
  int		pop;
  int		pop2;
  int		imp;
}		t_pop;

/*
** structure du jeu
*/

typedef struct	s_allu
{
  int		play;
  int		pos;
  int		pos2;
  int		safe;
  int		lock;
  int		sous1;
  int		sous2;
  int		help;
  int		win;
  int		ia_p;
}		t_allu;

/*
** structure ia
*/

typedef struct	s_ia
{
  int		tab[20];
  int		j;
  int		xor_total;
  int		ligne;
  int		i;
  int		allum_s;
  int		test;
  int		test2;
  int		test3;
  int		test4;
  int		test5;
  int		test6;
  int		test7;
  int		xxx;
}		t_ia;

/*
** data: structure principale contenant les pointeurs
**	de fenêtreet d'image, contient le tableau **tab,
*/

typedef struct	s_data
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*bigData;
  int		x_max;
  int		y_max;
  int		colo;
  int		bpp;
  int		sizeline;
  int		end;
  t_sound	sd;
  t_mod		m;
  t_pic		p;
  t_allu	a;
  t_pop		po;
  t_ia		ia;
}               t_data;

/*
** fonction divers.
*/

void	aff_allu_term(t_data *d);
void	test_pos_curs(t_data *d, int uu);
int	test_one(t_data *d, int j);
void	recp(t_data *d);
void	rec(t_data *d);
void	allu_draw(t_data *d);
void	tab_init(t_data *d);
void	allu_disp(t_data *d);
void	aff_win(t_data *d);
void	aff_pix_img(t_data *d, int x, int y);
void	aff_rec(t_data *d, int x1, int y1, int x2, int y2);

void	pic_init(t_data *d);
void	sound_init(t_data *d);
void	quitt(t_data *d);

/*
** fonction action
*/

void	allu_sous(t_data *d, int pos);
void	allu_add(t_data *d, int nbr, int pos);
void	add_one(t_data *d, int j);
void	less_one(t_data *d, int j);
void	count_one(t_data *d, int j);

/*
** fonction key hook
*/

void	key_no_ia(t_data *d, int keycode);
void	init_data_key(t_data *d, int i);

/*
** ia
*/

void	ia_start(t_data *d);
void	xor_test_hard(t_data *d);
void	xor_test_if_last_test_are_bad(t_data *d);

/*
** fonction evenement minilibix
*/

int	manage_key(int keycode, void *param);
int	manage_expose(void *param);

#endif
