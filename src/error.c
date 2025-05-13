/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:48:13 by samperez          #+#    #+#             */
/*   Updated: 2025/05/13 12:15:54 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_pipex(t_pipex *pipex)
{
	if (pipex)
	{
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
