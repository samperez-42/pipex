/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:37:25 by samperez          #+#    #+#             */
/*   Updated: 2025/05/19 15:09:36 by samperez         ###   ########.fr       */
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

static	int	check_absolute_path(t_pipex *pipex, char *cmd, char number)
{
	if (access(cmd, X_OK) == 0)
	{
		if (number == '1')
			pipex->cmd_path1 = ft_strdup(pipex->cmd1[0]);
		else if (number == '2')
			pipex->cmd_path2 = ft_strdup(pipex->cmd2[0]);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	command_check(t_pipex *pipex, char **envp)
{
	pipex->full_path = get_path(pipex->full_path, envp);
	if (!pipex->full_path)
	{
		ft_error(pipex, "Path not found in env variables.");
		return (EXIT_FAILURE);
	}
	if (check_absolute_path(pipex, pipex->cmd1[0], '1') == EXIT_FAILURE)
		pipex->cmd_path1 = search_paths(pipex->full_path, pipex->cmd1[0]);
	if (check_absolute_path(pipex, pipex->cmd2[0], '2') == EXIT_FAILURE)
		pipex->cmd_path2 = search_paths(pipex->full_path, pipex->cmd2[0]);
	if (!pipex->cmd_path1 || !pipex->cmd_path2)
	{
		ft_error(pipex, "Command not found or doesn't exist");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
