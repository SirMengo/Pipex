/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:38:17 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/11 15:21:54 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char	*envp[], char *cmd)
{
	int		i;
	char	**paths;
	char	*path;
	char	*add_path;

	i = 0;
	//if !env
	while(ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	//if !envp[i]
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while(paths[i])
	{
		add_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(add_path,cmd);
		free(add_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[i])
	{
		i++;
		free(paths[i]);
	}
	return(0);
}

void	cmd_exec(char *argv, char *envp[])
{
	char	*path;
	char	**cmd;
	int		i;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(envp, cmd[0]);
	if (!path)
	{
		while(cmd[i])
		{
			i++;
			free(cmd[i]);
		}
		free(cmd); 
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}

void	error()
{
	perror("ERROR");
	exit(EXIT_FAILURE);
}