/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:06:26 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/10 12:42:12 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *argv[], char *envp[], int *fd)
{
	int	file1;
	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
		error();
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(file1);
	cmd_exec(argv[2], envp);
	close(fd[1]);
}

void	parent_process(char *argv[], char *envp[], int *fd)
{
	int	file2;
	
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 < 0)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(fd[1]);
	close(file2);
	cmd_exec(argv[3], envp);
	close(fd[0]);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	proc_id;
	
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		proc_id = fork();
		if (proc_id == 0)
			child_process(argv, envp, fd);
		else
		{	
			parent_process(argv, envp, fd);
			waitpid(proc_id, NULL, 0);
		}
	}
}
