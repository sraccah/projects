/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:07:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/27 17:57:06 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

static void		ft_exec_semicolon(char *str, char ***envs)
{
	char 		**cmd;

	cmd = ft_strsplit(ft_strtrim(str), ' ');
	ft_get_exit(cmd);
	ft_getcmd(cmd, envs);
}

int				main(int ac, char **av, char **envp)
{
	char		*buff;
	char		**envs;

	if ((envs = ft_getenv(envp)) && envp[0] == NULL)
	{
		ft_print_error("Empty env. Can't proceed to start the shell.");
		exit(1);
	}
	if (ac != 1)
		ft_print_error("Usage: ./42sh");
	if (ac == 1)
		ft_welcome(envs);
	while (ac == 1)
	{
		ft_prompt(envs);
		ft_get_next_line(0, &buff);
		av = ft_strsplit(ft_strtrim(buff), ';');
		while (*av)
		{
			if (ft_strlen(*av) > 0 && ft_check(*av) == -1)
				ft_exec_semicolon(*av, &envs);
			av++;
		}
	}
	return (0);
}
