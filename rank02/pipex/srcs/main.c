/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milan-godawatta <milan-godawatta@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:07:06 by milan-godaw       #+#    #+#             */
/*   Updated: 2024/10/19 02:01:52 by milan-godaw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pipex(argc, argv, envp);
	return (0);
}

void	pipex(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	setup_pipex(argc, argv, &pipex);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		child_process1(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		child_process2(pipex, argv, envp);
	close_fds(pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
}

void	setup_pipex(int argc, char **argv, t_pipex *pipex)
{
	if (argc != 5)
		error_exit("Invalid argument count");
	pipex->fd_infile = open(argv[1], O_RDONLY);
	if (pipex->fd_infile < 0)
		error_exit("Error opening infile");
	pipex->fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_outfile < 0)
	{
		close(pipex->fd_infile);
		error_exit("Error opening outfile");
	}
	if (pipe(pipex->pipe_fd) == -1)
	{
		close(pipex->fd_infile);
		close(pipex->fd_outfile);
		error_exit("Pipe error");
	}
}

void	close_fds(t_pipex pipex)
{
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	close(pipex.fd_infile);
	close(pipex.fd_outfile);
}
