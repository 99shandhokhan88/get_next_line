/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:27:54 by vzashev           #+#    #+#             */
/*   Updated: 2023/04/06 16:47:51 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (ch == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)ch)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *res, char *temp)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!res)
	{
		res = (char *)malloc(1 * sizeof(char));
		res[0] = '\0';
	}
	if (!res || !temp)
		return (NULL);
	j = 0;
	i = -1;
	str = malloc((ft_strlen(res) + ft_strlen(temp) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (res[++i])
		str[i] = res[i];
	while (temp[j])
		str[i++] = temp[j++];
	str[i] = '\0';
	free(res);
	return (str);
}
