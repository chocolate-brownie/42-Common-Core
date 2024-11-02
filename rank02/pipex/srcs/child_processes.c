/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milan-godawatta <milan-godawatta@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:51:33 by milan-godaw       #+#    #+#             */
/*   Updated: 2024/10/19 01:51:46 by milan-godaw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process1(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd_infile, STDIN_FILENO);
	dup2(pipex.pipe_fd[1], STDOUT_FILENO);
	close(pipex.pipe_fd[0]);
	execute(argv[2], envp);
}

void	child_process2(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.pipe_fd[0], STDIN_FILENO);
	dup2(pipex.fd_outfile, STDOUT_FILENO);
	close(pipex.pipe_fd[1]);
	execute(argv[3], envp);
}
