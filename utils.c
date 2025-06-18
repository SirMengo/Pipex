/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:38:17 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/18 16:15:27 by msimoes          ###   ########.fr       */
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

static char	*popu_paths(char **paths, char **s_cmd, char *path, char *add_path)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		add_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(add_path, s_cmd[0]);
		free(add_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_str(s_cmd);
			free_str(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_str(paths);
	free_str(s_cmd);
	return (NULL);
}

static char	*find_path(char	*envp[], char *cmd)
{
	int		i;
	char	**paths;
	char	**s_cmd;
	char	*path;
	char	*add_path;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	path = NULL;
	add_path = NULL;
	i = 0;
	if (!envp && !*envp)
		error();
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	s_cmd = ft_split(cmd, ' ');
	return (popu_paths(paths, s_cmd, path, add_path));
	return (cmd);
}

void	cmd_exec(char *argv, char *envp[])
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
		not_found(cmd);
	path = find_path(envp, cmd[0]);
	if (!path)
		not_found(cmd);
	if (path == cmd[0] && !ft_strchr(cmd[0], '/'))
		not_found(cmd);
	if (execve(path, cmd, envp) == -1)
	{
		free_str(cmd);
		error();
	}
}
