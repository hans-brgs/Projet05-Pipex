/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:02:59 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/04/03 14:31:41 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(char *argv[], char **env, int *tube, int n_arg)
{
	close(tube[0]);
	dup2(tube[1], STDOUT_FILENO);
	exec_cmd(argv, env, n_arg);
}

static void	parent(int *tube)
{
	close(tube[1]);
	dup2(tube[0], STDIN_FILENO);
}

static void	multi_pipe(char *argv[], char **env, int n_arg)
{
	int		tube[2];
	pid_t	pid;
	//int		status;

	if (pipe(tube) != 0)
		pipe_error();
	pid = fork();
	if (pid == -1)
		fork_error();
	if (pid == 0)
		child(argv, env, tube, n_arg);
	else
	{
		//waitpid(pid, &status, WUNTRACED | WNOHANG);
		parent(tube);
	}
}

int	main(int argc, char *argv[], char **env)
{
	int	n;
	int	fd[2];

	n = 2;
	if (argc < 5)
		args_error();
	fd[0] = open(argv[1], O_RDONLY, 0777);
	if (fd[0] == -1)
		open_error();
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd[1] == -1)
		open_error();
	dup2(fd[0], STDIN_FILENO);
	while (n < argc - 2)
	{
		multi_pipe(argv, env, n);
		if (n == 2)
			close(fd[0]);
		n++;
	}
	dup2(fd[1], STDOUT_FILENO);
	exec_cmd(argv, env, argc - 2);
	close(fd[1]);
	return (EXIT_SUCCESS);
}
