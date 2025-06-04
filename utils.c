/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:38:17 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/04 15:52:57 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_exec(char argv, char *envp[])
{
	execve("/bin/bash", argv, NULL);
}

void	error()
{
	perror("ERROR");
	exit(EXIT_FAILURE);
}