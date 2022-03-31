/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:02:59 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/03/31 13:13:16 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(char *argv[], char **env, int *tube)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		open_error();
	close(tube[0]);
	dup2(fd, 0);
	dup2(tube[1], 1);
	exec_cmd(argv, env, 2);
	close(fd);
}

static void	parent(char *argv[], char **env, int *tube)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		open_error();
	close(tube[1]);
	dup2(fd, 1);
	dup2(tube[0], 0);
	exec_cmd(argv, env, 3);
	close(fd);
}

int	main(int argc, char *argv[], char **env)
{
	int		tube[2];
	pid_t	pid;

	if (argc != 5)
		args_error();
	if (pipe(tube) != 0)
		pipe_error();
	pid = fork();
	if (pid == -1)
		fork_error();
	if (pid == 0)
		child(argv, env, tube);
	else
	{
		wait(NULL);
		parent(argv, env, tube);
	}
	return (EXIT_SUCCESS);
}
