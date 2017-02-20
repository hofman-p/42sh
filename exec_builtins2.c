/*
** exec_builtins2.c for 42 in /home/simonn_s//svn/42sh-2017-simonn_s
** 
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
** 
** Started on  Mon Jun  3 16:47:25 2013 styve simonneau
** Last update Tue Jun  4 22:34:46 2013 styve simonneau
*/

#include "protos.h"
#include "error.h"

char	*fill_with_quote(char *str, char *tofill)
{
  int	i;
  int	cnt;

  i = -1;
  cnt = 0;
  while (str[++i] != '"')
    if (!str[i])
      {
	my_error(QUOTE_MISMATCH);
	return (NULL);
      }
  cnt = i;
  if (!(tofill = malloc(sizeof(char) * (cnt + 1))))
    return (NULL);
  tofill[cnt] = '\0';
  i = -1;
  while (++i < cnt)
    tofill[i] = str[i];
  return (tofill);
}

char	*fill_without_quote(char *str, char *tofill)
{
  int	i;
  int	cnt;

  i = 0;
  cnt = 0;
  while (str[i] && str[i] != ' ')
    ++i;
  cnt = i;
  if (!(tofill = malloc(sizeof(char) * (cnt + 1))))
    return (NULL);
  tofill[cnt] = '\0';
  i = -1;
  while (++i < cnt)
    tofill[i] = str[i];
  return (tofill);
}

char	*get_line(char **arg, int n)
{
  char	*line;
  int	i;
  int	tomalloc;

  tomalloc = 0;
  i = -1;
  while (arg[++i])
    tomalloc += strlen(arg[i]) + 10;
  if (!(line = malloc(sizeof(char) * tomalloc)))
    return (NULL);
  line[0] = '\0';
  line[tomalloc - 1] = '\0';
  i = n;
  while (arg[++i])
    line = strcat(strcat(line, arg[i]), " ");
  return (line);
}

char	*get_alias(char *line, int *i, int quotes, char *tofill)
{
  if (quotes == 1)
    {
      if (!(tofill = fill_with_quote(&line[(*i) + 1], tofill)))
	return (NULL);
      while (line[++(*i)] != '"');
      ++*i;
    }
  else
    {
      if (!(tofill = fill_without_quote(&line[*i], tofill)))
	return (NULL);
      while (line[++(*i)] != ' ');
    }
  return (tofill);
}

int	exec_alias(t_msh *pt, char **arg, int n)
{
  char	*alias;
  char	*line;
  char	*cmd;
  int	i;

  (void) n;
  i = -1;
  alias = NULL;
  cmd = NULL;
  if (!(line = get_line(arg, 0)))
    return (0);
  alias = line[++i] == '"' ? get_alias(line, &i, 1, alias)
    : get_alias(line, &i, 0, alias);
  cmd = line[++i] == '"' ? get_alias(line, &i, 1, cmd)
    : get_alias(line, &i, 0, cmd);
  if (alias && cmd)
    {
      if (!(pt->alias = realloc(pt->alias, (++pt->nb_alias + 1) * sizeof(char*))
	    ) || (!(pt->alias[pt->nb_alias - 1] = malloc(sizeof(char*) * 2))))
	return (my_error(1));
      pt->alias[pt->nb_alias - 1][0] = alias;
      pt->alias[pt->nb_alias - 1][1] = cmd;
      pt->alias[pt->nb_alias] = NULL;
    }
  return (0);
}
