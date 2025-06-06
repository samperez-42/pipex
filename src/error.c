/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:48:13 by samperez          #+#    #+#             */
/*   Updated: 2025/05/26 10:36:12 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Frees the allocated split of paths in env
void	free_paths(char **path)
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

// Frees the struct
void	free_pipex(t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->cmd1)
			free_paths(pipex->cmd1);
		if (pipex->cmd2)
			free_paths(pipex->cmd2);
		if (pipex->cmd_path1)
			free(pipex->cmd_path1);
		if (pipex->cmd_path2)
			free(pipex->cmd_path2);
		if (pipex->full_path)
			free_paths(pipex->full_path);
		free(pipex);
	}
}

// Checks for empty arguments like "" or "	"
int	check_empty_argv(char **argv)
{
	if (!argv[1][0] || !argv[2][0] || !argv[3][0] || !argv[4][0])
		return (EXIT_FAILURE);
	if (argv[1][0] == ' ' || argv[2][0] == ' ' || argv[3][0] == ' '
		|| argv[4][0] == ' ')
		return (EXIT_FAILURE);
	if (argv[1][0] == '\t' || argv[2][0] == '\t' || argv[3][0] == '\t'
		|| argv[4][0] == '\t')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// Sends a custom error message and terminates the program
int	ft_error(t_pipex *pipex, char *str)
{
	free_pipex(pipex);
	perror(str);
	return (EXIT_FAILURE);
}
