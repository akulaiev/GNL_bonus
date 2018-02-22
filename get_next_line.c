/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:29:12 by akulaiev          #+#    #+#             */
/*   Updated: 2018/01/23 17:29:14 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_realloc(char *line, size_t old, size_t new)
{
	char *temp;

	if ((new == 0 || new <= old) && line)
		return (line);
	if (!line)
		return (ft_memalloc(new + 1));
	temp = (char*)malloc(new + 1);
	ft_strcpy(temp, line);
	free(line);
	return (temp);
}

int			get_next_line_h(const int fd, char **l, char buf[BUFF_SIZE + 1])
{
	char		*np;
	int			read_res;

	if (!buf[0])
	{
		if ((read_res = read(fd, buf, BUFF_SIZE)) > 0)
			buf[read_res] = '\0';
		else
			return (read_res);
	}
	if ((np = ft_strchr(buf, '\n')))
	{
		if (!(*l = ft_realloc(*l, ft_strlen(*l), ft_strlen(*l) + np - buf)))
			return (-1);
		ft_strncat(*l, buf, np - buf);
		ft_memmove(buf, np + 1, ft_strlen(buf) - (np - buf));
		return (1);
	}
	if (!(*l = ft_realloc(*l, ft_strlen(*l), ft_strlen(*l) + ft_strlen(buf))))
		return (-1);
	ft_strcat(*l, buf);
	ft_strclr(buf);
	get_next_line_h(fd, l, buf);
	return (1);
}

t_list1		*create_elem(int fd, t_list1 *elem)
{
	if (!(elem = (t_list1*)malloc(sizeof(t_list1))))
		return (NULL);
	elem->content[0] = '\0';
	elem->list_fd = fd;
	return (elem);
}

int			get_next_line(const int fd, char **line)
{
	static t_list1	*first;
	t_list1			*current_elem;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	if (!first)
	{
		if (!(first = create_elem(fd, first)))
			return (-1);
		first->next = NULL;
	}
	current_elem = first;
	while (current_elem)
	{
		if (current_elem->list_fd == fd)
			return (get_next_line_h(fd, line, current_elem->content));
		current_elem = current_elem->next;
	}
	if (!(current_elem = create_elem(fd, current_elem)))
		return (-1);
	current_elem->next = first;
	first = current_elem;
	return (get_next_line_h(fd, line, current_elem->content));
}
