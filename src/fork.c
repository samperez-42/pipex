/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:18 by samperez          #+#    #+#             */
/*   Updated: 2025/05/19 16:58:02 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Need to change the infile to file1 and the outfile to file2 with dup2
void	child_process(t_pipex *pipex, int *fd, char **envp)
{
	int		infile;

	infile = open(pipex->file1, O_RDONLY);
	if (infile < 0)
		exit (ft_error(pipex, "Failed to open infile"));
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(pipex->cmd_path1, pipex->cmd1, envp);
	ft_error(pipex, "execve failed");
	exit (EXIT_FAILURE);
}

void	parent_process(t_pipex *pipex, int *fd, char **envp)
{
	int		outfile;

	outfile = open(pipex->file2, O_WRONLY, O_CREAT, O_TRUNC, 0644);
	if (outfile < 0)
		exit (ft_error(pipex, "Failed to open outfile"));
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(pipex->cmd_path2, pipex->cmd2, envp);
	ft_error(pipex, "execve failed");
	exit (EXIT_FAILURE);
}

// Need to do 2 forks -> 3 processes
int	fork_pipe(t_pipex *pipex, char **envp)
{
	int	pid[2];
	int	fd[2];

	if (pipe(fd) == -1)
		return (ft_error(pipex, "Pipe failed"));
	pid[0] = fork();
	if (pid[0] < 0)
		return (ft_error(pipex, "Fork failed"));
	if (pid[0] == 0)
		child_process(pipex, fd, envp);
	pid[1] = fork();
	if (pid[1] < 0)
		return (ft_error(pipex, "Fork failed"));
	if (pid[1] == 0)
		parent_process(pipex, fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (EXIT_SUCCESS);
}
