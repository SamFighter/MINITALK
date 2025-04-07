/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:24 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/14 10:27:16 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

//\\=========================LIBRARY=========================//

# include <unistd.h>
# include <stdlib.h>

//\\=======================FUNCTION=========================//

int				gnl_strlen(const char *str);
int				gnl_isnewline(const char *s);
char			*get_next_line(int fd);
char			*clean_stash(char *stash);
char			*gen_stash(char *stash, int fd);
char			*gen_line(char *stash, char *line);
char			*extract_line(char *stash, char *line);
char			*gnl_strjoin(char *s1, char const *s2);
void			*gnl_calloc(size_t nmemb, size_t size);

#endif