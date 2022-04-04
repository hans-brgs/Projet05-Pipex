/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:02:59 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/04/03 21:29:24 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_file(char *argv[], int n_arg)
{
	int	fd;

	if (n_arg == 1)
	{
		fd = open(argv[n_arg], O_RDONLY, 0777);
		if (fd == -1)
			open_error();
		dup2(fd, STDIN_FILENO);
		return (fd);
	}
	else
	{
		fd = open(argv[n_arg], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			open_error();
		dup2(fd, STDOUT_FILENO);
		return (fd);
	}
}

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
	int		status;

	if (pipe(tube) != 0)
		pipe_error();
	pid = fork();
	if (pid == -1)
		fork_error();
	if (pid == 0)
		child(argv, env, tube, n_arg);
	else
	{
		waitpid(pid, &status, WUNTRACED | WNOHANG);
		parent(tube);
	}
}

int	main(int argc, char *argv[], char **env)
{
	int	n;
	int	fd_input;
	int	fd_output;

	n = 2;
	if (argc < 5)
		args_error();
	fd_input = open_file(argv, 1);
	while (n < argc - 2)
	{
		multi_pipe(argv, env, n);
		if (n == 2)
			close(fd_input);
		n++;
	}
	fd_output = open_file(argv, argc - 1);
	exec_cmd(argv, env, argc - 2);
	close(fd_output);
	return (EXIT_SUCCESS);
}
