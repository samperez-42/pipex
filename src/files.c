/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:22:30 by samperez          #+#    #+#             */
/*   Updated: 2025/05/13 10:08:28 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	check_permissions(t_pipex *pipex, char *file1, char *file2)
{
	if (access(file1, F_OK) == -1 || access(file2, F_OK) == -1)
		return (ft_error(pipex, 2, "Error: File does not exist"));
	if (access(file1, R_OK) == -1 || access(file2, R_OK) == -1)
		return (ft_error(pipex, 13, "Error: No reading permission on file"));
	if (access(file1, W_OK) == -1 || access(file2, W_OK) == -1)
		return (ft_error(pipex, 13, "Error: No writing permission on file"));
	if (access(file1, X_OK) == -1 || access(file2, X_OK) == -1)
		return (ft_error(pipex, 13, "Error: No execution permission on file"));
	return (EXIT_SUCCESS);
}

int	file_check(t_pipex *pipex, char *file1, char *file2)
{
	int	fd1;
	int	fd2;

	if (check_permissions(pipex, file1, file2))
		return (EXIT_FAILURE);
	fd1 = open(file1, O_RDONLY);
	fd2 = open(file2, O_RDONLY);
	if (!fd1 || !fd2)
		return (ft_error(pipex, 13, "Error: Can't open the files"));
	return (EXIT_SUCCESS);
}
