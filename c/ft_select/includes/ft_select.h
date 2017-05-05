/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:08:53 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/04 04:10:18 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <term.h>
# include <unistd.h>
# include <termios.h>

/*
** Lists and Structures
*/

typedef struct		s_list
{
	char			*data;
	int				cursor;
	int				select;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

/*
** Functions for Lists and Strutures
*/

t_list				*ft_addinlist(t_list *list, char *data);
void				ft_print_list(t_list *list);
void				ft_print_list_selected(t_list *list);
int					ft_getinlist(char **data, t_list **list);

/*
** ft_error
*/

int					ft_print_error(char *error);

/*
** ft_libc
*/

char				*ft_strdup(char *src);
size_t				ft_strlen(const char *str);
void				ft_putendl(char *str);
void				ft_putstr(char *str);

/*
** ft_term
*/

int					ft_init_term(struct termios *term);
int					ft_apply_term(struct termios *term);
int					ft_reset_term(struct termios *term);

/*
** ft_action
*/

int					ft_press_key(t_list *list);
t_list				*ft_press_key2(t_list *tmp, char *buffer);
int					ft_action(t_list *list);
void				ft_action2(t_list *tmp);
void				ft_press_arrow(t_list *tmp, char *buffer);

#endif
