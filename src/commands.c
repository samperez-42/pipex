/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:37:25 by samperez          #+#    #+#             */
/*   Updated: 2025/05/19 11:41:53 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**get_path(char **path, char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i], ':');
			tmp = path[0];
			path[0] = ft_strtrim(path[0], "PATH=");
			free(tmp);
			return (path);
		}
		i++;
	}
	return (NULL);
}

static char	*search_paths(char **full_cmd, char *cmd)
{
	int		i;
	char	*tmp;
	char	*cmd_path;

	i = 0;
	tmp = NULL;
	cmd_path = NULL;
	while (full_cmd[i] != NULL)
	{
		tmp = ft_strjoin(full_cmd[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free (cmd_path);
		i++;
	}
	return (NULL);
}

int	command_check(t_pipex *pipex, char **envp)
{
	pipex->full_path = get_path(pipex->full_path, envp);
	if (!pipex->full_path)
	{
		ft_error(pipex, "Path not found in env variables.");
		return (EXIT_FAILURE);
	}
	pipex->cmd_path1 = search_paths(pipex->full_path, pipex->cmd1);
	pipex->cmd_path2 = search_paths(pipex->full_path, pipex->cmd2);
	if (!pipex->cmd_path1 || !pipex->cmd_path2)
	{
		ft_error(pipex, "Command not found or doesn't exist");
		return (EXIT_FAILURE);
	}
//	ft_printf("CMD_1 Path: %s\nCMD_2 Path: %s\n", pipex->cmd_path1, pipex->cmd_path2);
	return (EXIT_SUCCESS);
}
