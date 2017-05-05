/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parselex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 18:56:48 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/27 19:27:56 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

static char			*build_path(char **split_path, char **av)
{
	int				i;
	char			*path;

	i = 0;
	while (split_path[i])
	{
		path = ft_strjoin(ft_strjoin(split_path[i], "/"), av[0]);
		if (access(path, F_OK) == 0)
			return (path);
		if (access(av[0], F_OK) == 0)
		{
			path = av[0];
			return (path);
		}
		free(path);
		i++;
	}
	return (NULL);
}

static char			*get_path(char **av, char **envs)
{
	int				i;
	char			*path;
	char			**split_path;

	i = 0;
	while (envs[i])
	{
		if (ft_strstr(envs[i], "PATH=") && !ft_strstr(envs[i], "_PATH="))
		{
			path = ft_strsub(envs[i], 5, ft_strlen(envs[i]));
			split_path = ft_strsplit(path, ':');
			free(path);
			return (build_path(split_path, av));
		}
		i++;
	}
	return (NULL);
}

static int			get_cmd_builtin(char **av, char ***envs)
{
	if (av[0] != NULL)
	{
		if (ft_strcmp(av[0], "cd") == 0)
			*envs = cd_builtin(av, *envs);
		else if (ft_strcmp(av[0], "echo") == 0)
			ft_getinquote(av[1]);
		else if (ft_strcmp(av[0], "env") == 0)
			*envs = env_builtin(*envs);
		else if (ft_strcmp(av[0], "setenv") == 0)
		{
			if (av[1] != NULL && av[2] != NULL && av[3] == NULL)
				*envs = setenv_builtin(*envs, av[1], av[2]);
			else
				ft_print_error("usage: setenv (name = av[1]) (value = av[2])");
		}
		else if (ft_strcmp(av[0], "unsetenv") == 0)
		{
			if ((av[1] && !av[2]) && (ft_strcmp(av[1], "HOME=")
				&& ft_strcmp(av[1], "HOME") && ft_strcmp(av[1], "USER=")
					&& ft_strcmp(av[1], "USER") && ft_strcmp(av[1], "SHELL")
						&& ft_strcmp(av[1], "SHELL=") && ft_strcmp(av[1], "PWD")
							&& ft_strcmp(av[1], "PWD=") && ft_strcmp(av[1], "PATH")
								&& ft_strcmp(av[1], "PATH=") && ft_strcmp(av[1], "OLDPWD")
									&& ft_strcmp(av[1], "OLDPWD=")))
				*envs = unsetenv_builtin(*envs, av[1]);
		}
		else if (ft_strcmp(av[0], "help") == 0)
			ft_help();
		else
			return (-1);
		return (0);
	}
	else
		return (-1);
}

void				ft_getcmd(char **av, char ***envs)
{
	pid_t			pid;
	int				cmd;
	t_env			senv;

	senv.path = get_path(av, *envs);
	if ((cmd = get_cmd_builtin(av, &*envs)) == -1)
	{
		if (senv.path == NULL && av[0] != NULL)
			ft_is_not_found(av[0]);
		else if (cmd == -1)
		{
			pid = ft_getfork();
			if (pid == 0 && cmd == -1)
				execve(senv.path, av, *envs);
			else
				wait(NULL);
		}
	}
}