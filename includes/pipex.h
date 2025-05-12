/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:35:18 by samperez          #+#    #+#             */
/*   Updated: 2025/05/12 14:38:52 by samperez         ###   ########.fr       */
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

typedef struct s_pipex{
	char	*file1;
	char	*file2;
	char	*command1;
	char	*command2;
	char	*command_path1;
	char	*command_path2;
}				t_pipex;

int		ft_error(t_pipex *pipex, int errno, char *str);
void	free_pipex(t_pipex *pipex);
int		file_check(t_pipex *pipex, char *file1, char *file2);
int		command_check(t_pipex *pipex, char *command1, char *command2, char **envp);

#endif