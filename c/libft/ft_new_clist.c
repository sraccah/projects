/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 10:01:01 by sraccah           #+#    #+#             */
/*   Updated: 2016/06/02 10:20:44 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_clist		*ft_new_clist(void)
{
	t_clist	*root;

	if ((root = (t_clist *)malloc(sizeof(*root))) == NULL)
		exit(1);
	root->len = 0;
	root->content = NULL;
	root->root = root;
	root->prev = root;
	root->next = root;
	return (root);
}
