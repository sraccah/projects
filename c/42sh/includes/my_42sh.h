/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 14:47:56 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/27 17:43:00 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_42SH_H
# define MY_42SH_H

# include "libft.h"

/*
** Lists and Structures
*/

typedef struct	s_env
{
	char		*path;
	char		*user;
	char		*home;
	char		*pwd;
	char		*oldpwd;
}				t_env;

/*
** ft_init
*/

void			ft_help(void);
void			ft_welcome(char **envs);
void			ft_prompt(char **envs);

/*
** ft_get
*/

pid_t			ft_getfork(void);
void			ft_get_exit(char **av);
int				ft_check(char *buff);
char			**ft_getenv(char **envp);
void			ft_getcmd(char **av, char ***envs);
void			ft_getinquote(char *str);

/*
** ft_builtin
*/

char			**env_builtin(char **envs);
char			**setenv_builtin(char **envs, char *name, char *value);
char			**unsetenv_builtin(char **envs, char *name);
char			**cd_builtin(char **av, char **envs);

#endif /* !MY_42SH_H */
