/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milan-godawatta <milan-godawatta@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:53:59 by milan-godaw       #+#    #+#             */
/*   Updated: 2024/10/19 01:54:17 by milan-godaw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_command_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		ft_free_split(cmd_args);
		error_exit("Command not found");
	}
	if (execve(cmd_path, cmd_args, envp) == -1)
	{
		free(cmd_path);
		ft_free_split(cmd_args);
		error_exit("Execve error");
	}
}
