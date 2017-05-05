/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 16:05:15 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/27 15:28:10 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

pid_t			ft_getfork(void)
{
  	pid_t		pid;

  	if ((pid = fork()) == -1)
	{
	  	ft_print_error("[ERROR]: fork problem.");
	  	exit(1);
	}
  	else
		return (pid);
}

void			ft_get_exit(char **av)
{
	int			i;
	char		out[4] = "exit";

	i = 0;
	while (av[0][i] && av[0][i] == out[i])
		i++;
	if (i == 4 && av[0][i] == '\0')
		exit(0);
}

int				ft_check(char *buff)
{
	int			i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] != ' ' && buff[i] != '\t')
			return (-1);
		i++;
	}
	return (0);
}

char			**ft_getenv(char **envp)
{
	int			i;
	char		**envs;

	i = 0;
	while (envp[i])
		i++;
	envs = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (envp[i])
	{
		envs[i] = ft_strdup(envp[i]);
		i++;
	}
	envs[i] = NULL;
	return (envs);
}

void			ft_getinquote(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		while (str[i] != '"' && str[i])
			i++;
		if (str[i] == '"' && str[i])
			i++;
		if (str[i] != '"' && str[i])
		{
			while (str[i] != '"' && str[i])
			{
				ft_putchar(str[i]);
				i++;
			}
		}
	}
	ft_putchar('\n');
}
