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

int		handle_memory_helper(char **line, size_t plus_size, size_t prev_size)
{
	char	temp_str[prev_size];

	if (!prev_size)
	{
		if ((*line = (char*)malloc(sizeof(char) * plus_size)))
			return (1);
	}
	else
	{
		ft_strcpy(temp_str, *line);
		ft_strclr(*line);
		ft_strdel(line);
		if ((*line = (char*)malloc(sizeof(char) * plus_size + prev_size)))
		{
			ft_strcpy(*line, temp_str);
			return (1);
		}
	}
	return (0);
}

int		handle_memory(char **line, size_t plus_size)
{
	size_t	prev_size;
	int		mem_res;

	if (!*line)
		prev_size = 0;
	else
		prev_size = ft_strlen(*line);
	mem_res = handle_memory_helper(line, plus_size, prev_size);
	return (mem_res);
}

t_list1		*create_elem(int fd, char buffer[BUFF_SIZE + 1], int *error)
{
	t_list1	*elem;

	if (!(elem = (t_list1*)malloc(sizeof(t_list1))))
	{
		*error = -1;
		return (0);
	}
	ft_strcpy(elem->content, buffer);
	elem->list_fd = fd;
	elem->next = NULL;
	return (elem);
}

t_list1		*read_to_buff(int fd, char buffer[BUFF_SIZE + 1], t_list1 *first, int *error)
{
	int		read_res;
	t_list1	*temp;

	read_res = read(fd, buffer, BUFF_SIZE);
	if (read_res > 0)
		buffer[read_res] = '\0';
	else
	{
		*error = 0;
		return (0);
	}
	temp = NULL;
	if (!first)
	{
		if ((first = create_elem(fd, buffer, error)))
			return (first);
	}
	else
	{
		temp = first;
		while (temp)
		{
			if (fd == temp->list_fd)
			{
				ft_strcpy(temp->content, buffer);
				return (temp);
			}
			temp = temp->next;
		}
		if ((temp = create_elem(fd, buffer, error)))
		{
			temp->next = first;
			first = temp;
		}
	}
	return (temp);
}

int		get_next_line_helper(const int fd, char **line)
{
	char				*nl_point;
	int					error;
	char				buffer[BUFF_SIZE + 1];
	static t_list1		*first;

	if (!first || !first->content[0])
	{
		if (!first)
			first = NULL;
		if (!(first = read_to_buff(fd, buffer, first, &error)))
			return (error);
	}
	if ((nl_point = ft_strchr(first->content, '\n')))
	{
		if (!(handle_memory(line, nl_point - first->content)))
			return (-1);
		ft_strncat(*line, buffer, nl_point - first->content);
		ft_memmove(first->content, nl_point + 1, ft_strlen(first->content) -
		(nl_point - first->content));
		return (1);
	}
	if (!(handle_memory(line, ft_strlen(first->content))))
		return (-1);
	ft_strncat(*line, first->content, ft_strlen(first->content));
	ft_strclr(first->content);
	get_next_line_helper(fd, line);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int		res;

	if (fd < 0)
		return (-1);
	if (!line)
		return (-1);
	if (*line)
		*line = NULL;
	res = get_next_line_helper(fd, line);
	printf("%s\n", *line);
	return (res);
}
