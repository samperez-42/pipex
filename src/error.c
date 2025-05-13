/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:48:13 by samperez          #+#    #+#             */
/*   Updated: 2025/05/13 12:26:21 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	free_pipex(t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->cmd_path1)
			free(pipex->cmd_path1);
		if (pipex->cmd_path2)
			free(pipex->cmd_path2);
		if (pipex->full_path)
			free_paths(pipex->full_path);
		free(pipex);
	}
}

int	ft_error(t_pipex *pipex, int errno, char *str)
{
	free_pipex(pipex);
	ft_printf("%s - %s\n", str, strerror(errno));
	return (EXIT_FAILURE);
}
