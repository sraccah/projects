/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 18:58:15 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/17 07:35:50 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_lstdelone(t_list1 **alst, void (*del)(void *, size_t))
{
	if (*alst && del)
	{
		del(&(*alst)->content, *(*alst)->content_size);
		(*alst)->next = NULL;
		ft_memdel((void **)alst);
	}
}
