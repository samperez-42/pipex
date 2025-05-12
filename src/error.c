/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:48:13 by samperez          #+#    #+#             */
/*   Updated: 2025/05/12 14:38:28 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_pipex(t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->command1)
			free(pipex->command1);
		if (pipex->command2)
			free(pipex->command2);
		if (pipex->file1)
			free(pipex->file1);
		if (pipex->file2)
			free(pipex->file2);
		if (pipex->command_path1)
			free(pipex->command_path1);
		if (pipex->command_path2)
			free(pipex->command_path2);
		free(pipex);
	}
}

int	ft_error(t_pipex *pipex, int errno, char *str)
{
	free_pipex(pipex);
	ft_printf("%s - %s\n", str, strerror(errno));
	return (EXIT_FAILURE);
}
