/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:37:25 by samperez          #+#    #+#             */
/*   Updated: 2025/05/12 14:39:08 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**get_path(char **path, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i], ':');
			path[0] = ft_strtrim(path[0], "PATH=");
            return (path);
		}
		i++;
	}
	return (NULL);
}

// env || grep PATH to get the command paths, read each file and determine if command exists
// Don't forget to free the split of paths
int	command_check(t_pipex *pipex, char *command1, char *command2, char **envp)
{
	char	**path;

	path = NULL;
	path = get_path(path, envp);
	if (!path)
		return (ft_printf("Error\nPath not found in env variables.\n"));
	while (*path)
	{
		ft_printf("%s\n", *path);
		path++;
	}	
	(void) command1;
	(void) command2;
	//free_paths
	return (EXIT_SUCCESS);
}
