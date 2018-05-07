/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:30:43 by afoures           #+#    #+#             */
/*   Updated: 2018/03/12 14:51:36 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strnjoinfree(char const *s1, char const *s2, int len2)
{
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + len2 + 1))))
		return (NULL);
	res = ft_strcpy(res, (char *)s1);
	res = ft_strncat(res, (char *)s2, len2);
	ft_strdel((char **)&s1);
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static char		*content = NULL;
	char			buf[BUFF_SIZE + 1];
	char			*nl;
	int				i;

	if (!line || BUFF_SIZE <= 0 || (i = read(fd, buf, 0)) < 0)
		return (-1);
	while ((nl = ft_strchr(content, '\n'))
		|| (i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (nl)
		{
			*line = ft_strsub(content, 0, nl - content);
			ft_strcpy(content, nl + 1);
			return (1);
		}
		content = ft_strnjoinfree(content, buf, i);
	}
	if (ft_strlen(content) && (*line = ft_strdup(content)))
	{
		ft_strclr(content);
		return (1);
	}
	return ((i < 0) * -1);
}
