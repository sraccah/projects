/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 19:05:07 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/17 07:36:40 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list1			*ft_lstmap(t_list1 *list, t_list1 *(*f) (t_list1 *elem))
{
	t_list1		*tmp;

	if (list && list->next && f)
	{
		tmp = ft_lstmap(list->next, f);
		ft_lstadd(&tmp, f(list));
		return (tmp);
	}
	else if (list && f)
	{
		return (f(list));
	}
	else
	{
		return (NULL);
	}
}
