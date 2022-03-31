/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:25:11 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/03/31 12:31:35 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_error(void)
{
	perror("open()");
	exit(EXIT_FAILURE);
}

void	pipe_error(void)
{
	perror("pipe()");
	exit(EXIT_FAILURE);
}

void	args_error(void)
{
	ft_putstr_fd("Syntaxe : ./pipex infile cmd1 cmd2 outfile\n", 1);
	exit(EXIT_FAILURE);
}

void	fork_error(void)
{
	perror("fork()");
	exit(EXIT_FAILURE);
}

void	exec_error(void)
{
	perror("execve()");
	exit(EXIT_FAILURE);
}
