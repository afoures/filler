/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:30:43 by afoures           #+#    #+#             */
/*   Updated: 2017/12/10 18:34:28 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstsearch(t_list **alst, size_t fd)
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(alst, tmp);
	return (*alst);
}

static int		ft_lstrmone(t_list **alst, t_list *del)
{
	t_list	*tmp;

	tmp = *alst;
	if (del == tmp)
	{
		*alst = del->next;
		ft_memdel(&del->content);
		ft_strdel((char **)&del);
		return (0);
	}
	while (tmp->next != del)
		tmp = tmp->next;
	tmp->next = del->next;
	ft_memdel(&del->content);
	ft_strdel((char **)&del);
	return (0);
}

static char		*ft_strnjoinfree(char const *s1, char const *s2, int len2
	, int n)
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
	if (n == 1 || n == 3)
		ft_strdel((char **)&s1);
	if (n == 2 || n == 3)
		ft_strdel((char **)&s2);
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*cur;
	char			buf[BUFF_SIZE + 1];
	char			*nl;
	int				i;

	if (!line || BUFF_SIZE <= 0 || (i = read(fd, buf, 0)) < 0)
		return (-1);
	cur = ft_lstsearch(&lst, fd);
	while ((nl = ft_strchr(cur->content, '\n'))
		|| (i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (nl)
		{
			*line = ft_strsub(cur->content, 0, nl - (char *)cur->content);
			return ((ft_strcpy(cur->content, nl + 1)) ? 1 : 1);
		}
		cur->content = ft_strnjoinfree(cur->content, buf, i, 1);
	}
	if (ft_strlen(cur->content) && (*line = ft_strdup(cur->content)))
	{
		ft_strclr(cur->content);
		return (1);
	}
	return ((i < 0) ? -1 : ft_lstrmone(&lst, cur));
}
