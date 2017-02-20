/*
** file.c for 42sh in /home/switi/svn/perso/42sh-2017
**
** Made by Styve Simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Fri Mar 15 19:30:26 2013 Styve Simonneau
** Last update Mon Jun  3 14:21:00 2013 styve simonneau
*/

#include "protos.h"

char	*dollar_dollar()
{
  char	*id;

  if (!(id = malloc(7)))
    my_error(1);
  sprintf(id, "%d", getpid());
  return (id);
}

char	*get_var(char *str, char **env)
{
  char	*var;
  char	*value;
  t_cnt	cnt;

  cnt.i = -1;
  cnt.j = -1;
  if (str[0] == '$')
    return (dollar_dollar());
  while (str[++(cnt.i)] && str[cnt.i] != ' ' && str[cnt.i] != '\t');
  if (!(var = malloc(cnt.i + 2)))
    my_error(1);
  var[cnt.i] = '=';
  var[cnt.i + 1] = '\0';
  cnt.i = -1;
  while (str[++(cnt.i)] && str[cnt.i] != '$' && str[cnt.i] != ' '
	 && str[cnt.i] != '\t')
    var[++(cnt.j)] = str[cnt.i];
  value = get(env, var);
  my_free(var);
  return (value);
}

void	fill_string(char *finalstr, char *string, t_msh *pt, t_cnt *cnt)
{
  char	*var;

  finalstr[++(cnt->j)] = string[cnt->i];
  if (string[cnt->i] == '$' && string[cnt->i + 1] && string[cnt->i + 1] != ' '
      && string[cnt->i + 1] != '\t')
    {
      var = get_var(&string[cnt->i + 1], pt->env);
      while (string[++(cnt->i)] && string[cnt->i] != ' '
	     && string[cnt->i] != '\t');
      --(cnt->i);
      finalstr[cnt->j] = '\0';
      if (var != NULL)
	{
	  strcat(finalstr, var);
	  cnt->j += strlen(var) - 1;
	  my_free(var);
	}
      else
	strcat(finalstr, "\b");
    }
}

char	*analyze_string(t_msh *pt, char *string)
{
  t_cnt	cnt;
  int	tomalloc;
  char	*finalstr;

  cnt.i = -1;
  cnt.j = -1;
  tomalloc = count_to_malloc(string, pt->env);
  if (!(finalstr = malloc(tomalloc + 1)))
    my_error(1);
  while (++(cnt.i) <= tomalloc)
    finalstr[cnt.i] = '\0';
  cnt.i = -1;
  while (string[++(cnt.i)])
    fill_string(finalstr, string, pt, &cnt);
  return (finalstr);
}

int	count_to_malloc(char *string, char **env)
{
  int	i;
  int	tomalloc;
  char	*var;

  tomalloc = 0;
  i = -1;
  while (string[++i])
    {
      tomalloc += 1;
      if (string[i] == '$' && string[i + 1] && string[i + 1] != ' '
	  && string[i + 1] != '\t')
	{
	  var = get_var(&string[i + 1], env);
	  if (var != NULL)
	    {
	      tomalloc += strlen(var);
	      my_free(var);
	    }
	}
    }
  return (tomalloc);
}
