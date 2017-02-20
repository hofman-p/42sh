/*
** get_alias.c for 42 in /home/simonn_s//svn/42sh-2017-simonn_s
** 
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
** 
** Started on  Tue Jun  4 03:30:16 2013 styve simonneau
** Last update Tue Jun  4 21:06:19 2013 styve simonneau
*/

#include "protos.h"
#include "error.h"

int	cut_alias(t_msh *pt, char **tab, char **alias, char **cmd)
{
  char	*s;
  int	i;

  i = -1;
  if (!(s = get_line(tab, 0)))
    return (0);
  if (s[++i] == '"')
    *alias = get_alias(s, &i, 1, *alias);
  else
    *alias = get_alias(s, &i, 0, *alias);
  if (s[++i] == '"')
    *cmd = get_alias(s, &i, 1, *cmd);
  else
    *cmd = get_alias(s, &i, 0, *cmd);
  if (!(pt->alias = realloc(pt->alias, (++pt->nb_alias + 1) * sizeof(char ***))))
    return (my_error(1));
  pt->alias[pt->nb_alias] = NULL;
  return (0);
}

int	read_in_file(t_msh *pt, char *path)
{
  char	*alias;
  char	*cmd;
  char	*s;
  char	**tab;

  if ((pt->fd = open(path, O_RDONLY)) == -1)
    return (my_error(TURTLE_EOPEN));
  while ((s = get_next_line(pt->fd)))
    {
      tab = my_str_to_wordtab(s, " \t");
      my_free(s);
      if (strcmp(tab[0], "alias") == 0)
	{
	  cut_alias(pt, tab, &alias, &cmd);
	  if (alias && cmd)
	    {
	      if (!(pt->alias[pt->nb_alias - 1] = malloc(sizeof(char **) * 2)))
		return (my_error(1));
	      pt->alias[pt->nb_alias - 1][0] = alias;
	      pt->alias[pt->nb_alias - 1][1] = cmd;
	    }
	}
    }
  return (0);
}

int	get_alias_(t_msh *pt)
{
  pt->nb_alias = 0;
  pt->alias = NULL;
  read_in_file(pt, ".turtlerc");
  return (0);
}
