/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:22:44 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/04 04:59:57 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

int					ft_init_term(struct termios *term)
{
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_print_error("[ERROR] : getenv failed.");
		return (-1);
	}
	if (tgetent(NULL, name_term) < 1)
	{
		ft_print_error("[ERROR] : tgetent failed.");
		return (-1);
	}
	if (tcgetattr(0, term) == -1)
	{
		ft_print_error("[ERROR] : tcgetattr failed.");
		return (-1);
	}
	return (0);
}

int					ft_apply_term(struct termios *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
	{
		ft_print_error("[ERROR] : tcsetattr failed.");
		return (-1);
	}
	return (0);
}

int					ft_reset_term(struct termios *term)
{
	if (tcgetattr(0, term) == -1)
	{
		ft_print_error("[ERROR] : tcgetattr failed.");
		return (-1);
	}
	term->c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, term) == -1)
	{
		ft_print_error("[ERROR] : tcsetattr failed.");
		return (-1);
	}
	ft_putstr(tgetstr("ve", NULL));
	return (0);
}
