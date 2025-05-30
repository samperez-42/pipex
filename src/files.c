/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:22:30 by samperez          #+#    #+#             */
/*   Updated: 2025/05/28 13:03:28 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Checks if file1 & file2 exist and have the correct permissions 
static int	check_permissions(t_pipex *pipex)
{
	if (access(pipex->file1, F_OK) == -1 || access(pipex->file2, F_OK) == -1)
		return (ft_error(pipex, "File does not exist"));
	if (access(pipex->file1, R_OK) == -1 || access(pipex->file2, R_OK) == -1)
		return (ft_error(pipex, "No reading permission on file"));
	if (access(pipex->file1, W_OK) == -1 || access(pipex->file2, W_OK) == -1)
		return (ft_error(pipex, "No writing permission on file"));
	if (access(pipex->file2, X_OK) == -1)
		return (ft_error(pipex, "No execution permission on file"));
	return (EXIT_SUCCESS);
}

// Does a few checks regarding file permissions
int	file_check(t_pipex *pipex)
{
	int	fd1;
	int	fd2;

	fd2 = open(pipex->file2, O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (!fd2)
		return (ft_error(pipex, "Failed to open file 2"));
	close(fd2);
	if (check_permissions(pipex))
		return (EXIT_FAILURE);
	fd1 = open(pipex->file1, O_RDONLY);
	if (!fd1)
		return (ft_error(pipex, "Failed to open file 1"));
	close(fd1);
	return (EXIT_SUCCESS);
}
