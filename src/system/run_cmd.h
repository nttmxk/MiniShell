/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:51:05 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/26 12:58:49 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_CMD_H
# define RUN_CMD_H

# include "libft.h"
# include "pipe_struct.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

# define R 0
# define W 1

// error.c-------------------------------------
/*
[p_a_error()]
Before printing the error about errno,
the allocated structure 'arg' is free.
*/
void		p_a_error(t_arg *arg);
// main.c
//parsing.c-----------------------------------
t_arg		*init_arg(void);
int			**malloc_fds(int cmd_count);
// run_cmd.c-----------------------------------
/*
[run_cmd()]
Creates child processes and executes command.
*/
int			run_cmd(t_arg *arg, int i);
/*
[connect_pipe()]
Pipe connection with the following command.
*/
void		connect_pipe(int cmd_idx, t_arg *arg);
/*
[connect_redir()]
Apply redirection.
*/
void		connect_redir(t_redir *redir, t_arg *arg);
/*
[sellect_redir()]
Choose the proper redirection function and execute it.
In the connect_redir()
*/
int			sellect_redir(t_redir *redir);
// redirection.c-----------------------------------
int			redir_in(const char *filename);
int			redir_out(const char *filename);
int			redir_app(const char *filename);
int			redir_here(const char *limitor);
// here_doc_util.c-----------------------------------
/*
[until_comein_limitor()]
Read on the readline() and connect to str until the limiter comes in.
When the limiter comes in, call the comein_limitor().
*/
int			until_comein_limitor(char **str, char **rl,
				const char *limitor, int fd);
/*
[free_return()]
Check if the strings str and rl are null or return status after deallocation.
If allocation fails, use it in return.
*/
int			free_return(char **str, char **rl, int status);
/*
[comein_limitor()]
Create a temporary file named temp, write a str, attach temp to STDIN, and temp is unlink.
*/
int			comein_limitor(int fd, char **str, char **rl);
/*
[is_limitor()]
Checked if the limiter was met.
If you have met the limiter return 0,
else returns the string read by readline().
*/
char		*is_limitor(char *rl, const char *limitor);
/*
[add_str()]
Added rl and newline to str.
null return on failure.
*/
char		*add_str(char **str, char **rl);
#endif