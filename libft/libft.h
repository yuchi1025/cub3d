/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:00:57 by yucchen           #+#    #+#             */
/*   Updated: 2026/01/12 15:51:18 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdarg.h> // va_list
# include <stdint.h> // uintptr_t
# include <stdlib.h> // malloc, free, exit
# include <unistd.h> // write, read, close, pipe, fork, dup2, execve

/* ------------------------------ */
/*         Character Check        */
/* ------------------------------ */

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/* ------------------------------ */
/*         Memory Functions       */
/* ------------------------------ */

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);

/* ------------------------------ */
/*        String Functions        */
/* ------------------------------ */

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/* ------------------------------ */
/*       Numeric Conversion       */
/* ------------------------------ */

int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);

/* ------------------------------ */
/*     File Descriptor Output     */
/* ------------------------------ */

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/* ------------------------------ */
/*        Linked List Bonus       */
/* ------------------------------ */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* ------------------------------ */
/*        ft_printf & utils       */
/* ------------------------------ */

int					ft_putchar(unsigned char c);
int					ft_putnbr(int n);
int					ft_putunsignednbr(unsigned int u);
int					ft_puthexalower(unsigned int x);
int					ft_puthexaupper(unsigned int X);
int					ft_putptr(uintptr_t ptr);
int					ft_printf(const char *format, ...);

/* ------------------------------ */
/*         get_next_line          */
/* ------------------------------ */

char				*get_next_line(int fd, char **storage);
void				gnl_clean(char **storage);

#endif
