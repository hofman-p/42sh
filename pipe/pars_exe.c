/*
** pars_exe.c for 42sh in /home/salope_b//42sh-2017-simonn_s/test/toto/42sh-2017-simonn_s
**
** Made by brandon salopek
** Login   <salope_b@epitech.net>
**
** Started on  Sun May 26 20:47:57 2013 brandon salopek
** Last update Sun May 26 22:45:22 2013 pierre hofman
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "pipes.h"
#include "error.h"
#include "my.h"

int	size_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL);
  return (i);
}

int	init_pipe(char *cmd, char ***pipe_cmd, int *i)
{
  if ((pipe_cmd[0] = my_str_to_wordtab(cmd, "|")) == NULL)
    return (-1);
  *i = size_tab(pipe_cmd[0]);
  return (1);
}

int	init_tab_pipe(char **pipe_cmd, int ***tab_pipe)
{
  int	i;

  i = -1;
  while (++i < size_tab(pipe_cmd) - 1)
    {
      if ((tab_pipe[0][i] = malloc(sizeof(int) * 3)) == NULL)
	return (my_error(0));
      else if (pipe(tab_pipe[0][i]) == -1)
	return (my_error_(0));
    }
  tab_pipe[0][i] = NULL;
  return (0);
}

int	exec_one(char **arg, t_msh *msh)
{
  int	ret;
  char	*path;

  ret = my_exec(arg, msh);
  if (ret >= 0)
    path = create_path(msh->path[ret], arg[0]);
  else if (ret == -2)
    path = arg[0];
  else if (ret == -3)
    return (1);
  else
    return (-1);
  if ((ret = fork()) == - 1)
    return (my_error_(2));
  else if (ret == 0)
    {
      redirection(arg, msh, NULL);
      redirection_2(arg, msh, NULL);
      if ((redirection_l2(arg, msh, NULL)) == 42)
	return (42);
      redirection_l(arg, msh, NULL);
      return (execve(path, arg, msh->env));
    }
  while (waitpid(-1, &ret, 0) != -1);
  return (ret);
}

int	pars_in_out(char **t_cmd)
{
  int	i;
  char	**tmp;

  i = -1;
  while (t_cmd[++i] != NULL)
    {
      tmp = my_str_to_wordtab(t_cmd[i], " ");
      if (t_cmd[i + 1] != NULL &&
	  (check_redirection_l(tmp) == 1
	   || check_redirection_l2(tmp) == 1
	   || check_redirection(tmp) == 1
	   || check_redirection_2(tmp) == 1)
	  && i != 0)
	return (write(2, "Ambiguous output/input redirect\n", 33));
      else if (i == 0 && (check_redirection(tmp) == 1
			  || check_redirection_2(tmp) == 1))
	return (write(2, "Ambiguous output redirect\n", 27));
      else if (t_cmd[i + 1] == NULL && (check_redirection_l(tmp) == 1
					|| check_redirection_l2(tmp) == 1))
	return (write(2, "Ambiguous input redirect\n", 26));
    }
  return (1);
}
