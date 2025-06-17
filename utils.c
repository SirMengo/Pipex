/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:38:17 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/17 16:03:21 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
		free(str[--i]);
	free(str);
}

static char	*find_path(char	*envp[], char *cmd)
{
	int		i;
	char	**paths;
	char	*path;
	char	*add_path;
	char	**s_cmd;

	i = 0;
	if (!envp && !*envp)
		error();
	while(ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return(NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	s_cmd = ft_split(cmd, ' ');
	while(paths[i])
	{
		add_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(add_path,s_cmd[0]);
		free(add_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_str(s_cmd);
			return (path);
		}
		free(path);
		i++;
	}
	i = -1;
	free(paths);
	free_str(s_cmd);
	return(cmd);
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