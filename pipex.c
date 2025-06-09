/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:06:26 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/09 14:45:34 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *argv[], char *envp[], int *fd)
{
	int	file1;
	file1 = open(argv[1], O_RDONLY);
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	cmd_exec(argv[2], envp);
	close(fd[0]);
	close(file1);
}

void	parent_process(char *argv[], char *envp[], int *fd)
{
	int	file2;
	
	file2 = open(argv[4], O_RDWR | O_CREAT);
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	cmd_exec(argv[3], envp);
	close(fd[1]);
	close(file2);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	proc_id;
	
	if (argc == 5)
	{
		pipe(fd);
		if (pipe(fd) == -1)
			error();
		proc_id = fork();
		if (proc_id == 0)
			child_process(argv, envp, fd);
		parent_process(argv, envp, fd);
		waitpid(proc_id, NULL, 0);
	}
}
