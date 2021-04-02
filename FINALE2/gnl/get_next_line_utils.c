/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:47:08 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/01/27 14:59:39 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *s;
	unsigned char *d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}

char	*join_str(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	len_tot;
	char	*nstr;

	if (!s1 && !s2)
		return (0);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	len_tot = len1 + len2;
	if (!(nstr = malloc(sizeof(char) * (len_tot + 1))))
		return (0);
	ft_memmove(nstr, s1, len1);
	ft_memmove(nstr + len1, s2, len2);
	nstr[len_tot] = '\0';
	free((char *)s1);
	return (nstr);
}

int		has_return(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
