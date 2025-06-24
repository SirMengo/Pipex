/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:06:26 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/24 15:38:13 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_files(int *fd, int file)
{
	if (close(fd[0]) < 0 || close(fd[1]) < 0)
		error();
	if (close(file))
		error();
}

void	child_process1(char *argv[], char *envp[], int *fd)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
	{
		close(fd[0]);
		close(fd[1]);
		error();
	}
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close_files(fd, file1);
	cmd_exec(argv[2], envp);
	exit(EXIT_FAILURE);
}

void	child_process2(char *argv[], char *envp[], int *fd)
{
	int	file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 < 0)
	{
		close(fd[0]);
		close(fd[1]);
		error();
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close_files(fd, file2);
	cmd_exec(argv[3], envp);
	exit(EXIT_FAILURE);
}

int	ft_wait(pid_t *proc_id)
{
	int	status;
	int	exit_code;

	exit_code = 0;
	waitpid(proc_id[1], &status, 0);
	if (WIFEXITED (status))
		exit_code = WEXITSTATUS(status);
	waitpid(proc_id[0], NULL, 0);
	return (exit_code);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		exit_code;
	pid_t	proc_id[2];

	exit_code = 1;
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		proc_id[0] = fork();
		if (proc_id[0] == 0)
			child_process1(argv, envp, fd);
		else
		{
			proc_id[1] = fork();
			if (proc_id[1] == 0)
				child_process2(argv, envp, fd);
		}
		if (close(fd[0]) < 0 || close(fd[1]) < 0)
			error();
		exit_code = ft_wait(proc_id);
	}
	else
		write(1, "Invalid number of arguments", 27);
	return (exit_code);
}
