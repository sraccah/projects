/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 19:00:25 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/17 07:35:58 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_lstiter(t_list1 *lst, void (*f) (t_list1 *elem))
{
	if (lst && lst->next && f)
	{
		f(lst->next);
	}
	else if (lst && f)
	{
		f(lst);
	}
}
