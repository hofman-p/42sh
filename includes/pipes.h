/*
** pipes.h for pipe in /home/switi/svn/B2/42sh-2017-simonn_s
**
** Made by Styve Simonneau
** Login   <simonn_s@epitech.net>
**
** Started on  Sat May 25 21:22:43 2013 Styve Simonneau
** Last update Sun May 26 22:21:31 2013 Styve Simonneau
*/

#ifndef		PIPES_H_
# define	PIPES_H_

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "struct.h"

void	fork_err();
void	pipe_err();
void	malloc_err();
void	dup_err();
void	close_err();
int	my_error_(int ret);
int	pipe_exec_beg(int **fd, int i, char **arg, t_msh *msh);
int	pipe_exec_link(int **fd, int i, char **arg, t_msh *msh);
int	pipe_exec_end(int **fd, int i, char **arg, t_msh *msh);
char	*create_path(char *beg, char *end);
int	my_exec(char **arg, t_msh *msh);
int	size_tab(char **tab);
int	**close_execption(int **pipe, int no);
int	**close_pipe(int **pipe);
int	exec_one(char **arg, t_msh *msh);
int	pars_in_out(char **t_cmd);
int	check_pipe(t_msh *msh, char *cmd);
char	*my_strcat_2(char *dest, char *src);
char	*my_strcat(char *dest, char *src);
int	operand_exec(char *cmd, t_msh *msh);
int	check_redirection(char **argv);
char	*check_file(char **argv, char *file);
char	**check_arg(char **argv, int i, int j);
int	redirection(char **argv, t_msh *msh, int *t_fd);
int	check_redirection_2(char **argv);
char	*check_file_2(char **argv, char *file);
char	**check_arg_2(char **argv, int i, int j);
int	redirection_2(char **argv, t_msh *msh, int *t_fd);
int	check_redirection_l(char **argv);
char	*check_file_l(char **argv, char *file);
char	**check_arg_l(char **argv, int i, int j);
int	init_var_2(char *file, int *fd, char **res);
int	redirection_l(char **argv, t_msh *msh, int *t_fd);
int	check_redirection_l2(char **argv);
char	*check_file_l2(char **argv, char *file);
char	**check_arg_l2(char **argv, int i, int j);
int	get_data(char **argv, int **t_fd, t_msh *msh);
int	get_data_2(char **argv, t_msh *msh, char *);
int	redirection_l2(char **argv, t_msh *msh, int **t_fd);
int	first_red_exe(int **, char *, int);
int	sec_red_exe(int **, char **, t_msh *, int);
int	init_tab_pipe(char **, int ***);
int	init_pipe(char *, char ***, int *);
int	**close_execption(int **pipe, int no);
char	*create_path(char *, char *);
void	fork_err();
void	pipe_err();
void	malloc_err();
void	dup_err();
void	close_err();

#endif		/* !PIPES_H_ */
