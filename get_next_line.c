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

	if (!*line)
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

int		get_next_line_helper(const int fd, char **line, char buffer[BUFF_SIZE + 1])
{
	char		*nl_point;
	int			read_res;

	if (!buffer[0])
	{
		read_res = read(fd, buffer, BUFF_SIZE);
		if (read_res > 0)
			buffer[read_res] = '\0';
		else
			return (read_res);
	}
	if ((nl_point = ft_strchr(buffer, '\n')))
	{
		if (!(handle_memory(line, nl_point - buffer)))
			return (-1);
		ft_strncat(*line, buffer, nl_point - buffer);
		ft_memmove(buffer, nl_point + 1, ft_strlen(buffer) -
		(nl_point - buffer));
		return (1);
	}
	if (!(handle_memory(line, ft_strlen(buffer))))
		return (-1);
	ft_strncat(*line, buffer, ft_strlen(buffer));
	ft_strclr(buffer);
	get_next_line_helper(fd, line, buffer);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				read_res;
	static t_list1	*first;
	t_list1			*current_elem;

	if (fd < 0 || !line)
		return (-1);
	if (*line)
		*line = NULL;
	if (!first)
	{
		if (!(first = (t_list1*)malloc(sizeof(t_list1))))
			return (-1);
		if ((read_res = read(fd, first->content, BUFF_SIZE)) > 0)
		{
			first->content[read_res] = '\0';
			first->list_fd = fd;
			first->next = NULL;
			current_elem = first;
		}
		else
		{
			free(first);
			return (read_res);
		}
	}
	if (first && first->list_fd == fd)
		current_elem = first;
	if (first && first->list_fd != fd)
	{
		current_elem = first;
		while (current_elem->next)
		{	
			if (current_elem->list_fd == fd)
			{
				read_res = get_next_line_helper(fd, line, current_elem->content);
				return (read_res);
			}
			current_elem = current_elem->next;
		}
		if (current_elem->list_fd != fd)
		{
			if (!(current_elem = (t_list1*)malloc(sizeof(t_list1))))
				return (-1);
			if ((read_res = read(fd, current_elem->content, BUFF_SIZE)) > 0)
			{
				current_elem->content[read_res] = '\0';
				current_elem->list_fd = fd;
				current_elem->next = first;
				first = current_elem;
			}
			else
			{
				free(current_elem);
				return (read_res);
			}
		}
	}
	read_res = get_next_line_helper(fd, line, current_elem->content);
	return (read_res);
}
