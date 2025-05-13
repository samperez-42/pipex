/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:06:14 by samperez          #+#    #+#             */
/*   Updated: 2025/05/13 10:50:01 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_struct(t_pipex *pipex)
{
	pipex->command1 = NULL;
	pipex->command2 = NULL;
	pipex->command_path1 = NULL;
	pipex->command_path2 = NULL;
	pipex->file1 = NULL;
	pipex->file2 = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = NULL;
	if (argc != 5)
		return (ft_error(pipex, 22, "Error: Incorrect number of arguments"));
	if (!argv[1][0] || !argv[2][0] || !argv[3][0] || !argv[4][0])
		return (ft_error(pipex, 22, "Error: Empty arguments"));
	pipex = malloc(sizeof(t_pipex));
	init_struct(pipex);
	if (!pipex)
		return (EXIT_FAILURE);
	if (file_check(pipex, argv[1], argv[4]))
		return (EXIT_FAILURE);
	if (command_check(pipex, argv[2], argv[3], envp))
		return (EXIT_FAILURE);
	free_pipex(pipex);
	return (EXIT_SUCCESS);
}
