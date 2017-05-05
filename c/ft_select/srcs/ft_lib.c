/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 19:05:37 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/04 04:42:12 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

t_list			*ft_addinlist(t_list *list, char *data)
{
	t_list		*tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
	{
		ft_print_error("[ERROR] : Malloc error in ft_addinlist");
		return (NULL);
	}
	tmp->data = ft_strdup(data);
	tmp->cursor = 'n';
	tmp->select = 'n';
	if (list == NULL)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		list = tmp;
	}
	else
	{
		tmp->prev = list->prev;
		list->prev->next = tmp;
		tmp->next = list;
		list->prev = tmp;
	}
	list->cursor = 'y';
	return (list);
}

void			ft_print_list(t_list *list)
{
	t_list		*tmp;

	tmp = list;
	if (tmp != NULL)
	{
		ft_putendl(tmp->data);
		tmp = tmp->next;
		while (tmp != list)
		{
			ft_putendl(tmp->data);
			tmp = tmp->next;
		}
	}
}

void			ft_print_list_selected(t_list *list)
{
	t_list		*tmp;

	tmp = list;
	if (tmp != NULL)
	{
		if (tmp->select == 'y')
		{
			ft_putstr(tmp->data);
			ft_putstr(" ");
		}
		tmp = tmp->next;
		while (tmp != list)
		{
			if (tmp->select == 'y')
			{
				ft_putstr(tmp->data);
				ft_putstr(" ");
			}
			tmp = tmp->next;
		}
		ft_putstr(tgetstr("le", NULL));
	}
	ft_putstr("\n");
}

int				ft_getinlist(char **data, t_list **list)
{
	int			i;

	*list = NULL;
	i = 0;
	while (data[i])
	{
		*list = ft_addinlist(*list, data[i]);
		i++;
	}
	return (++i);
}

char			*ft_strdup(char *src)
{
	char		*dest;
	int			i;
	int			len;

	i = 0;
	len = 0;
	if (src == '\0')
		return (0);
	while (src[len] != '\0')
		len++;
	if (!(dest = (char *)malloc(sizeof(*src) * (len + 1))))
	{
		ft_print_error("[ERROR] : Malloc error in ft_strdup");
		return (NULL);
	}
	if (dest == 0)
		return (0);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
