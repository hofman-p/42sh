/*
** redirection.c for redirection in /home/salope_b//minishell2-2017-salope_b
** 
** Made by brandon salopek
** Login   <salope_b@epitech.net>
** 
** Started on  Wed Mar  6 00:51:12 2013 brandon salopek
** Last update Sun May 26 11:38:55 2013 brandon salopek
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "my.h"
#include "pipes.h"

int	check_redirection_l(char **argv)
{
  int	i;
  int	j;

  i = 0;
  while (argv[i] != NULL)
    {
      j = 0;
      while (argv[i][j] != '\0')
	{
	  if (argv[i][j] == '<' && argv[i][j + 1] != '<')
	    return (1);
	  else if (argv[i][j] == '<' && argv[i][j + 1] == '<')
	    return (-1);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (-1);
}

char	*check_file_l(char **argv, char *file)
{
  int	i;
  int	j;

  i = 0;
  while (argv[i] != NULL)
    {
      j = 0;
      while (argv[i][j] != '\0')
	{
	  if (argv[i][j] == '<' && argv[i][j + 1] == '\0')
	    {
	      file = strdup(argv[i + 1]);
	      return (file);
	    }
	  else if (argv[i][j] == '<' && argv[i][j + 1] != '\0')
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

char	**check_arg_l(char **argv, int i, int j)
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

int	init_var_2(char *file, int *fd, char **res)
{
  if ((*fd = open(file, O_CREAT | O_RDONLY , S_IRWXU, S_IXOTH)) == -1)
    printf("%s : invalid file\n", file);
  res[0][0] = '\0';
  return (0);
}

int	redirection_l(char **argv, t_msh *msh, int *t_fd)
{
  char	*file;
  char	*path;
  int	fd;

  (void)t_fd;
  file = NULL;
  if (check_redirection_l(argv) == -1)
    return (1);
  file = check_file_l(argv, file);
  argv = check_arg_l(argv, 0, 0);
  path = create_path(msh->path[my_exec(argv, msh)], argv[0]);
  if ((fd = open(file, O_CREAT | O_RDONLY , S_IRWXU, S_IXOTH)) == -1)
    printf("%s : invalid file\n", file);
  dup2(fd, 0);
  return (execve(path, argv, msh->env));
}
