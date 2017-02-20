/*
** struct.h for strcu mysh in /home/simonn_s//svn/minishell1
**
** Made by styve simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Sun Dec  9 17:57:15 2012 styve simonneau
** Last update Tue Jun  4 05:48:52 2013 styve simonneau
*/

#include <stdarg.h>

#ifndef	STRUCT_H_
# define STRUCT_H_

typedef struct	s_msh
{
  char		*home;
  char		**av;
  char		**env;
  char		**path;
  char		***alias;
  char		*cwd;
  int		nb_alias;
  int		env_modified;
  int		exit;
  int		fd;
}		t_msh;

typedef struct	s_cnt
{
  int		i;
  int		j;
}		t_cnt;

#endif /* !STRUCT_H_ */
