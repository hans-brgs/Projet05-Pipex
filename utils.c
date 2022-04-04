/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:08:07 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/04/03 21:05:58 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	char	*folder_path;
	char	*cmd_path;
	size_t	i;

	i = 0;
	all_paths = ft_split(my_getenv("PATH", env), ':');
	while (all_paths[i])
	{
		folder_path = ft_strjoin(all_paths[i], "/");
		cmd_path = ft_strjoin(folder_path, cmd_arg);
		free(folder_path);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			ft_free_array(all_paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free_array(all_paths);
	return (cmd_arg);
}

void	exec_cmd(char **argv, char **env, int cmd_pos)
{
	char	**cmd_param;
	char	*path;

	cmd_param = ft_split(argv[cmd_pos], ' ');
	path = getpath(cmd_param[0], env);
	if (execve(path, cmd_param, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_param[0], 2);
		ft_free_array(cmd_param);
		exec_error();
	}
	ft_free_array(cmd_param);
	free(path);
}
