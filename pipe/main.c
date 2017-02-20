/*
** main.c for main in /home/salope_b//42sh/pipe_inf
**
** Made by brandon salopek
** Login   <salope_b@epitech.net>
**
** Started on  Tue Apr  2 08:44:35 2013 brandon salopek
** Last update Sun May 26 22:45:28 2013 pierre hofman
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "pipes.h"
#include "error.h"
#include "my.h"

int	link_tab_pipe(int **tab_pipe, char **pipe_cmd, int *i, t_msh *msh)
{
  int	size;
  char	**arg;

  size = size_tab(pipe_cmd);
  *i = -1;
  while (++(*i) < size - 2)
    if ((dup2(tab_pipe[(*i)][0], tab_pipe[(*i)][1])) == -1
	|| (arg = my_str_to_wordtab(pipe_cmd[(*i) + 1], " ")) == NULL
	|| (pipe_exec_link(tab_pipe, (*i) + 1, arg, msh) == -1))
      return (-1);
  return (0);
}

int	beg_tab_pipe(char **pipe_cmd, int ***tab_pipe, t_msh *msh, int *ret)
{
  char	**arg;

  if ((pars_in_out(pipe_cmd) != 1) ||
      ((tab_pipe[0] = malloc(sizeof(int *) *
			  (size_tab(pipe_cmd) + 1))) == NULL) ||
      ((init_tab_pipe(pipe_cmd, tab_pipe)) == -1) ||
      ((arg = my_str_to_wordtab(pipe_cmd[0], " ")) == NULL ||
       (*ret = pipe_exec_beg(tab_pipe[0], my_exec(arg, msh), arg, msh)) == -1))
    return (-1);
  else
    return (0);
}

int	check_pipe(t_msh *msh, char *cmd)
{
  char	**pipe_cmd;
  char  **arg;
  int	**tab_pipe;
  int	ret;
  int	i;

  if (init_pipe(cmd, &pipe_cmd, &i) == -1)
    return (-1);
  if (i != 1)
    {
      if (beg_tab_pipe(pipe_cmd, &tab_pipe, msh, &ret) == -1)
	return (-1);
      else if (ret == 42)
	return (42);
      if ((link_tab_pipe(tab_pipe, pipe_cmd, &i, msh)) == -1 ||
	  ((arg = my_str_to_wordtab(pipe_cmd[i + 1], " ")) == NULL ||
	   (pipe_exec_end(tab_pipe, i, arg, msh)) == -1))
	return (-1);
      tab_pipe = close_pipe(tab_pipe);
    }
  else
    return (exec_one(my_str_to_wordtab(cmd, " "), msh));
  while (waitpid(-1, &ret, 0) != -1);
  return (ret);
}
