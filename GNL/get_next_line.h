/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:15:16 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/01/22 19:15:37 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

int					get_next_line(int fd, char **line);
int					has_return(char *str);

size_t				ft_strlen(const char *s);

char				*join_str(const char *s1, const char *s2);
//#include    "get_next_line_utils.c"
//#include    "get_next_line.c"

#endif
