/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:29:23 by akulaiev          #+#    #+#             */
/*   Updated: 2018/01/23 17:29:24 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 3

# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef	struct s_list1
{
	char			content[BUFF_SIZE + 1];
	int				list_fd;
	struct s_list1	*next;
}				t_list1;

int		get_next_line(const int fd, char **line);

#endif
