/*
** get_data_2.c for 42sh in /home/salope_b//42sh-2017-simonn_s/test/toto/42sh-2017-simonn_s
** 
** Made by brandon salopek
** Login   <salope_b@epitech.net>
** 
** Started on  Sun May 26 20:54:42 2013 brandon salopek
** Last update Sun Jun  9 19:07:24 2013 styve simonneau
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "protos.h"
#include "my.h"
#include "pipes.h"

int	get_data_2(char **argv, t_msh *msh, char *file)
{
  char	*str;
  char	*res;
  int	*fd;
  int	ret;

  if (file == NULL)
    return (-1);
  fd = malloc(sizeof(int) * 2);
  res = NULL;
  pipe(fd);
  argv = check_arg_l2(argv, 0, 0);
  write(1, "? ", 2);
  while (((str = get_next_line(0)) != NULL) && strcmp(str, file) != 0)
    {
      write(1, "? ", 2);
      res = my_strcat_2(res, str);
      my_free(str);
    }
  ret = fork();
  if (ret == 0)
    return (first_red_exe(&fd, res, 1));
  else
    return (sec_red_exe(&fd, argv, msh, 1));
  return (0);
}

int	get_data(char **argv, int **t_fd, t_msh *msh)
{
  char	*str;
  char	*res;
  char	*file;
  int	ret;

  res = NULL;
  file = NULL;
  file = check_file_l2(argv, file);
  argv = check_arg_l2(argv, 0, 0);
  write(1, "? ", 2);
  while (((str = get_next_line(0)) != NULL) && strcmp(str, file) != 0)
    {
      write(1, "? ", 2);
      res = my_strcat_2(res, str);
      my_free(str);
    }
  ret = fork();
  if (ret == 0)
    return (first_red_exe(t_fd, res, 0));
  else
    return (sec_red_exe(t_fd, argv, msh, 0));
  return (0);
}

int	first_red_exe(int **fd, char *res, int duper)
{
  close(fd[0][0]);
  if (duper == 1)
    dup2(fd[0][1], 1);
  if ((write(1, res, strlen(res))) == -1)
    write(2, "error write\n", 12);
  return (42);
}

int	sec_red_exe(int **fd, char **argv, t_msh *msh, int closer)
{
  char	*path;
  int	ret;

  waitpid(-1, 0, 1);
  path = create_path(msh->path[my_exec(argv, msh)], argv[0]);
  dup2(fd[0][0], fd[0][1]);
  if (closer == 1)
    close(fd[0][1]);
  else
    dup2(fd[0][1], 1);
  dup2(fd[0][0], 0);
  ret = execve(path, argv, msh->env);
  return (ret);
}
