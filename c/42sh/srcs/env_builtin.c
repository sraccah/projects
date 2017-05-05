/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 19:01:29 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/27 17:42:57 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

static char		**ft_realenvs(char **envs, char *name, char *value)
{
	int			i;
	char		**tmp;

	tmp = envs;
	i = 0;
	ft_print_purple("REALENV");
	while (tmp[i])
		i++;
	envs = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (tmp[i])
	{
		envs[i] = ft_strdup(tmp[i]);
		ft_print_green(envs[i]);
		i++;
	}
	envs[i] = ft_strjoin(ft_strjoin(name, "="), value);
	ft_print_green(envs[i]);
	envs[i + 1] = NULL;
	return (envs);
}

char			**env_builtin(char **envs)
{
	int			i;

	i = 0;
	while (envs[i])
	{
		ft_putendl(envs[i]);
		i++;
	}
	return (envs);
}

char			**setenv_builtin(char **envs, char *name, char *value)
{
	int			i;

	if (name == NULL || value == NULL)
		envs = env_builtin(envs);
	else
	{
		ft_print_purple("SETENV");
		i = 0;
		while (envs[i])
		{
			ft_print_purple("SETENV2");
			if (ft_strstr(envs[i], ft_strjoin(name, "=")))
			{
				envs[i] = ft_strjoin(ft_strsub(envs[i], 0, ft_strlen(name) + 1)
										, value);
				return (envs);
			}
			i++;
		}
		envs = ft_realenvs(envs, name, value);
	}
	return (envs);
}

char			**unsetenv_builtin(char **envs, char *name)
{
	int			i;
	int			j;
	char		**tmp;

	i = 0;
	while (envs[i])
		i++;
	tmp = envs;
	envs = malloc(sizeof(char *) * i);
	i = 0;
	j = 0;
	while (tmp[j])
	{
		if (ft_strstr(tmp[j], ft_strjoin(name, "=")) == NULL)
		{
			envs[i] = ft_strdup(tmp[j]);
			i++;
		}
		j++;
	}
	free(tmp);
	return (envs);
}