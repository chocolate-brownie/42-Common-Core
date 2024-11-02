/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milan-godawatta <milan-godawatta@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:52:28 by milan-godaw       #+#    #+#             */
/*   Updated: 2024/10/19 02:16:59 by milan-godaw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*build_cmd_path(char *path, char *cmd)
{
	char	*temp;
	char	*full_path;

	temp = ft_strjoin(path, "/");
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	return (full_path);
}

char	*get_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*cmd_path;
	int		i;
	char	*path_env;

	path_env = ft_getenv(envp, "PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	i = -1;
	while (paths && paths[++i])
	{
		cmd_path = build_cmd_path(paths[i], cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			ft_free_split(paths);
			return (cmd_path);
		}
		free(cmd_path);
	}
	ft_free_split(paths);
	return (NULL);
}
