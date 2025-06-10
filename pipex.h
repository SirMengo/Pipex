/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:58:34 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/10 12:36:50 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

//# include "srcs/ft_printf/ft_printf.h"
# include "srcs/libft/libft.h"

void	error(void);
void	cmd_exec(char *argv, char *envp[]);

#endif