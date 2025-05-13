/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:06:14 by samperez          #+#    #+#             */
/*   Updated: 2025/05/13 12:12:08 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_struct(t_pipex *pipex, char **argv)
{
	pipex->command1 = argv[2];
	pipex->command2 = argv[3];
	pipex->command_path1 = NULL;
	pipex->command_path2 = NULL;
	pipex->file1 = argv[1];
	pipex->file2 = argv[4];
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
	init_struct(pipex, argv);
	if (!pipex)
		return (EXIT_FAILURE);
	if (file_check(pipex))
		return (EXIT_FAILURE);
	if (command_check(pipex, envp))
		return (EXIT_FAILURE);
	free_pipex(pipex);
	return (EXIT_SUCCESS);
}
