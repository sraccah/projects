/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 18:50:33 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/17 07:36:51 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list1			*ft_lstnew(void const *content, size_t content_size)
{
	t_list1		*tmp;

	tmp = (t_list1 *)malloc(sizeof(t_list1));
	if (tmp)
	{
		if (content)
		{
			tmp->content = ft_memalloc(content_size);
			ft_memcpy(tmp->content, content, content_size);
			tmp->content_size = &content_size;
		}
		else
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		tmp->next = NULL;
	}
	return (tmp);
}
