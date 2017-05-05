/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 19:00:25 by sraccah           #+#    #+#             */
/*   Updated: 2016/03/22 12:26:50 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	if (lst && lst->next)
		ft_lstiter(lst->next, f);
	if (*f && lst)
		f(lst);
}
