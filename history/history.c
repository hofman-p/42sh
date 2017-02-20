/*
** history.c for history in /home/mace_j//afs/unix/42sh/history
**
** Made by jeanbaptiste mace
** Login   <mace_j@epitech.net>
**
** Started on  Thu May  2 13:11:40 2013 jeanbaptiste mace
** Last update Sun Jun  9 19:16:44 2013 styve simonneau
*/

#include "list.h"

char	*stock_buffer(char *buffer)
{
  if ((buffer = malloc(5 * sizeof(char))) == NULL)
    return (NULL);
  clean_tab(buffer, 5);
  if (read(0, buffer, 3) <= 0)
    return (NULL);
  return (buffer);
}

t_list		*boucle(t_util *util, t_msh *pt, char *buffer, t_list *list)
{
  if (buffer[0] == '\t')
    {
      auto_complet(util->tableau);
      return (list);
    }
  if (buffer[2] != '\0')
    {
      touche_cd(buffer, util);
      list = touche_ab(buffer, list, util);
    }
  if (util->test == 0 && buffer[1] == '\0')
    {
      if (buffer[0] == 127)
	{
	  if (util->pos > 0)
	    backslash(util);
	}
      else
	{
	  if (strlen(util->tableau) < 257)
	      list = nobackn(buffer, util, list);
	  list = backn(buffer, util, list, pt);
	}
    }
  return (list);
}

int		touche(t_util *util, t_msh *pt)
{
  char		*buffer;
  t_list	*list;

  list = 0;
  my_putstr("$>");
  while (pt->exit >= 256)
    {
      util->test = 0;
      if ((buffer = stock_buffer(buffer)) == NULL)
	return (0);
      if (buffer[0] == 4)
	return (my_error(0));
      if (buffer[0] == 12)
	{
	  tputs(tgetstr("cl", NULL), 1, stv);
	  my_putstr("$>");
	}
      else
	list = boucle(util, pt, buffer, list);
      my_free(buffer);
    }
  return (1);
}

int		save_all(t_msh *pt)
{
  t_util	util;

  if ((util.tableau = malloc(sizeof(char) * 500)) == NULL)
      return (0);
  util.tableau[0] = '\0';
  util.pos = 0;
  util.go_on = 256;
  if (icanon() == -1)
    {
      my_putstr("Initialisation termcap bug\n");
      return (0);
    }
  clean_tab(util.tableau, 300);
  if (touche(&util, pt) == 0)
    return (0);
  return (pt->exit);
}
