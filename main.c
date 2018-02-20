/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:29:31 by akulaiev          #+#    #+#             */
/*   Updated: 2018/01/23 17:29:34 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int fd1;
	int fd2;
	int fd3;
	char *line;
	int err;
	int ret_c;

	err = 0;
	ret_c = 0;
	ft_putendl("===Multiple file descriptors");
	fd1 = open("./file", O_RDONLY);
	fd2 = open("./file2", O_RDONLY);
	fd3 = open("./file5", O_RDONLY);
	if (get_next_line(fd1, &line) > 0)
	{
		if (ret_c == 0 && ft_strcmp(line, "ABCDEFGHIJKL") != 0)
			err++;
		ret_c++;
	}
	if (get_next_line(fd2, &line) > 0)
	{
		if (ret_c == 1 && ft_strcmp(line, "ABCDEFGHIJKLMNOPQR") != 0)
			err++;
		ret_c++;
	}
	if (get_next_line(fd1, &line) > 0)
	{
		if (ret_c == 2 && ft_strcmp(line, "MNOP") != 0)
			err++;
		ret_c++;
	}
	if (get_next_line(fd3, &line) > 0)
	{
		if (ret_c == 3 && ft_strcmp(line, "ABCDEFGH") != 0)
			err++;
		ret_c++;
	}
	if (get_next_line(fd1, &line) > 0)
	{
		if (ret_c == 4 && ft_strcmp(line, "") != 0)
			err++;
		ret_c++;
	}
	if (get_next_line(fd2, &line) > 0)
	{
		if (ret_c == 5 && ft_strcmp(line, "STUVWXYZ") != 0)
			err++;
		ret_c++;
	}
	if (err > 0)
		ft_putendl("Error? Multiple fd not suported? :(");
	if (ret_c != 6)
		ft_putendl("Wrong number of '1' :(");
	if (ret_c == 6 && err == 0)
		ft_putendl("OK :D");	
	close(fd1);
	close(fd2);
	close(fd3);
	// int			fd;
	// char		*line;
	// int			res;

	// if (argc > 1)
	// {
	// 	fd = open(argv[1], O_RDONLY);
	// 	if (fd <= 0)
	// 	{
	// 		printf("error: not a valid file\n");
	// 		return (0);
	// 	}
	// 	while ((res = get_next_line(fd, &line)))
	// 	{
	// 		if (res == 1)
	// 			printf("%s #\n", line);
	// 	}
	// 	if (res == 0)
	// 		printf("EOF\n");
	// 	if (res == -1)
	// 		printf("error\n");
	// 	close(fd);
	// 	system("leaks test_gnl");
	// 	return (0);
	// }
}