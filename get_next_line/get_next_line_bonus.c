/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:27:52 by vzashev           #+#    #+#             */
/*   Updated: 2023/04/06 16:45:28 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_write_next_line(char *new_line)
{
	char	*next_line;
	int		i;

	i = 0;
	if (!new_line[i])
		return (NULL);
	while (new_line[i] && new_line[i] != '\n')
		i++;
	next_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!next_line)
		return (NULL);
	i = 0;
	while (new_line[i] && new_line[i] != '\n')
	{
		next_line[i] = new_line[i];
		i++;
	}
	if (new_line[i] == '\n')
	{
		next_line[i] = new_line[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*ft_get_new_line(char *new_line)
{
	char	*return_new_line;
	int		i;
	int		j;
	char	*x;

	i = 0;
	while (new_line[i] && new_line[i] != '\n')
		i++;
	if (!new_line[i])
	{
		free(new_line);
		return (NULL);
	}
	x = (char *)malloc(sizeof(char) * (ft_strlen(new_line) - i + 1));
	return_new_line = x;
	if (!return_new_line)
		return (NULL);
	i++;
	j = 0;
	while (new_line[i])
		return_new_line[j++] = new_line[i++];
	return_new_line[j] = '\0';
	free (new_line);
	return (return_new_line);
}

char	*ft_read_new_line(int fd, char *new_line)
{
	char	*temp_buff;
	int		bytes;

	temp_buff = malloc(BUFFER_SIZE + 1);
	if (!temp_buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(new_line, '\n') && bytes != 0)
	{
		bytes = read(fd, temp_buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (temp_buff);
			return (NULL);
		}
		temp_buff[bytes] = '\0';
		new_line = ft_strjoin(new_line, temp_buff);
	}
	free (temp_buff);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*new_line[4096];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	new_line[fd] = ft_read_new_line(fd, new_line[fd]);
	if (!new_line[fd])
		return (NULL);
	next_line = ft_write_next_line(new_line[fd]);
	new_line[fd] = ft_get_new_line(new_line[fd]);
	return (next_line);
}
