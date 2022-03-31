/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:48:56 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/03/31 16:22:36 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	ft_free_array(char **array);
char	*my_getenv(char *name, char **env);
char	*getpath(char *cmd_arg, char **env);
void	exec_cmd(char **argv, char **env, int cmd_pos);
void	open_error(void);
void	pipe_error(void);
void	fork_error(void);
void	args_error(void);
void	exec_error(void);

#endif