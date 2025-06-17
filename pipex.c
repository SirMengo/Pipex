/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:06:26 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/17 15:21:54 by msimoes          ###   ########.fr       */
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
		error();
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
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close_files(fd, file2);
	cmd_exec(argv[3], envp);
	exit(EXIT_FAILURE);
}

void	ft_wait(pid_t *proc_id)
{
	waitpid(proc_id[1], NULL, 0);
	waitpid(proc_id[0], NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	proc_id[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		proc_id[0] = fork();
		if (proc_id[0] == 0)
		{
			child_process1(argv, envp, fd);
			exit(EXIT_FAILURE);
		}
		else
		{	
			proc_id[1] = fork();
			if (proc_id[1] == 0)
				child_process2(argv, envp, fd);
		}
		if (close(fd[0]) < 0 || close(fd[1]) < 0)
			error();
		ft_wait(proc_id);
	}
	else
		write(1, "Invalid number of arguments", 27);
	return (0);
}
