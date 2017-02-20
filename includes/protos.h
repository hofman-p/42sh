/*
** protos.h for 42sh in /home/switi/svn/perso/42sh-2017
**
** Made by Styve Simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Wed Mar 13 14:46:05 2013 Styve Simonneau
** Last update Sun Jun  9 19:06:44 2013 styve simonneau
*/

#ifndef	PROTOS_H_
# define PROTOS_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include "struct.h"
# include "my.h"


/* ERROR.c */
int		my_error(int);
/* MAIN.c */
int		qdxsh(t_msh *, char*);
/* GET.c */
int		is_oldvalue(char *, char *);
char		*get_oldvalue(char *);
char		*get(char **, char *);
/* INIT.c */
void		init(t_msh *, char **);
void		get_env(t_msh *, char **);
void		get_path(t_msh *, char **);
int		entry_env(char **);
/* ADD_ENTRIES.C */
int		add_entries(t_msh *pt);
/* PARSER.c */
int		check_builtin(t_msh *, char **, int);
int		command(t_msh *, char *);
int		separate(t_msh *, char *);
typedef int    (*fct)(t_msh *, char **, int);
/* FILE.c */
char		*dollar_dollar();
char		*get_var(char *, char **);
void		fill_string(char *, char *, t_msh *, t_cnt *);
char		*analyze_string(t_msh *, char *);
int		count_to_malloc(char *, char **);
/* EXEC_BUILTINS.c */
int		exec_echo(t_msh *, char **, int);
int		exec_env(t_msh *, char **, int);
int		exec_setenv(t_msh *, char **, int);
int		exec_unsetenv(t_msh *, char **, int);
char		**mcit(char **);
/* EXEC_BUILTINS2.c */
char		*get_alias(char *, int *, int, char *);
int		exec_alias(t_msh *, char **, int);
char		*get_line(char **, int);
/* EXEC_BUILTINS3.c */
int		exec_source(t_msh *, char **, int);
/* GET_ALIAS.c */
int		get_alias_(t_msh *);
int		read_in_file(t_msh *, char *);
int		cut_alias(t_msh *, char **, char **, char **);
/* BUILTINS_1.c */
void		modify_in_env(t_msh *);
void		add_to_env(t_msh *, char **, int, int);
int		length_to_malloc(t_msh *);
int		already_in_env(char **, char **);
char		*cutenv(char *);
/* BUILTINS_2.c */
int		copy_in_newenv(t_msh *, int, char **);
char		*check_av2(char *, t_msh *);
char		*get_user(t_msh *);
/* USEFULL.c */
char		*clean_it(char *, int);
void		change_env(char *, char *, char *, t_msh *);
void		remove_bn(char []);
void		putprompt();
/* FREE.c */
void		my_free(void *);
void		free_tab(char **);
/* CD.c */
int		cd_normal(t_msh *, char **, char *);
int		cd_tiret(t_msh *, char **, char *);
int		cd_tilt(t_msh *, char **, char *);
int		go_dir(t_msh *, char **);
int		my_getcwd(t_msh *);
int		exec_cd(t_msh *, char **, int);
void		print_change_cd(char *, char *, t_msh *);
typedef int	(*tbcd)(t_msh *, char **, char *);
/* EXEC_BINARY.c */
int		check_rights(char *);
int		fork_and_exec(t_msh *, char *);
int		exec_shellcmd(t_msh *, char *);
int		exec_binary(t_msh *, char *);
/* ALIAS.c */
char		*alias(char *, t_msh *);
int		is_alias(char *, char *, t_msh *);
int		find_cmd(char *, char *, t_msh *);
int		get_cmd(t_msh *, char *, int);
/* PARSER_CONF.c */
int		parser_conf();
int		check_syntax(char *);
int		check_alias(char *);
int		save_all(t_msh *);
/* REPLACE-WITH-ALIAS.c */
char		*replace_with_alias(char ***, char *);
void		replace_by_alias(char *, char ***, int *, char *);
int		count_in_tab(char **);
/* AUTO_COMPLET.c */
int		auto_complet(char *);
char		*check_directory(char *, char *);
void		check_in_directory(DIR *, char *);
int		check_complet(char *, char *);
char		*check_pathern(char *, char *);
char		*erase_multi_star(char *);
int		my_match(char *, char *);
char		*last_word(char *);

#endif /* !PROTOS_H_ */
