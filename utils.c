/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:08:07 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/03/31 13:17:48 by hbourgeo         ###   ########.fr       */
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

static void	free_specifics_arrays(char **array1, char **array2)
{
	ft_free_array(array1);
	ft_free_array(array2);
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
	size_t	i;

	i = 0;
	all_paths = ft_split(my_getenv("PATH", env), ':');
	cmd_param = ft_split(cmd_arg, ' ');
	while (all_paths[i])
	{
		folder_path = ft_strjoin(all_paths[i], "/");
		cmd_path = ft_strjoin(folder_path, cmd_param[0]);
		free(folder_path);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_specifics_arrays(cmd_param, all_paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_specifics_arrays(cmd_param, all_paths);
	return (NULL);
}

void	exec_cmd(char **argv, char **env, int cmd_pos)
{
	char	**cmd_param;
	char	*path;

	cmd_param = ft_split(argv[cmd_pos], ' ');
	path = getpath(argv[cmd_pos], env);
	if (execve(path, cmd_param, env) == -1)
	{
		ft_free_array(cmd_param);
		free(path);
		exec_error();
	}
	ft_free_array(cmd_param);
	free(path);
}
