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
#include <stdio.h>

char		*ft_realloc(char *line, size_t old, size_t new)
{
	char *temp;

	if ((new == 0 || new <= old) && line)
		return (line);
	if (!line)
		return (ft_memalloc(new));
	temp = (char*)malloc(new);
	ft_strcpy(temp, line);
	free(line);
	return (temp);
}

int			get_next_line_h(const int fd, char **line, char buf[BUFF_SIZE + 1])
{
	char		*nl_point;
	int			read_res;

	if (!buf[0])
	{
		read_res = read(fd, buf, BUFF_SIZE);
		if (read_res > 0)
			buf[read_res] = '\0';
		else
			return (read_res);
	}
	if ((nl_point = ft_strchr(buf, '\n')))
	{
		if (!(*line = ft_realloc(*line, ft_strlen(*line), nl_point - buf)))
			return (-1);
		ft_strncat(*line, buf, nl_point - buf);
		ft_memmove(buf, nl_point + 1, ft_strlen(buf) - (nl_point - buf));
		return (1);
	}
	if (!(*line = ft_realloc(*line, ft_strlen(*line), ft_strlen(buf))))
		return (-1);
	ft_strncat(*line, buf, ft_strlen(buf));
	ft_strclr(buf);
	get_next_line_h(fd, line, buf);
	return (1);
}

t_list1		*create_elem(int fd, t_list1 *elem, t_list1 *first, int *error)
{
	elem = NULL;
	if (!first)
	{
		if (!(elem = (t_list1*)malloc(sizeof(t_list1))))
		{
			*error = -1;
			return (NULL);
		}
		elem->content[0] = '\0';
		elem->list_fd = fd;
		elem->next = NULL;
	}
	else
	{
		if (!(elem = (t_list1*)malloc(sizeof(t_list1))))
		{
			*error = -1;
			return (NULL);
		}
		elem->content[0] = '\0';
		elem->list_fd = fd;
		elem->next = first;
	}
	return (elem);
}

int			get_next_line(const int fd, char **line)
{
	int				error;
	static t_list1	*first;
	t_list1			*current_elem;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	current_elem = NULL;
	if (!first)
	{
		if (!(first = create_elem(fd, current_elem, first, &error)))
			return (error);
	}
	current_elem = first;
	while (current_elem->next)
	{
		if (current_elem->list_fd == fd)
			return (get_next_line_h(fd, line, current_elem->content));
		current_elem = current_elem->next;
	}
	if ((current_elem = create_elem(fd, current_elem, first, &error)))
		first = current_elem;
	else
		return (error);
	return (get_next_line_h(fd, line, current_elem->content));
}
