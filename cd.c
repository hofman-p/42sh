/*
** cd.c for cd.c in /home/hofman_p//W/Projets/42sh/Test_42
**
** Made by pierre hofman
** Login   <hofman_p@epitech.net>
**
** Started on  Mon Apr  8 17:01:58 2013 pierre hofman
** Last update Mon Jun  3 14:21:16 2013 styve simonneau
*/

#include "protos.h"
#include "error.h"

int	cd_normal(t_msh *cd, char **cmd, char *way)
{
  (void) way;
  if (cmd[1])
    {
      if (!(access(cmd[1], X_OK)))
	{
	  if (chdir(cmd[1]) == -1)
	    return (-1);
	  else
	    {
	      my_getcwd(cd);
	      change_env("setenv", "PWD", cd->cwd, cd);
	      my_free(cd->cwd);
	    }
	}
      else
	if (cmd[1][0] != '-' && cmd[1][0] != '~')
	  return (my_error(BADDIR));
      return (0);
    }
  return (0);
}

int	cd_tiret(t_msh *cd, char **cmd, char *way)
{
  char	*pwd;
  char	*oldpwd;

  if (!(oldpwd = get(cd->env, "OLDPWD=")))
    return (my_error(NOLDPWD));
  if (cmd[1] && cmd[1][0] == '-')
    {
      if (!(pwd = get(cd->env, "OLDPWD=")))
	return (my_error(NOLDPWD));
      change_env("setenv", "PWD", pwd, cd);
      if (cmd[1][1])
	return (my_error(CDTIRET));
      if (!(access(oldpwd, X_OK)))
	if (chdir(oldpwd) == -1)
	  return (-1);
	else
	  print_change_cd(pwd, way, cd);
      else
	return (my_error(NOLDPWD));
      my_free(pwd);
    }
  my_free(oldpwd);
  return (0);
}

int	cd_tilt(t_msh *cd, char **cmd, char *way)
{
  (void) way;
  if ((!cmd[1] || (cmd[1][0] == '~' && cmd[1][1] == '\0')) && cd->path[0])
    {
      if (!(cd->home = get(cd->env, "HOME=")))
	return (my_error(NOHOME));
      if (!(access(cd->home, X_OK)))
	{
	  if (chdir(cd->home) == -1)
	    return (-1);
	  else
	    change_env("setenv", "PWD", cd->home, cd);
	}
      else
	return (my_error(BADHOME));
    }
  return (0);
}

int			go_dir(t_msh *cd, char **cmd)
{
  static const tbcd	tb[] = {cd_tilt, cd_tiret, cd_normal};
  char			*way;
  int			i;

  i = -1;
  my_getcwd(cd);
  if (!(way = get(cd->env, "PWD=")))
    return (my_error(NOPWD));
  while (++i < 3)
    if ((tb[i](cd, cmd, way)) == -1)
      return (-1);
  my_free(way);
  return (0);
}

int	exec_cd(t_msh *cd, char **cmd, int n)
{
  (void) n;
  go_dir(cd, cmd);
  return (0);
}
