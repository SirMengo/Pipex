/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:53:57 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/18 15:53:59 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	not_found(char **cmd)
{
	free_str(cmd);
	write(2, "ERROR: Command not found\n", 26);
	exit(127);
}

void	error(void)
{
	perror("ERROR");
	exit(EXIT_FAILURE);
}
