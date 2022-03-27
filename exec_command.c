/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:08:07 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/03/27 15:38:10 by hbourgeo         ###   ########.fr       */
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

char	**get_cmd_param(char *cmd_arg)
{
	char	**cmd_param;
	
	cmd_param = ft_split(cmd_arg, ' '); /*free ? [N]*/
	return (cmd_param);
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

char	*getpath(char *cmd_arg, char **env)
{
	char	**all_paths;
	char	**cmd_param;
	char	*folder_path;
	char	*cmd_path;
	size_t 	i;

	i = 0;
	all_paths = ft_split(my_getenv("PATH", env), ':');
	cmd_param = get_cmd_param(cmd_arg);
	while (all_paths[i])
	{
		folder_path = ft_strjoin(all_paths[i], "/"); /*free [Y]*/
		cmd_path = ft_strjoin(folder_path, cmd_param[0]); /*free [Y]*/
		free(folder_path);
		if (access(cmd_path, F_OK | X_OK) == 0) /*voir errno*/
		{
			ft_free_array(cmd_param);
			ft_free_array(all_paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free_array(cmd_param);
	ft_free_array(all_paths);
	return (NULL);
}

int main(int argc, char **argv, char **envp)
{
	char	**cmd_param;
	char	*path;
	size_t	n;

	n = 0;

	// printf("%s\n", *argv + 1);
	cmd_param = get_cmd_param(argv[1]);
	
	path = getpath(argv[1], envp);
	printf("%s\n", path);
	if (argc > 1)
	{
		if (execve(path, cmd_param, NULL) == -1)
			perror("execve");
	}
	ft_free_array(cmd_param);
	free(path);
	printf("My pid is: %s\n", "test");
	return (0);
}