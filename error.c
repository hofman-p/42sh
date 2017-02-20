/*
** error.c for 42sh in /home/switi/svn/perso/42sh-2017
**
** Made by Styve Simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Thu Mar 14 19:06:39 2013 Styve Simonneau
** Last update Tue Jun  4 16:37:01 2013 styve simonneau
*/

#include <stdlib.h>
#include <stdio.h>
#include "protos.h"
#include "error.h"

int			my_error(int num)
{
  static const char	*err[] = {ERR00, ERR01, ERR02, \
				  ERR03, ERR04, ERR05, ERR06, ECDTIRET,	\
				  ENOLDPWD, EBADDIR, ENOHOME, EBADHOME, \
				  ENOPWD, ETCGETATTR, ETCSETATTR, EFORK, \
				  EUNSETENV, ETURTLE_EOPEN, ENOPERM, \
				  ENOTAFILE, ENOTEXE, EQUOTE_MISMATCH};

  fprintf(stderr, "%s\n", err[num]);
  return (-1);
}
