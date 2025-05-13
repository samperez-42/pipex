/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:06:14 by samperez          #+#    #+#             */
/*   Updated: 2025/05/13 12:22:48 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	init_struct(t_pipex *pipex, char **argv)
{
	pipex->file1 = argv[1];
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
	pipex->file2 = argv[4];
	pipex->cmd_path1 = NULL;
	pipex->cmd_path2 = NULL;
	pipex->full_path = NULL;
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
	if (!pipex)
		return (EXIT_FAILURE);
	init_struct(pipex, argv);
	if (file_check(pipex))
		return (EXIT_FAILURE);
	if (command_check(pipex, envp))
		return (EXIT_FAILURE);
	free_pipex(pipex);
	return (EXIT_SUCCESS);
}
