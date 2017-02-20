/*
** error.h for 42sh in /home/switi/svn/perso/42sh-2017
**
** Made by Styve Simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Thu Mar 14 19:53:12 2013 Styve Simonneau
** Last update Tue Jun  4 02:01:12 2013 styve simonneau
*/

#ifndef	ERROR_H_
# define ERROR_H_

enum
{
  CDTIRET = 7,
  NOLDPWD,
  BADDIR,
  NOHOME,
  BADHOME,
  NOPWD,
  TCGETATTR,
  TCSETATTR,
  FORK,
  UNSETENV,
  TURTLE_EOPEN,
  NOPERM,
  NOTAFILE,
  NOTEXE,
  QUOTE_MISMATCH
};

# define	ERR00		"exit"
# define	ERR01		"Can't alloc enough space, please free your memory."
# define	ERR02		"Mismatched quotes"
# define	ERR03		"Mismatched parentheses"
# define	ERR04		"Mismatched brackets"
# define	ERR05		"Mismatched braces"
# define	ERR06		"There was an error stating a file. Please try\
  again\nIf this error still appears, maybe you should buy a new computer."
# define	ECDTIRET	"cd: usage: cd [-]"
# define	ENOLDPWD	"Error: no OLDPWD set."
# define	EBADDIR		"cd: Not a directory"
# define	ENOHOME		"Error: no HOME"
# define	EBADHOME	"Error: Bad HOME"
# define	ENOPWD		"Error: No PWD set"
# define	ETURTLE_EOPEN	"Error opening .turtlerc"
# define	ENOPERM		"Permission denied"
# define	ENOTAFILE	"Not a file"
# define	ENOTEXE		"Cannot execute"
# define	ETCGETATTR	"Error with tcgetattr"
# define	ETCSETATTR	"Error with tcsetattr"
# define	EFORK		"Error with fork"
# define	EUNSETENV	"unsetenv: Too few arguments."
# define	EQUOTE_MISMATCH	"Mismatched quotes."

#endif	/* !ERROR_H_ */
