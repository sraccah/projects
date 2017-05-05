/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 08:26:35 by sraccah           #+#    #+#             */
/*   Updated: 2015/05/10 19:14:53 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

extern void 	ft_bzero(void *str, int nb);
extern int 		ft_isdigit(int nb);
extern int 		ft_isalpha(int nb);
extern int 		ft_isprint(int nb);
extern int 		ft_isascii(int nb);
extern int 		ft_isalnum(int nb);
extern int 		ft_toupper(int c);
extern int 		ft_tolower(int c);
extern void 	ft_puts(char *str);
extern int 		ft_strlen(char *str);
extern void 	*ft_memcpy(void *dst, void *src, size_t len);
extern void 	*ft_memset(void *b, int c, size_t len);
extern char 	*ft_strdup(char *str);
extern char		*ft_strnew(size_t size);
extern void 	ft_putchar(char c);

void 			*malloc(size_t size);

#define BLACK   "\033[1;30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define PURPLE  "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[1;37m"
#define STOP 	"\033[0m"

void			c_putchar(char c)
{
	if (c)
		write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	if (str)
		while (*str)
			write(1, str++, 1);

}

int				ft_error_ptr(int c, int ret, int (*this_ptr)(int), int (*libc_ptr)(int), int test)
{
	if (ret == 0)
		ft_putstr(RED"TESTS KO\n"STOP);
	printf("\n[ERROR]\t• test %d\n\t  char = <%c> ascii = <%d>\n\t  expected = <%d>\n\t  returned = <%d>\n", test, c, c, libc_ptr(c), this_ptr(c));
	return (1);
}

int				ft_error_bzero(int ret, char *str1, char *str2, int test)
{
	if (ret == 0)
		ft_putstr(RED"TESTS KO\n"STOP);
	printf("\n[ERROR]\t• test %d\n\t  expected = <%s>\n\t  returned = <%s>\n", test, str1, str2);
	return (1);
}

int 			ft_error_strlen(int ret, char *str, int len1, int len2, int test)
{
	if (ret == 0)
		ft_putstr(RED"TESTS KO\n"STOP);
	printf("\n[ERROR]\t• test %d\n\t  str = <%s>\n\t  expected = <%d>\n\t  returned = <%d>\n", test, str, len2, len1);
	return (1);	
}

int 			ft_error_ft_memcpy(int ret, char *str1, char *str2, int test){
	if (ret == 0)
		ft_putstr(RED"TESTS KO\n"STOP);
	printf("\n[ERROR]\t• test %d\n\t  expected = <%s>\n\t  returned = <%s>\n", test, str1, str2);
	return (1);	
}

int 			ft_error_ft_memset(int ret, char *str1, char *str2, int test){
	if (ret == 0)
		ft_putstr(RED"TESTS KO\n"STOP);
	printf("\n[ERROR]\t• test %d\n\t  expected = <%s>\n\t  returned = <%s>\n", test, str1, str2);
	return (1);	
}

int 		ft_error_strdup(int ret, char *str, int test){
	if (ret == 0)
		ft_putstr(RED"TESTS KO\n"STOP);
	printf("\t• test %d\n\t  expected = <%s>\n\t  returned = <%s>\n", test,  strdup(str), ft_strdup(str));
	return (1);	
}

int 			ft_check_s1_s2(char *str1, char *str2, int n){
	int 		i;
	int 		j;

	i = 0;
	j = 0;
	while(i < n)
	{
		if (str1[i++] != 0)
		{
			if (str1[i] != str2[i])
				return (1);
		}
	}
	while(j < n)
	{
		if (str2[j++] != 0)
		{
			if (str1[j] != str2[j])
				return (1);
		}
	}
	if (i != j)
		return (1);
	return (0);
}

// FT_BZERO
void			ft_test_bzero()
{
	int 		ret;
	char 		*str1;
	char 		*str2;
	char 		*bkp1;
	char 		*bkp2;
	char 		c1;
	char 		c2;

	c1 = 'c';
	c2 = 'c';
	ret = 0;
	str1 = NULL;
	str2 = NULL;
	bkp1 = NULL;
	bkp2 = NULL;
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_bzero\n");
	ft_putstr(CYAN"ft_bzero (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_bzero   = "STOP);
	str1 = strdup("wesh");
	str2 = strdup("wesh");
	ft_bzero(str1, 0);
	bzero(str2, 0);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, strlen(str1)))
		ret = ft_error_bzero(ret, str1, str2, 0);
	str1 = strdup("wesh");
	str2 = strdup("wesh");
	ft_bzero(str1, 1);
	bzero(str2, 1);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, strlen(str1)))
		ret = ft_error_bzero(ret, str1, str2, 1);
	str1 = strdup("wesh");
	str2 = strdup("wesh");
	bkp1 = str1;
	bkp2 = str2;
	ft_bzero(str1, 1);
	bzero(str2, 1);
	str1++;
	str2++;
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, strlen(str1)))
		ret = ft_error_bzero(ret, str1, str2, 2);
	str1 = strdup("wesh");
	str2 = strdup("wesh");
	ft_bzero(str1, 10);
	bzero(str2, 10);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, 10))
		ret = ft_error_bzero(ret, str1, str2, 3);
	str1 = strdup("wesh");
	str2 = strdup("wesh");
	ft_bzero(str1, 100);
	bzero(str2, 100);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, 100))
		ret = ft_error_bzero(ret, str1, str2, 4);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	ft_bzero(str1, 0);
	bzero(str2, 0);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, strlen(str1)))
		ret = ft_error_bzero(ret, str1, str2, 5);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	ft_bzero(str1, 1);
	bzero(str2, 1);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, strlen(str1)))
		ret = ft_error_bzero(ret, str1, str2, 6);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	bkp1 = str1;
	bkp2 = str2;
	ft_bzero(str1, 1);
	bzero(str2, 1);
	str1++;
	str2++;
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, strlen(str1)))
		ret = ft_error_bzero(ret, str1, str2, 7);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	ft_bzero(str1, 10);
	bzero(str2, 10);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, 10))
		ret = ft_error_bzero(ret, str1, str2, 8);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	ft_bzero(str1, 100);
	bzero(str2, 100);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, 100))
		ret = ft_error_bzero(ret, str1, str2, 9);
	c1 = 'c';
	c2 = 'c';
	ft_bzero(&c1, 1);
	bzero(&c2, 1);
	if (ft_check_s1_s2(&c1, &c2, 1))
		ret = ft_error_bzero(ret, &c1, &c2, 10);
	c1 = 'c';
	c2 = 'c';
	ft_bzero(&c1, 10);
	bzero(&c2, 10);
	if (ft_check_s1_s2(&c1, &c2, 10))
		ret = ft_error_bzero(ret, &c1, &c2, 11);
	if (!ret)
		ft_putstr(GREEN"TESTS OK\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_bzero\n");
}

// FT_ISAPLHA
void			ft_test_isalpha()
{
	int 		c;
	int 		ret;
	int 		(*this_ptr)(int);
	int 		(*libc_ptr)(int);

	ret = 0;
	c = 'a';
	this_ptr = ft_isalpha;
	libc_ptr = isalpha;
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_isalpha\n");
	ft_putstr(CYAN"ft_isalpha (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_isalpha = "STOP);
	while (c <= 'z')
	{
		if (ft_isalpha(c) != isalpha(c))
			ret = ft_error_ptr(c, ret, this_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_isalpha(65) != isalpha(65))
		ret = ft_error_ptr(65, ret, this_ptr, libc_ptr, 1); 
	if (ft_isalpha('a') != isalpha('a'))
		ret = ft_error_ptr('a', ret, this_ptr, libc_ptr, 2); 
	if (ft_isalpha(97) != isalpha(97))
		ret = ft_error_ptr(97, ret, this_ptr, libc_ptr, 3); 
	if (ft_isalpha('z') != isalpha('z'))
		ret = ft_error_ptr('z', ret, this_ptr, libc_ptr, 4); 
	if (ft_isalpha(122) != isalpha(122))
		ret = ft_error_ptr(122, ret, this_ptr, libc_ptr, 5); 
	if (ft_isalpha('\0') != isalpha('\0'))
		ret = ft_error_ptr('\0', ret, this_ptr, libc_ptr, 6); 
	if (ft_isalpha(48) != isalpha(48))
		ret = ft_error_ptr(48, ret, this_ptr, libc_ptr, 7); 
	if (ft_isalpha('0') != isalpha('0'))
		ret = ft_error_ptr('0', ret, this_ptr, libc_ptr, 8); 
	if (ft_isalpha(57) != isalpha(57))
		ret = ft_error_ptr(57, ret, this_ptr, libc_ptr, 9); 
	if (ft_isalpha('9') != isalpha('9'))
		ret = ft_error_ptr('9', ret, this_ptr, libc_ptr, 10); 
	if (ft_isalpha(1) != isalpha(1))
		ret = ft_error_ptr(1, ret, this_ptr, libc_ptr, 11); 
	if (ft_isalpha(0) != isalpha(0))
		ret = ft_error_ptr(0, ret, this_ptr, libc_ptr, 12); 
	if (ft_isalpha(42) != isalpha(42))
		ret = ft_error_ptr(42, ret, this_ptr, libc_ptr, 13); 
	if (ft_isalpha(2147483647) != isalpha(2147483647))
		ret = ft_error_ptr(2147483647, ret, this_ptr, libc_ptr, 14); 
	if (!ret)
		ft_putstr(GREEN"TESTS OK\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_isalpha\n");
}

// FT_ISDIGIT
void			ft_test_isdigit()
{
	int 		c;
	int 		ret;
	int 		(*this_ptr)(int);
	int 		(*libc_ptr)(int);

	ret = 0;
	c = '0';
	this_ptr = ft_isdigit;
	libc_ptr = isdigit;
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_isdigit\n");
	ft_putstr(CYAN"ft_isdigit (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_isdigit = "STOP); 
	while (c <= '9')
	{
		if (ft_isdigit(c) != isdigit(c))
			ret = ft_error_ptr(c, ret, this_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_isdigit(48) != isdigit(48))
		ret = ft_error_ptr(48, ret, this_ptr, libc_ptr, 1);
	if (ft_isdigit('0') != isdigit('0'))
		ret = ft_error_ptr('0', ret, this_ptr, libc_ptr, 2);
	if (ft_isdigit(57) != isdigit(57))
		ret = ft_error_ptr(57, ret, this_ptr, libc_ptr, 3);
	if (ft_isdigit('9') != isdigit('9'))
		ret = ft_error_ptr('9', ret, this_ptr, libc_ptr, 4);
	if (ft_isdigit('\0') != isdigit('\0'))
		ret = ft_error_ptr('\0', ret, this_ptr, libc_ptr, 5);
	if (ft_isdigit('a') != isdigit('a'))
		ret = ft_error_ptr('a', ret, this_ptr, libc_ptr, 6);
	if (ft_isdigit(97) != isdigit(97))
		ret = ft_error_ptr(97, ret, this_ptr, libc_ptr, 7);
	if (ft_isdigit('z') != isdigit('z'))
		ret = ft_error_ptr('z', ret, this_ptr, libc_ptr, 8);
	if (ft_isdigit(122) != isdigit(122))
		ret = ft_error_ptr(122, ret, this_ptr, libc_ptr, 9);
	if (ft_isdigit(1) != isdigit(1))
		ret = ft_error_ptr(1, ret, this_ptr, libc_ptr, 10);
	if (ft_isdigit(0) != isdigit(0))
		ret = ft_error_ptr(0, ret, this_ptr, libc_ptr, 11);
	if (ft_isdigit(127) != isdigit(127))
		ret = ft_error_ptr(127, ret, this_ptr, libc_ptr, 12);
	if (ft_isdigit(2147483647) != isdigit(2147483647))
		ret = ft_error_ptr(2147483647, ret, this_ptr, libc_ptr, 13);
	if (!ret)
		ft_putstr(GREEN"TESTS OK\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_isdigit\n");
}

// FT_ISALNUM
void			ft_test_isalnum()
{
	int 		c;
	int 		ret;
	int 		(*this_ptr)(int);
	int 		(*libc_ptr)(int);

	ret = 0;
	this_ptr = ft_isalnum;
	libc_ptr = isalnum;
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_isalnum\n");
	ft_putstr(CYAN"ft_isalnum (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_isalnum = "STOP); 
	if (ft_isalnum('a') != ft_isalnum('a'))
		ret = ft_error_ptr('a', ret, this_ptr, libc_ptr, 0);
	if (ft_isalnum(97) != ft_isalnum(97))
		ret = ft_error_ptr(97, ret, this_ptr, libc_ptr, 1);
	if (ft_isalnum('z') != ft_isalnum('z'))
		ret = ft_error_ptr('z', ret, this_ptr, libc_ptr, 2);
	if (ft_isalnum(122) != ft_isalnum(122))
		ret = ft_error_ptr(122, ret, this_ptr, libc_ptr, 3);
	if (ft_isalnum(48) != ft_isalnum(48))
		ret = ft_error_ptr(48, ret, this_ptr, libc_ptr, 4);
	if (ft_isalnum('0') != ft_isalnum('0'))
		ret = ft_error_ptr('0', ret, this_ptr, libc_ptr, 5);
	if (ft_isalnum(57) != ft_isalnum(57))
		ret = ft_error_ptr(57, ret, this_ptr, libc_ptr, 6);
	if (ft_isalnum('9') != ft_isalnum('9'))
		ret = ft_error_ptr('9', ret, this_ptr, libc_ptr, 7);
	c = '0';
	while (c++ <= '9')
	{
		if (ft_isalnum(c) != ft_isalnum(c))
			ret = ft_error_ptr('9', ret, this_ptr, libc_ptr, 8);
	}
	c = 'A';
	while (c++ <= 'Z')
	{
		if (ft_isalnum(c) != ft_isalnum(c))
			ret = ft_error_ptr(c, ret, this_ptr, libc_ptr, 9);
	}
	c = 'a';
	while (c++ <= 'z')
	{
		if (ft_isalnum(c) != ft_isalnum(c))
			ret = ft_error_ptr(c, ret, this_ptr, libc_ptr, 10);
	}
	if (ft_isalnum('\0') != isalnum('\0'))
		ret = ft_error_ptr('\0', ret, this_ptr, libc_ptr, 11);
	if (ft_isalnum(1) != isalnum(1))
		ret = ft_error_ptr(1, ret, this_ptr, libc_ptr, 12);
	if (ft_isalnum(40) != isalnum(40))
		ret = ft_error_ptr(40, ret, this_ptr, libc_ptr, 13);
	if (ft_isalnum(58) != isalnum(58))
		ret = ft_error_ptr(58, ret, this_ptr, libc_ptr, 14);
	if (ft_isalnum(92) != isalnum(92))
		ret = ft_error_ptr(92, ret, this_ptr, libc_ptr, 15);
	if (ft_isalnum(123) != isalnum(123))
		ret = ft_error_ptr(123, ret, this_ptr, libc_ptr, 16);
	if (ft_isalnum(0) != isalnum(0))
		ret = ft_error_ptr(0, ret, this_ptr, libc_ptr, 17);
	if (ft_isalnum(127) != isalnum(127))
		ret = ft_error_ptr(127, ret, this_ptr, libc_ptr, 18);
	if (ft_isalnum(2147483647) != isalnum(2147483647))
		ret = ft_error_ptr(2147483647, ret, this_ptr, libc_ptr, 19);
	if (!ret)
		ft_putstr(GREEN"TESTS OK\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_isalnum\n");
}

// FT_ISASCII
void			ft_test_isascii()
{	
	int 		c;
	int 		ret;
	int 		(*this_ptr)(int);
	int 		(*libc_ptr)(int);

	this_ptr = ft_isascii;
	libc_ptr = isascii;
	c = 0;
	ret = 0;
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_isascii\n");
	ft_putstr(CYAN"ft_isascii (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_isascii = "STOP); 
	while (c <= 127){
		if (ft_isascii(c) != isascii(c))
			ret = ft_error_ptr(c, ret, this_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_isascii(2147483647) != isascii(2147483647))
		ret = ft_error_ptr(2147483647, ret, this_ptr, libc_ptr, 1);
	if (ft_isascii(-1) != isascii(-1))
		ret = ft_error_ptr(-1, ret, this_ptr, libc_ptr, 2);
	if (ft_isascii(128) != isascii(128))
		ret = ft_error_ptr(128, ret, this_ptr, libc_ptr, 3);
	if (ft_isascii(2147483648) != isascii(2147483648))
		ret = ft_error_ptr(2147483648, ret, this_ptr, libc_ptr, 4);
	if (!ret)
		ft_putstr(GREEN"TESTS OK\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_ascii\n");
}

// FT_ISPRINT
void			ft_test_isprint()
{
	int 		c;
	int 		ret;
	int 		(*this_ptr)(int);
	int 		(*libc_ptr)(int);

	this_ptr = ft_isprint;
	libc_ptr = isprint;
	c = 32;
	ret = 0;
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_isprint\n");
	ft_putstr(CYAN"ft_isprint (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_isprint = "STOP); 
	while (c <= 126)
	{
		if (!ft_isprint(c))
			ret = ft_error_ptr(c, ret, this_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_isprint(0))
		ret = ft_error_ptr(0, ret, this_ptr, libc_ptr, 1);
	if (ft_isprint(27))
		ret = ft_error_ptr(27, ret, this_ptr, libc_ptr, 2);
	if (ft_isprint(31))
		ret = ft_error_ptr(31, ret, this_ptr, libc_ptr, 3);
	if (ft_isprint(4))
		ret = ft_error_ptr(4, ret, this_ptr, libc_ptr, 4);
	if (ft_isprint(2147483647))
		ret = ft_error_ptr(2147483647, ret, this_ptr, libc_ptr, 5);
	if (ft_isprint(-1))
		ret = ft_error_ptr(-1, ret, this_ptr, libc_ptr, 6);
	if (ft_isprint(128))
		ret = ft_error_ptr(128, ret, this_ptr, libc_ptr, 7);
	if (ft_isprint(127))
		ret = ft_error_ptr(127, ret, this_ptr, libc_ptr, 8);
	if (ft_isprint(30))
		ret = ft_error_ptr(30, ret, this_ptr, libc_ptr, 9);
	if (ft_isprint(2147483648))
		ret = ft_error_ptr(2147483648, ret, this_ptr, libc_ptr, 10);
	if (!ret)
		ft_putstr(GREEN"TESTS OK\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_isprint\n");
}

// FT_TOUPPER
void			ft_test_toupper()
{
	int 		c;
	int 		ret;
	int 		(*this_ptr)(int);
	int 		(*libc_ptr)(int);

	this_ptr = ft_toupper;
	libc_ptr = toupper;
	ret = 0;
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_toupper\n");
	ft_putstr(CYAN"ft_toupper (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_toupper = "STOP); 
	c = 'a';
	while (c <= 'z')
	{
		if (ft_toupper(c) != toupper(c))
			ret = ft_error_ptr(127, ret, this_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_toupper('A') != toupper('A'))
		ret = ft_error_ptr('A', ret, this_ptr, libc_ptr, 1);
	if (ft_toupper(12) != toupper(12))
		ret = ft_error_ptr(12, ret, this_ptr, libc_ptr, 2);
	if (ft_toupper(0) != toupper(0))
		ret = ft_error_ptr(0, ret, this_ptr, libc_ptr, 3);
	if (ft_toupper(-1) != toupper(-1))
		ret = ft_error_ptr(-1, ret, this_ptr, libc_ptr, 4);
	if (ft_toupper(4) != toupper(4))
		ret = ft_error_ptr(4, ret, this_ptr, libc_ptr, 5);
	if (ft_toupper(2147483648) != toupper(2147483648))
		ret = ft_error_ptr(2147483648, ret, this_ptr, libc_ptr, 6);
	if (ft_toupper(2147483647) != toupper(2147483647))
		ret = ft_error_ptr(2147483647, ret, this_ptr, libc_ptr, 7);
	if (ft_toupper(-2147483648) != toupper(-2147483648))
		ret = ft_error_ptr(-2147483648, ret, this_ptr, libc_ptr, 8);
	if (ft_toupper('\0') != toupper('\0'))
		ret = ft_error_ptr('\0', ret, this_ptr, libc_ptr, 9);
	c = 'A';
	while (c <= 'Z')
	{
		if (ft_toupper(c) != toupper(c))
			ret = ft_error_ptr(c, ret, this_ptr, libc_ptr, 10);
		c++;
	}
	if (!ret)
		ft_putstr(GREEN"TESTS OK\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_toupper\n");
}

// FT_TOLOWER
void			ft_test_tolower()
{
	int 		c;
	int 		ret;
	int 		(*this_ptr)(int);
	int 		(*libc_ptr)(int);

	this_ptr = ft_tolower;
	libc_ptr = tolower;
	ret = 0;
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_tolower\n");
	ft_putstr(CYAN"ft_tolower (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_tolower = "STOP); 
	c = 'a';
	while (c <= 'z')
	{
		if (ft_tolower(c) != tolower(c))
			ret = ft_error_ptr(127, ret, this_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_tolower('A') != tolower('A'))
		ret = ft_error_ptr('A', ret, this_ptr, libc_ptr, 1);
	if (ft_tolower(12) != tolower(12))
		ret = ft_error_ptr(12, ret, this_ptr, libc_ptr, 2);
	if (ft_tolower(0) != tolower(0))
		ret = ft_error_ptr(0, ret, this_ptr, libc_ptr, 3);
	if (ft_tolower(-1) != tolower(-1))
		ret = ft_error_ptr(-1, ret, this_ptr, libc_ptr, 4);
	if (ft_tolower(4) != tolower(4))
		ret = ft_error_ptr(4, ret, this_ptr, libc_ptr, 5);
	if (ft_tolower(2147483648) != tolower(2147483648))
		ret = ft_error_ptr(2147483648, ret, this_ptr, libc_ptr, 6);
	if (ft_tolower(2147483647) != tolower(2147483647))
		ret = ft_error_ptr(2147483647, ret, this_ptr, libc_ptr, 7);
	if (ft_tolower(-2147483648) != tolower(-2147483648))
		ret = ft_error_ptr(-2147483648, ret, this_ptr, libc_ptr, 8);
	if (ft_tolower('\0') != tolower('\0'))
		ret = ft_error_ptr('\0', ret, this_ptr, libc_ptr, 9);
	c = 'A';
	while (c <= 'Z')
	{
		if (ft_tolower(c) != tolower(c))
			ret = ft_error_ptr(c, ret, this_ptr, libc_ptr, 10);
		c++;
	}
	if (!ret)
		ft_putstr(GREEN"TESTS OK\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_tolower\n");
}

// FT_PUTS
void			ft_test_puts()
{
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_puts\n");
	ft_putstr(CYAN"str\033[0m = ");
	ft_putstr(RED"ft_putstr (c)"STOP);
	ft_putstr(" => ");
	ft_putstr(GREEN"ft_puts (asm)\n"STOP);
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr("str =   => ");
	ft_puts(GREEN" "STOP);
	ft_putstr("\n");
	ft_putstr("str = \033[1;31mWesh\033[0m => ");
	ft_puts(GREEN"Wesh"STOP);
	ft_putstr("\n");
	ft_putstr("str = \033[1;31mBrah\033[0m => ");
	ft_puts(GREEN"Brah"STOP);
	ft_putstr("\n");
	ft_putstr("str = \033[1;31mWazzzzzzzaaaaaaaa\033[0m => ");
	ft_puts(GREEN"Wazzzzzzzaaaaaaaa"STOP);
	ft_putstr("\n");
	ft_putstr("str = \033[1;31mZzZz\033[0m => ");
	ft_puts(GREEN"ZzZz"STOP);
	ft_putstr("\n");
	ft_putstr("str = \033[1;31m42\033[0m => ");
	ft_puts(GREEN"42"STOP);
	ft_putstr("\n");
	ft_putstr("str = \033[1;31mAaaaaaaaaaaaaaaaaaaaaaaaaaaaaA\033[0m => ");
	ft_puts(GREEN"AaaaaaaaaaaaaaaaaaaaaaaaaaaaaA"STOP);
	ft_putstr("\n");
	char *str = "Hello World";
	ft_putstr("str = \033[1;31m");
	ft_putstr(str);
	ft_putstr("\033[0m => ");
	ft_puts(GREEN);
	ft_puts(str);
	ft_puts(STOP);
	ft_putstr("\n");
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_puts\n");
}
	
// FT_STRLEN
void			ft_test_strlen()
{
	int 		ret;
	char 		*str;

	ret = 0;
	str = NULL;
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_strlen\n");
	ft_putstr(CYAN"ft_strlen (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_strlen = "STOP);
	str = "hello";
	if (strlen(str) != ft_strlen(str))
		ret = ft_error_strlen(ret, str, strlen(str), ft_strlen(str), 0);
	str = "hello World !";
	if (strlen(str) != ft_strlen(str))
		ret = ft_error_strlen(ret, str, strlen(str), ft_strlen(str), 1);
	str = "hello 42....";
	if (strlen(str) != ft_strlen(str))
		ret = ft_error_strlen(ret, str, strlen(str), ft_strlen(str), 2);
	str = "hello !";
	if (strlen(str) != ft_strlen(str))
		ret = ft_error_strlen(ret, str, strlen(str), ft_strlen(str), 3);
	str = "";
	if (strlen(str) != ft_strlen(str))
		ret = ft_error_strlen(ret, str, strlen(str), ft_strlen(str), 4);
	if (strlen("wesh") != ft_strlen("wesh"))
		ret = ft_error_strlen(ret, "wesh", strlen("wesh"), ft_strlen("wesh"), 5);
	if (strlen("") != ft_strlen(""))
		ret = ft_error_strlen(ret, "", strlen(""), ft_strlen(""), 6);
	if (strlen("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA") != ft_strlen("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA"))
		ret = ft_error_strlen(ret, "AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA", strlen("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA"), ft_strlen("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA"), 7);	// str2 = NULL;
	if (!ret)
		ft_putstr(GREEN"TESTS OK\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_strlen\n");
}

// FT_MEMCPY
void		ft_test_memcpy()
{
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_memcpy\n");
	ft_putstr(CYAN"ft_memcpy (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_memcpy  = "STOP);
	char strmem[] = "test memset";
	ft_memset(strmem, 'X', 3);
	if (!strcmp(strmem, "XXXt memset"))
		ft_putstr(GREEN"TESTS OK\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_memcpy\n");
}

// FT_MEMSET
void			ft_test_memset()
{
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_memset\n");
	ft_putstr(CYAN"ft_memset (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_memset  = "STOP);
	char strmemcp[] = "test memcpy";
	ft_memcpy(strmemcp, "wesh", 3);
	if (!strcmp(strmemcp, "west memcpy"))
		ft_putstr(GREEN"TESTS OK\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_memset\n");
}

// FT_STRLEN
void			ft_test_strdup()
{
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_strdup\n");
	ft_putstr(CYAN"ft_strdup (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_strdup  = "STOP);
	char *testdup = ft_strdup("Wesh cousin !");
	char *test = strdup("Wesh cousin !");
	if (!strcmp(testdup, test))
		ft_putstr(GREEN"TESTS OK\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_strdup\n");	
}

// FT_CAT
void			ft_test_cat()
{
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_cat\n");
	ft_putstr(CYAN"ft_cat (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr(BLUE"ft_cat = "STOP);
	ft_putstr(RED"Je n'ai pas su faire ft_cat :(\n"STOP);
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_cat\n");	
}

// FT_STRNEW
void			ft_test_strnew()
{
	int 		ret;

	ret = 0;
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_strnew\n");
	ft_putstr(CYAN"ft_strnew (asm)"STOP);
	ft_putstr(" = \033[1;32mTESTS OK\033[0m / \033[1;31mTEST KO\033[0m\n");
	ft_putstr(BLUE"***************************************************\n"STOP);

	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_strnew\n");	
}

// FT_PUTCHAR
void			ft_test_putchar()
{
	int 		i;

	i = 0;
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // TEST ft_putchar\n");
	ft_putstr(CYAN"c\033[0m = ");
	ft_putstr(RED"ft_putstr (c)"STOP);
	ft_putstr(" => ");
	ft_putstr(GREEN"ft_putchar (asm)"STOP);
	ft_putstr(YELLOW" => c_putchar"STOP);
	ft_putstr(" (cas spéciaux)\n");
	ft_putstr(BLUE"***************************************************\n"STOP);
	ft_putstr("c = '\033[1;31ma\033[0m' => ");
	ft_putstr(GREEN);
	ft_putchar('a');
	ft_putstr(STOP);
	ft_putstr("\n");
	ft_putstr("c = '\033[1;31mA\033[0m' => ");
	ft_putstr(GREEN);
	ft_putchar('A');
	ft_putstr(STOP);
	ft_putstr("\n");
	ft_putstr("c = \033[1;31m52\033[0m => ");
	ft_putstr(GREEN);
	ft_putchar(52);
	ft_putstr(STOP);
	ft_putstr("\n");
	ft_putstr("c = '\033[1;31m*\033[0m' => ");
	ft_putstr(GREEN);
	ft_putchar('*');
	ft_putstr(STOP);
	ft_putstr("\n");
	ft_putstr("c = '\033[1;31m9\033[0m' => ");
	ft_putstr(GREEN);
	ft_putchar(57);
	ft_putstr(STOP);
	ft_putstr("\n");
	ft_putstr("c = \033[1;31m41\033[0m => ");
	ft_putstr(GREEN);
	ft_putchar(41);
	ft_putstr(STOP);
	ft_putstr(YELLOW);
	ft_putstr(" => ");
	c_putchar(41);
	ft_putstr(STOP);
	ft_putstr("\n");
	ft_putstr("c = \033[1;31m123\033[0m => ");
	ft_putstr(GREEN);
	ft_putchar(123);
	ft_putstr(STOP);
	ft_putstr(YELLOW);
	ft_putstr(" => ");
	c_putchar(123);
	ft_putstr(STOP);
	ft_putstr("\n");
	ft_putstr("c = \033[1;31m4\033[0m => ");
	ft_putstr(GREEN);
	ft_putchar(4);
	ft_putstr(STOP);
	ft_putstr(YELLOW);
	ft_putstr(" => ");
	c_putchar(4);
	ft_putstr(STOP);
	ft_putstr("\n");
	ft_putstr("c = \033[1;31m127\033[0m => ");
	ft_putstr(GREEN);
	ft_putchar(127);
	ft_putstr(STOP);
	ft_putstr(YELLOW);
	ft_putstr(" => ");
	c_putchar(127);
	ft_putstr(STOP);
	ft_putstr("\n");
	char *str = strdup("Hello 42");
	ft_putstr("str = '");
	while(str[i])
	{
		ft_putstr(RED);
		c_putchar(str[i]);
		ft_putstr(STOP);
		i++;
	}
	ft_putstr("' => ");
	i = 0;
	while(str[i])
	{
		ft_putstr(GREEN);
		ft_putchar(str[i]);
		ft_putstr(STOP);
		i++;
	}
	ft_putstr("\n");
	ft_putstr(PURPLE"***************************************************"STOP);
	ft_putstr(" // FIN TEST ft_putchar\n");
}

int 			main(int ac, char **av)
{
	if (ac != 2)
		ft_putstr("Usage: ./a.out -full (ou nom de la fonction/partie ex: -puts, -part1)\n");
	if (ac == 2)
	{
		if (!strcmp(av[1], "-full"))
		{
			ft_putstr(YELLOW"Partie Obligatoire (partie 1)\n"STOP);
			ft_test_bzero();
			ft_test_isalpha();
			ft_test_isdigit();
			ft_test_isalnum();
			ft_test_isascii();
			ft_test_isprint();
			ft_test_toupper();
			ft_test_tolower();
			ft_test_puts();
			ft_putstr(YELLOW"Partie Obligatoire (partie 2)\n"STOP);
			ft_test_strlen();
			ft_test_memcpy();
			ft_test_memset();
			//ft_test_strdup();
			ft_putstr(YELLOW"Partie Obligatoire (partie 3)\n"STOP);
			ft_test_cat();
			ft_putstr(YELLOW"Partie Bonus\n"STOP);
			//ft_test_putchar();
		}
		else if (!strcmp(av[1], "-part1"))
		{
			ft_putstr(YELLOW"Partie Obligatoire (partie 1)\n"STOP);
			ft_test_bzero();
			ft_test_isalpha();
			ft_test_isdigit();
			ft_test_isalnum();
			ft_test_isascii();
			ft_test_isprint();
			ft_test_toupper();
			ft_test_tolower();
			ft_test_puts();
		}
		else if (!strcmp(av[1], "-part2"))
		{
			ft_putstr(YELLOW"Partie Obligatoire (partie 2)\n"STOP);
			ft_test_strlen();
			ft_test_memcpy();
			ft_test_memset();
			//ft_test_strdup();
		}
		else if (!strcmp(av[1], "-part3"))
		{
			ft_putstr(YELLOW"Partie Obligatoire (partie 3)\n"STOP);
			ft_test_cat();
		}
		else if (!strcmp(av[1], "-bonus"))
		{
			ft_putstr(YELLOW"Partie Bonus\n"STOP);
			//ft_test_putchar();
		}
		else if (!strcmp(av[1], "-bzero"))
			ft_test_bzero();
		else if (!strcmp(av[1], "-isalpha"))
			ft_test_isalpha();
		else if (!strcmp(av[1], "-isdigit"))
			ft_test_isdigit();
		else if (!strcmp(av[1], "-isalnum"))
			ft_test_isalnum();
		else if (!strcmp(av[1], "-isascii"))
			ft_test_isascii();
		else if (!strcmp(av[1], "-isprint"))
			ft_test_isprint();
		else if (!strcmp(av[1], "-toupper"))
			ft_test_toupper();
		else if (!strcmp(av[1], "-tolower"))
			ft_test_tolower();
		else if (!strcmp(av[1], "-strlen"))
			ft_test_strlen();
		else if (!strcmp(av[1], "-memcpy"))
			ft_test_memcpy();
		else if (!strcmp(av[1], "-memset"))
			ft_test_memset();
		else if (!strcmp(av[1], "-strdup"))
			ft_test_strdup();
		else if (!strcmp(av[1], "-puts"))
			ft_test_puts();
		else if (!strcmp(av[1], "-cat"))
			ft_test_cat();
		else if (!strcmp(av[1], "-putchar"))
			ft_test_putchar();
		else
			ft_putstr("Le nom de la fonction on a dit...(-puts / -isascii / -strlen / etc...)\n");
	}
	return(0);
}