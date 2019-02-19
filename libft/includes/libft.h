/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:00:32 by schakor           #+#    #+#             */
/*   Updated: 2019/02/16 13:55:35 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "get_next_line.h"
# include <stdint.h>

/*
**		MEMORY FUNCTIONS
*/

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t n);
void				ft_memdel(void **ap);

/*
**		STRING FUNCTIONS
*/

size_t				ft_wslen(char *str);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *h, const char *n);
char				*ft_strnstr(const char *h, const char *n, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t n);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinjoin(char *s1, char *s2, char *s3);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strfjoin(char *s1, char *s2, int opt);

/*
**		UTF-8 STRING FUNCTIONS
*/

size_t				ft_u8_strlen(const uint8_t *s);
uint8_t				*ft_u8_strdup(const uint8_t *s);
uint8_t				*ft_u8_strcpy(uint8_t *dst, const uint8_t *src);
uint8_t				*ft_u8_strncpy(uint8_t *dst, const uint8_t *src, size_t n);
uint8_t				*ft_u8_strcat(uint8_t *dst, const uint8_t *src);
uint8_t				*ft_u8_strncat(uint8_t *dst, const uint8_t *src, size_t n);
int					ft_u8_strcmp(const uint8_t *s1, const uint8_t *s2);
int					ft_u8_strncmp(const uint8_t *s1, const uint8_t *s2, \
		size_t n);
uint8_t				*ft_u8_strnew(size_t n);
void				ft_u8_strdel(uint8_t **as);
int					ft_u8_strequ(uint8_t const *s1, uint8_t const *s2);
uint8_t				*ft_u8_strjoin(uint8_t const *s1, uint8_t const *s2);
uint8_t				*ft_u8_strfjoin(uint8_t *s1, uint8_t *s2, \
		int opt);
uint8_t				**ft_u8_strsplit(uint8_t const *s, uint8_t c);

/*
**		CHAR ** FUNCTIONS
*/

size_t				ft_arrlen(char **arr);
char				**ft_arrdup(char **arr);
void				ft_arrdel(char **arr);

/*
**		ARRAY OF UTF-8 STRING FUNCTIONS
*/

size_t				ft_u8_arrlen(uint8_t **arr);
uint8_t				**ft_u8_arrdup(uint8_t **arr);
void				ft_u8_arrdel(uint8_t **arr);

/*
**		CONVERSION FUNCTIONS
*/

int					ft_atoi(const char *s);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_itoa(int n);

/*
**		TYPE FUNCTIONS
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
char				*ft_strtolower(char *str);
int					ft_isquote(int c);
int					ft_isescaped(char *s, int index);
int					ft_isnotprint(int c);
int					ft_first_char_unicode(int c);

/*
**		OUTPUT FUNCTIONS
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putu8str(uint8_t const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putnbrendl(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbrendl_fd(int n, int fd);

/*
**		MATHS FUNCTIONS
*/

int					ft_abs(int n);
int					ft_min(int x, int y);
int					ft_max(int x, int y);

/*
**		LINKED LISTS FUNCTIONS
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstlen(t_list *lst);
void				ft_lstaddlast(t_list **alst, t_list *new);

#endif
