/*
** list.h for day12 in /home/mace_j//afs/struct
**
** Made by jeanbaptiste mace
** Login   <mace_j@epitech.net>
**
** Started on  Tue Oct 23 11:36:09 2012 jeanbaptiste mace
** Last update Sun Jun  9 19:19:45 2013 styve simonneau
*/

#ifndef	_LIST_H_
# define _LIST_H_

# include <term.h>
# include <curses.h>
# include <stdlib.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "struct.h"
# include "protos.h"

typedef struct	s_list
{
  char		*data;
  struct s_list	*prev;
  struct s_list	*next;
}		t_list;

typedef struct	s_util
{
  char		*tableau;
  int		pos;
  int		test;
  int		go_on;
}		t_util;

int		save_all(t_msh *pt);
void		decalage_write(char *buffer, t_util *util);
void		aff_fin_str(t_util *util);
void		aff_fin_str2(t_util *util);
void		backslash(t_util *util);
int		raw_mode(struct termios *t);
int		init_term();
int		icanon();
char		*stock_buffer(char *);
int		copy_str(char *str, char *str2, int a);
int		stv(int c);
void		clean_tab(char *str, int nb);
int		del_touch();
t_list		*add_in_list(t_list *old, char *data);
int		del_chaine(int  i);
t_list		*prev_list(t_list *old, t_util *util);
t_list		*next_list(t_list *old, t_util *util);
char		*copy_str_full(char *str, char *str2);
t_list		*backn(char *buffer, t_util *util, t_list *list, t_msh *pt);
t_list		*nobackn(char *buffer, t_util *util, t_list *list);
int		touche_cd(char *buffer, t_util *util);
t_list		*touche_ab(char *buffer, t_list *list, t_util *util);
int		control(t_list *list, t_util *util, char *buffer);
void		move_end(t_util *util);

#endif /* !_LIST_H_ */
