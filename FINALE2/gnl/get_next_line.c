/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:35:36 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/01/27 16:13:45 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		return_zero(char *str)
{
	if (!str)
	{
		free(str);
		return (1);
	}
	return (0);
}

char	*get_save(char *str)
{
	int		i;
	char	*nstr;
	int		j;

	if (return_zero(str))
		return (0);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	if (!(nstr = malloc(sizeof(char) * (ft_strlen(str) - i + 1))))
		return (0);
	i++;
	while (str[i])
		nstr[j++] = str[i++];
	nstr[j] = '\0';
	free(str);
	return (nstr);
}

char	*get_line(char *str)
{
	int		i;
	char	*nstr;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(nstr = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		nstr[i] = str[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char *save;
	int			reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!has_return(save) && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		save = join_str(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = get_save(save);
	if (reader == 0)
		return (0);
	return (1);
}
