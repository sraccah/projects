/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 14:47:56 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/18 10:24:12 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft.h"

/*
** Lists and Structures
*/

typedef struct		s_list
{
	int				val;
	int				len;
	struct s_list	*root;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

/*
** list.c
*/

t_list				*ft_new_list(void);
void				ft_before_list(t_list *elem, int val);
void				ft_after_list(t_list *elem, int val);
void				ft_head_list(t_list *root, int val);
void				ft_tail_list(t_list *root, int val);

/*
** list2.c
*/

void				ft_del_list(t_list **list);
void				ft_free_elem(t_list *list);
void				ft_remove_elem(t_list *list);
void				ft_removefirst_elem(t_list *list);
void				ft_removelast_elem(t_list *list);

/*
** r.c
*/

void				ft_ra_ps(t_list *list, int count);
void				ft_rb_ps(t_list *list1);
void				ft_rr_ps(t_list *list, t_list *list1);
void				ft_rra_ps(t_list *list);
void				ft_rrb_ps(t_list *list1);

/*
** s.c
*/

void				ft_sa_ps(t_list *list, int count);
void				ft_sb_ps(t_list *list1);
void				ft_ss_ps(t_list *list, t_list *list1);

/*
** p.c
*/

void				ft_pa_ps(t_list *list, t_list *list1);
void				ft_pb_ps(t_list *list, t_list *list1, int count);
void				ft_rrr_ps(t_list *list, t_list *list1);
void				ft_print_list_ps(t_list *list);

/*
** sort.c
*/

void				ft_swap_elem(t_list *list, t_list *list1);
int					ft_sort_list(t_list *list, t_list *list1);
int					ft_isminor_list(t_list *list);

#endif
