/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:37:25 by samperez          #+#    #+#             */
/*   Updated: 2025/05/13 10:51:33 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	free_paths(char **path)
{
	int	i;

	if (!path)
		return ;
	i = 0;
	while (path[i])
	{
		free(path[i]);
		path[i] = NULL;
		i++;
	}
	free(path);
}

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

// env || grep PATH to get the command paths,
//	read each file and determine if command exists
// Don't forget to free the split of paths
int	command_check(t_pipex *pipex, char *cmd1, char *cmd2, char **envp)
{
	char	**path;

	path = NULL;
	path = get_path(path, envp);
	if (!path)
	{
		free_pipex(pipex);
		return (ft_printf("Error\nPath not found in env variables.\n"));
	}
	(void)pipex;
	(void)cmd1;
	(void)cmd2;
	free_paths(path);
	return (EXIT_SUCCESS);
}
