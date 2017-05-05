/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:54:16 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/04 04:18:40 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_press_key(t_list *list)
{
	char		buffer[5];
	t_list		*tmp;

	tmp = list;
	while (42)
	{
		ft_action(list);
		buffer[2] = 0;
		read(0, buffer, 5);
		tmp = ft_press_key2(tmp, buffer);
		if ((buffer[0] == 'q' || buffer[0] == 10)
				|| (buffer[0] == 27 && buffer[2] == 0))
		{
			ft_putstr(tgetstr("cl", NULL));
			ft_putstr(tgetstr("me", NULL));
			if (buffer[0] == 10)
				ft_print_list_selected(list);
			return (0);
		}
	}
	return (0);
}

t_list			*ft_press_key2(t_list *tmp, char *buffer)
{
	if (buffer[0] == 27)
	{
		tmp->cursor = 'n';
		if (buffer[1] == 91 && buffer[2] == 'A')
			tmp = tmp->prev;
		if (buffer[1] == 91 && buffer[2] == 'B')
			tmp = tmp->next;
		if (buffer[1] == 91 && buffer[2] == 'C')
			tmp = tmp->next;
		if (buffer[1] == 91 && buffer[2] == 'D')
			tmp = tmp->prev;
		tmp->cursor = 'y';
	}
	if (buffer[0] == ' ')
	{
		if (tmp->select == 'y')
			tmp->select = 'n';
		else
			tmp->select = 'y';
		tmp->cursor = 'n';
		tmp = tmp->next;
		tmp->cursor = 'y';
	}
	return (tmp);
}

int				ft_action(t_list *list)
{
	t_list		*tmp;

	ft_putstr(tgetstr("cl", NULL));
	tmp = list;
	ft_action2(tmp);
	tmp = tmp->next;
	while (tmp != list)
	{
		ft_action2(tmp);
		tmp = tmp->next;
	}
	return (0);
}

void			ft_action2(t_list *tmp)
{
	if (tmp->cursor == 'y')
		ft_putstr(tgetstr("us", NULL));
	if (tmp->select == 'y')
		ft_putstr(tgetstr("mr", NULL));
	ft_putendl(tmp->data);
	ft_putstr(tgetstr("me", NULL));
	ft_putstr(tgetstr("vi", NULL));
}
