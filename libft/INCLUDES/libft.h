/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:31:58 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/31 12:10:24 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//\\=====================================================================\\//

# include <stdlib.h>
# include <unistd.h>

//\\=====================================================================\\//

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//\\=====================================================================\\//

void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_putendl_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_bzero(void *s, size_t n);
void			ft_putnbr_fd(int n, int fd);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_isalnum(unsigned char c);
int				ft_isalpha(unsigned char c);
int				ft_isascii(unsigned char c);
int				ft_isdigit(unsigned char c);
int				ft_isprint(unsigned char c);
int				ft_atoi(const char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strrchr(const char *s, int c);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_itoa(int n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);

//\\==============================BONUS===================================\\//

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);

//\\==============================SF_DLC===================================\\//

int				ft_putnbr(int n);
int				ft_isspace(char c);
int				len_int(long int n);
int				ft_putchar(const char c);
int				ft_putstr(const char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strstr(char *str, char *to_find);

#endif
