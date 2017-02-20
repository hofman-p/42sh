/*
** my_put_in_list.c for day12 in /home/mace_j//afs/struct
**
** Made by jeanbaptiste mace
** Login   <mace_j@epitech.net>
**
** Started on  Tue Oct 23 11:50:41 2012 jeanbaptiste mace
** Last update Sun Jun  9 19:18:01 2013 styve simonneau
*/

#include "list.h"

t_list		*add_in_list(t_list *old, char *data)
{
  t_list	*new;

  if (old != 0 && old != NULL && old->next != NULL)
    {
      while (old->next != NULL)
	old = old->next;
      old->next = 0;
    }
  if (!(new = malloc(sizeof(*new))))
    return (old);
  if (old != 0 && old != NULL)
    old->next = new;
  new->next = 0;
  new->prev = old;
  new->data = data;
  return (new);
}

t_list	*changedata(t_list *old, t_util *util)
{
  my_free(util->tableau);
  if ((util->tableau = malloc(sizeof(char ) * 700)) == NULL)
    return (NULL);
  clean_tab(util->tableau, 450);
  copy_str_full(strdup(old->data), util->tableau);
  util->pos = strlen(util->tableau);
  return (old);
}

int	del_chaine(int i)
{
  while (i > 0)
    {
      my_putchar('\b');
      tputs(tgetstr("dc", NULL), 1, stv);
      i = i - 1;
    }
  return (0);
}

t_list		*prev_list(t_list *old, t_util *util)
{
  static int	i = 0;

  if (util->pos < (int)(strlen(util->tableau)))
      move_end(util);
  del_chaine(strlen(util->tableau));
  if (i == 1)
    {
      if (old->prev != NULL)
	old = old->prev;
      my_putstr(old->data);
    }
  if (old != NULL && i == 0)
    {
      i = 1;
      my_putstr(old->data);
    }
  if (changedata(old, util) == NULL)
    return (NULL);
  return (old);
}

t_list	*next_list(t_list *old, t_util *util)
{
  if (util->pos < (int)(strlen(util->tableau)))
      move_end(util);
  del_chaine(strlen(util->tableau));
  if (old->next != NULL)
    old = old->next;
  my_putstr(old->data);
  if (changedata(old, util) == NULL)
    return (NULL);
  util->pos = strlen(old->data);
  return (old);
}
