/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:31:08 by salabbe           #+#    #+#             */
/*   Updated: 2025/03/05 09:31:21 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	stash = gen_stash(stash, fd);
	if (stash == NULL || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash, line);
	if (line == NULL || line[0] == '\0')
	{
		free(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}

char	*gen_stash(char *stash, int fd)
{
	char	*buff;
	int		i;

	i = BUFFER_SIZE;
	while (!gnl_isnewline(stash) && i == BUFFER_SIZE)
	{
		buff = gnl_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1 || (stash == NULL && i == 0))
		{
			free(stash);
			free(buff);
			return (NULL);
		}
		stash = gnl_strjoin(stash, buff);
		free(buff);
	}
	return (stash);
}

char	*extract_line(char *stash, char *line)
{
	int		i;

	i = 0;
	line = gen_line(stash, line);
	if (!line)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			line[i] = stash[i];
			break ;
		}
		line[i] = stash[i];
		i++;
	}
	return (line);
}

char	*gen_line(char *stash, char *line)
{
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line = gnl_calloc(sizeof(char), i + 1);
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (i != gnl_strlen(stash))
		tmp = gnl_calloc(sizeof(char), (gnl_strlen(stash) - i) + 1);
	else
	{
		tmp = NULL;
		free(stash);
		stash = NULL;
		return (NULL);
	}
	i++;
	while (stash[i] != '\0')
		tmp[j++] = stash[i++];
	free(stash);
	stash = NULL;
	return (tmp);
}
