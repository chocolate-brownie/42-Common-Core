/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milan-godawatta <milan-godawatta@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:34:19 by mgodawat          #+#    #+#             */
/*   Updated: 2024/10/19 01:55:58 by milan-godaw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		fd_infile;
	int		fd_outfile;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
}			t_pipex;

void		error_exit(char *message);
void		child_process1(t_pipex pipex, char **argv, char **envp);
void		child_process2(t_pipex pipex, char **argv, char **envp);
void		setup_pipex(int argc, char **argv, t_pipex *pipex);
void		close_fds(t_pipex pipex);
void		pipex(int argc, char **argv, char **envp);
char		*get_command_path(char *cmd, char **envp);
char		*ft_getenv(char **envp, const char *name);
void		ft_free_split(char **split);
void		execute(char *cmd, char **envp);

#endif
