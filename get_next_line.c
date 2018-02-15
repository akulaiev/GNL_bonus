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
	t_list1	*new_elem;

	read_res = read(fd, buffer, BUFF_SIZE);
	if (read_res > 0)
		buffer[read_res] = '\0';
	else
	{
		*error = 0;
		return (0);
	}
	new_elem = NULL;
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
		if ((new_elem = create_elem(fd, buffer, error)))
		{
			temp->next = new_elem;
			new_elem->next = NULL;
		}
	}
	return (new_elem);
}

int		get_next_line_helper(const int fd, char **line, t_list1	*read_res)
{
	char				*nl_point;
	int					error;
	char				buffer[BUFF_SIZE + 1];
	static t_list1		*buff;

	if (!buff)
	{
		if (!(read_res = read_to_buff(fd, buffer, buff, &error)))
			return (error);
	}
	if ((nl_point = ft_strchr(read_res->content, '\n')))
	{
		if (!(handle_memory(line, nl_point - read_res->content)))
			return (-1);
		ft_strncat(*line, buffer, nl_point - read_res->content);
		ft_memmove(read_res->content, nl_point + 1, ft_strlen(read_res->content) -
		(nl_point - read_res->content));
		return (1);
	}

	if (!(handle_memory(line, ft_strlen(read_res->content))))
		return (-1);
	ft_strncat(*line, read_res->content, ft_strlen(read_res->content));
	ft_strclr(read_res->content);
	get_next_line_helper(fd, line, read_res);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int		res;
	t_list1	*read_res;

	if (fd < 0)
		return (-1);
	if (!line)
		return (-1);
	if (*line)
		*line = NULL;
	read_res = NULL;
	res = get_next_line_helper(fd, line, read_res);
	printf("%s\n", *line);
	return (res);
}
