/*
** pipe_end_beg.c for 42sh in /home/salope_b//42sh-2017-simonn_s/test/42sh-2017-simonn_s
** 
** Made by brandon salopek
** Login   <salope_b@epitech.net>
** 
** Started on  Sun May 26 11:26:16 2013 brandon salopek
** Last update Sun May 26 20:52:31 2013 brandon salopek
*/

#include <stdlib.h>
#include <stdio.h>
#include "pipes.h"
#include "my.h"

int	my_error_(int ret)
{
  void	(*f[6])();

  f[0] = &close_err;
  f[1] = &dup_err;
  f[2] = &fork_err;
  f[3] = &malloc_err;
  f[4] = &pipe_err;
  f[5] = NULL;
  if (ret == 5)
    return (-1);
  f[ret]();
  return (-1);
}

int	pipe_exec_beg(int **fd, int ret, char **arg, t_msh *msh)
{
  int	err;
  char	*path;

  ret = my_exec(arg, msh);
  if (ret >= 0)
    path = create_path(msh->path[my_exec(arg, msh)], arg[0]);
  else if (ret == -2)
    path = arg[0];
  else
    return (-1);
  if ((ret = fork()) == -1)
    return (my_error_(2));
  else if (ret == 0)
    {
      fd = close_execption(fd, 0);
      if ((err = dup2(fd[0][1], 1)) == -1)
	return (my_error_(-err));
      if ((err = redirection_l2(arg, msh, fd)) != 1)
	return (ret);
      if ((err = close(fd[0][0]) + 1) == 0)
	return (my_error_(-err));
      redirection_l(arg, msh, NULL);
      return (execve(path, arg, msh->env));
    }
  return (1);
}

int	pipe_exec_link(int **fd, int i, char **arg, t_msh *msh)
{
  int	ret;
  char	*path;

  ret = my_exec(arg, msh);
  if (ret >= 0)
    path = create_path(msh->path[my_exec(arg, msh)], arg[0]);
  else if (ret == -2)
    path = arg[0];
  else
    return (-3);
  if ((ret = fork()) == -1)
    return (0);
  if (ret == 0)
    {
      if ((dup2(fd[i - 1][0], 0)) == -1)
	return (-1);
      if ((dup2(fd[i][1], 1)) == -1)
	return (-1);
      return (execve(path, arg, msh->env));
    }
  return (1);
}

int	pipe_exec_end(int **fd, int i, char **arg, t_msh *msh)
{
  int	ret;
  char	*path;

  ret = my_exec(arg, msh);
  if (ret >= 0)
    path = create_path(msh->path[my_exec(arg, msh)], arg[0]);
  else if (ret == -2)
    path = arg[0];
  else
    return (-3);
  if ((ret = fork()) == -1)
    return (-1);
  if (ret == 0)
    {
      redirection(arg, msh, NULL);
      redirection_2(arg, msh, NULL);
      if ((close(fd[i][1])) == -1)
	return (-1);
      if ((dup2(fd[i][0], 0)) == -1)
	return (-1);
      fd = close_execption(fd, i);
      return (execve(path, arg, msh->env));
    }
  return (1);
}
