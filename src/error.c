/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:48:13 by samperez          #+#    #+#             */
/*   Updated: 2025/05/02 10:01:55 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_error(int errno, char *str)
{
	ft_printf("%s - %s\n", str, strerror(errno));
	return (EXIT_FAILURE);
}