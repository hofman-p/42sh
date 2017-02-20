/*
** redirection.c for redirection in /home/salope_b//minishell2-2017-salope_b
** 
** Made by brandon salopek
** Login   <salope_b@epitech.net>
** 
** Started on  Wed Mar  6 00:51:12 2013 brandon salopek
** Last update Sun May 26 20:56:25 2013 brandon salopek
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "pipes.h"

int	check_redirection_l2(char **argv)
{
  int	i;
  int	j;

  i = 0;
  while (argv[i] != NULL)
    {
      j = 0;
      while (argv[i][j] != '\0')
	{
	  if (argv[i][j] == '<' && argv[i][j + 1] == '<')
	    return (1);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (-1);
}

char	*check_file_l2(char **argv, char *file)
{
  int	i;
  int	j;

  i = 0;
  while (argv[i] != NULL)
    {
      j = 0;
      while (argv[i][j] != '\0')
	{
	  if (argv[i][j] == '<' && argv[i][j + 2] == '\0')
	    {
	      file = strdup(argv[i + 1]);
	      return (file);
	    }
	  else if (argv[i][j] == '<' && argv[i][j + 2] != '\0')
	    {
	      file = strdup(&argv[i][j + 1]);
	      return (file);
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  return (NULL);
}

char	**check_arg_l2(char **argv, int i, int j)
{
  while (argv[i] != NULL)
    {
      if (argv[i][0] == '<')
	{
	  argv[i] = NULL;
	  return (argv);
	}
      i = i + 1;
    }
  i = 0;
  while (argv[i] != NULL)
    {
      j = -1;
      while (argv[i][++j] != '\0')
	if (argv[i][j] == '<')
	  {
	    argv[i][j] = '\0';
	    argv[i + 1] = NULL;
	    return (argv);
	  }
      i = i + 1;
    }
  return (NULL);
}

int	redirection_l2(char **argv, t_msh *msh, int **t_fd)
{
  char	*file;

  file = NULL;
  if ((check_redirection_l2(argv)) == -1)
    return (1);
  else if (t_fd != NULL)
    return (get_data(argv, t_fd, msh));
  else
    return (get_data_2(argv, msh, check_file_l2(argv, file)));
}
