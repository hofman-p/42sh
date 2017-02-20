/*
** touche.c for touche in /home/mace_j//afs/unix/42sh/history
**
** Made by jeanbaptiste mace
** Login   <mace_j@epitech.net>
**
** Started on  Mon May  6 13:36:41 2013 jeanbaptiste mace
** Last update Sat Jun  8 14:47:14 2013 jeanbaptiste mace
*/

#include "list.h"

t_list	*backn(char *buffer, t_util *util, t_list *list, t_msh *pt)
{
  if (buffer[0] == '\n')
    {
      if ((list = add_in_list(list, strdup(util->tableau))) == NULL)
	return (NULL);
      util->go_on = qdxsh(pt, util->tableau);
      fflush(stdout);
      if (pt->exit >= 256)
	my_putstr("$>");
      if ((util->tableau = malloc (sizeof(char) * 700)) == NULL)
	return (NULL);
      clean_tab(util->tableau, 300);
      util->pos = 0;
    }
  return (list);
}

t_list	*nobackn(char *buffer, t_util *util, t_list *list)
{
  if (buffer[0] != '\n')
    {
      if (buffer[0] == '\t')
	return (0);
      if (util->tableau[util->pos] != '\0')
	decalage_write(buffer, util);
      else
        {
          my_putchar(buffer[0]);
          copy_str(buffer, util->tableau, util->pos);
          util->pos = util->pos + 1;
        }
    }
  return (list);
}

int	touche_cd(char *buffer, t_util *util)
{
  if (buffer[2] == 'C')
    {
      util->test = 1;
      if ((int)strlen(util->tableau) > util->pos)
        {
          tputs(tgetstr("nd", NULL), 1, stv);
          util->pos = util->pos + 1;
        }
    }
  else if (buffer[2] == 'D')
    {
      util->test = 1;
      if (util->pos > 0)
        {
          tputs(tgetstr("le", NULL), 1, stv);
          util->pos = util->pos - 1;
        }
    }
  return (0);
}

t_list  *touche_ab(char *buffer, t_list *list, t_util *util)
{
  if (buffer[2] == 'A')
    {
      util->test = 1;
      if (list != 0)
	if ((list = prev_list(list, util)) == NULL)
	  return (NULL);
    }
  else if (buffer[2] == 'B')
    {
      util->test = 1;
      if (list != 0)
	if ((list = next_list(list, util)) == NULL)
	  return (NULL);
    }
  return (list);
}

int    control(t_list *list, t_util *util, char *buffer)
{
  if (buffer[1] == 'C')
    {
      my_free(util->tableau);
      my_free(list);
      return (1);
    }
  return (0);
}
