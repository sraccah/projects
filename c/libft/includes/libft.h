/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2016/06/02 10:28:11 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 1024
# endif

# define BLACK     "\033[1;30m"
# define RED       "\033[1;31m"
# define GREEN     "\033[1;32m"
# define YELLOW    "\033[1;33m"
# define BLUE      "\033[1;34m"
# define PURPLE    "\033[1;35m"
# define CYAN      "\033[1;36m"
# define GREY      "\033[1;37m"
# define RESET	   "\033[0m"
# define BOLD	   "\033[1m"
# define LINE	   "\033[4m"
# define UNLINE	   "\033[24m"

/*
** Lists / Strutures / Trees
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_clist
{
	void			*content;
	int 			len;
	struct s_clist	*root;
	struct s_clist	*prev;
	struct s_clist	*next;
}					t_clist;

typedef struct		s_node
{
	char			*data;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

/*
** Functions for Lists / Strutures / Trees and HashTables
*/

t_clist				*ft_new_clist(void);
void				ft_before_clist(t_clist *elem, void *content);
void				ft_after_clist(t_clist *elem, void *content);
void				ft_head_clist(t_clist *root, void *content);
void				ft_tail_clist(t_clist *root, void *content);
void				ft_del_clist(t_clist **list);
void				ft_free_elem(t_clist *list);
void				ft_remove_elem(t_clist *list);
void				ft_removefirst_elem(t_clist *list);
void				ft_removelast_elem(t_clist *list);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f) (t_list *elem));
void				ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void				ft_print_list(t_list *list);
int					ft_size_list(t_list *list);
t_list				*ft_lstmap(t_list *list, t_list *(*f) (t_list *elem));
int					ft_search_node(t_node *tree, char *data);
void				ft_print_tree(t_node *tree);
void				ft_clear_tree(t_node **tree);
int					ft_hashb(char *str);

/*
** Added for posterity
*/

void				ft_print_color(char *color, char *option, char *error, int bs);
int					ft_is(char *str, int c);
int					ft_isint(char *str);
void				ft_print_error(char *error);
void				ft_print_gnobs(char *error);
void				ft_print_rnobs(char *error);
void				ft_print_bnobs(char *error);
void				ft_print_pnobs(char *error);
void				ft_print_ynobs(char *error);
void				ft_print_red(char *error);
void				ft_print_green(char *error);
void				ft_print_blue(char *error);
void				ft_print_purple(char *error);
void				ft_print_yellow(char *error);
int					ft_logfile(char *file, void *towrite, int mode);
char				*ft_strreverse(const char *s);
size_t				ft_strnlen(const char *s, size_t maxlen);

/*
** Lib C
*/

void				ft_putchar(char c);
int					ft_linelen(char const *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(const char *str);
void				ft_putendl_fd(const char *str, int fd);
size_t				ft_strlen(const char *s);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				ft_bzero(void *s, size_t n);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strlcat(char *dest, const char *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f) (char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
char				*ft_strmap(const char *s, char (*f) (char));
char				*ft_strmapi(const char *s, char (*f) (unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);

#endif
