/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:35:18 by samperez          #+#    #+#             */
/*   Updated: 2025/05/13 12:26:04 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

typedef struct s_pipex
{
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
	char	*cmd_path1;
	char	*cmd_path2;
	char	**full_path;
}				t_pipex;

int		ft_error(t_pipex *pipex, int errno, char *str);
void	free_paths(char **path);
void	free_pipex(t_pipex *pipex);
int		file_check(t_pipex *pipex);
int		command_check(t_pipex *pipex, char **envp);

#endif