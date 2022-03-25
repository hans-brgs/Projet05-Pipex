/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:08:07 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/03/24 19:28:29 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

void	ft_free_array(char **array)
{
	size_t	n;

	n = 0;
	while (array[n])
	{
		free(array[n]);
		n++;
	}
	free(array);
}

char	**getparam(char *cmd_arg)
{
	char	**param;
	size_t	len;

	len = 0;
	while (*cmd_arg && *cmd_arg != ' ')
	{
		cmd_arg++;
	}
	cmd_arg++;
	param = ft_split(cmd_arg, ' '); /*free ? [N]*/
	return (param);
}

char	*my_getenv(char *name, char **env)
{
	char	*getenv;

	while (*env)
	{
		if (ft_strnstr(*env, name, ft_strlen(name)))
		{
			getenv = ft_strchr(*env, '=');
			return (getenv + 1);
		}
		env++;
	}
	return (NULL);
}

char	*getcmd(char *cmd_arg)
{
	char	*cmd;
	size_t	len;

	len = 0;
	while (cmd_arg[len] && cmd_arg[len] != ' ')
	{
		len++;
	}
	cmd = ft_calloc(len + 1, sizeof(char));
	if (!cmd)
		return (NULL);
	ft_strlcpy(cmd, cmd_arg, len + 1); /*free [Y]*/
	return (cmd);
}

char	*getpath(char *cmd_arg, char **env)
{
	char	**all_paths;
	char	*cmd;
	char	*folder_path;
	char	*cmd_path;
	size_t 	i;

	i = 0;
	all_paths = ft_split(my_getenv("PATH", env), ':');
	cmd = getcmd(cmd_arg);
	while (all_paths[i])
	{
		folder_path = ft_strjoin(all_paths[i], "/"); /*free [Y]*/
		cmd_path = ft_strjoin(folder_path, cmd); /*free [Y]*/
		free(folder_path);
		if (access(cmd_path, F_OK | X_OK) == 0) /*voir errno*/
		{
			free(cmd);
			ft_free_array(all_paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free(cmd);
	ft_free_array(all_paths);
	return (NULL);
}

int main(int argc, char **argv, char **envp)
{
	char	**param;
	char	*path;

	param = getparam(argv[1]);
	path = getpath(argv[1], envp);
	if (argc > 1)
		if (execve(path, param, envp) == -1)
			perror("execve");
	ft_free_array(param);
	printf("My pid is: %d\n", getpid());
}