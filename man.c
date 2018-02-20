/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 11:49:30 by dlinkin           #+#    #+#             */
/*   Updated: 2017/11/19 11:51:17 by dlinkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
int		df;

void	first(char *file)
{
	char	*line;
	int		fd;
	int		ret_c;
	int		err;

	ret_c = 0;
	err = 0;
	ft_putendl("===File with 4 lines, 1 empty");
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ret_c == 0 && ft_strcmp(line, "ABCDEFGHIJKL") != 0)
			err++;
		if (ret_c == 1 && ft_strcmp(line, "MNOP") != 0)
			err++;
		if (ret_c == 2 && ft_strcmp(line, "") != 0)
			err++;
		if (ret_c == 3 && ft_strcmp(line, "QRSTUVWXYZ") != 0)
			err++;
		ret_c++;
	}
	if (ret_c != 4)
		ft_putendl("Wrong number of '1' :(");
	if (err > 0)
		ft_putendl("Wrong output in line :(");
	if (ret_c == 4 && err == 0)
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
}

void	second(char *file)
{
	char	*line;
	int		fd;
	int		ret_c;
	int		err;

	ret_c = 0;
	err = 0;
	ft_putendl("===File with 2 lines");
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ret_c == 0 && ft_strcmp(line, "ABCDEFGHIJKLMNOPQR") != 0)
			err++;
		if (ret_c == 1 && ft_strcmp(line, "STUVWXYZ") != 0)
			err++;
		ret_c++;
	}
	if (ret_c != 2)
		ft_putendl("Wrong number of '1' :(");
	if (err > 0)
		ft_putendl("Wrong output in line :(");
	if (ret_c == 2 && err == 0)
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
}

void	third(char *file)
{
	char	*line;
	int		fd;
	int		ret_c;
	int		err;

	ret_c = 0;
	err = 0;
	ft_putendl("===File with 1 line");
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ret_c == 0 && ft_strcmp(line, "ABCDEFGHIJKLMNO") != 0)
			err++;
		ret_c++;
	}
	if (ret_c != 1)
		ft_putendl("Wrong number of '1' :(");
	if (err > 0)
		ft_putendl("Wrong output in line :(");
	if (ret_c == 1 && err == 0)
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
}

void	fourth(char *file)
{
	char	*line;
	int		fd;
	int		ret_c;
	int		err;

	ret_c = 0;
	err = 0;
	ft_putendl("===File with 4 little lines");
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ret_c == 0 && ft_strcmp(line, "A") != 0)
			err++;
		if (ret_c == 1 && ft_strcmp(line, "BCD") != 0)
			err++;
		if (ret_c == 2 && ft_strcmp(line, "EFGH") != 0)
			err++;
		if (ret_c == 3 && ft_strcmp(line, "IJ") != 0)
			err++;
		ret_c++;
	}
	if (ret_c != 4)
		ft_putendl("Wrong number of '1' :(");
	if (err > 0)
		ft_putendl("Wrong output in line :(");
	if (ret_c == 4 && err == 0)
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
}

void	fifth(char *file)
{
	char	*line;
	int		fd;
	int		ret_c;
	int		err;

	ret_c = 0;
	err = 0;
	ft_putendl("===File with 1 line without new line");
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ret_c == 0 && ft_strcmp(line, "ABCDEFGH") != 0)
			err++;
		ret_c++;
	}
	if (ret_c != 1)
		ft_putendl("Wrong number of '1' :(");
	if (err > 0)
		ft_putendl("Wrong output in line :(");
	if (ret_c == 1 && err == 0)
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
}

void	sixth(char *file)
{
	char	*line;
	int		fd;
	int		ret_c;
	int		err;

	ret_c = 0;
	err = 0;
	ft_putendl("===File with 2 lines without new line");
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ret_c == 0 && ft_strcmp(line, "ABCDEF") != 0)
			err++;
		if (ret_c == 1 && ft_strcmp(line, "GHIJK") != 0)
			err++;
		ret_c++;
	}
	if (ret_c != 2)
		ft_putendl("Wrong number of '1' :(");
	if (err > 0)
		ft_putendl("Wrong output in line :(");
	if (ret_c == 2 && err == 0)
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
}

void	seven(char *file)
{
	char	*line;
	int		fd;

	ft_putendl("===Empty file Oo");
	fd = open(file, O_RDONLY);
	if (get_next_line(fd, &line) != 0)
		ft_putendl("You didn't return zero :O");
	else
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
}

void	eight(char *file)
{
	char	*line;
	int		fd;
	int		ret_c;
	int		err;

	ret_c = 0;
	err = 0;
	ft_putendl("===Just new line in file");
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ret_c == 0 && ft_strcmp(line, "") != 0)
			err++;
		ret_c++;
	}
	if (ret_c != 1)
		ft_putendl("Wrong number of '1' :(");
	if (err > 0)
		ft_putendl("Wrong output in line :(");
	if (ret_c == 1 && err == 0)
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
}

void	big_file(char *file)
{
	char	*ln;
	int		fd;
	int		ret_c;
	int		err;

	ret_c = 0;
	err = 0;
	ft_putendl("===Big file - big lines");
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &ln) > 0)
	{
		if (ret_c == 0 && ft_strcmp(ln, "The first parameter is the file descriptor that will be used to read.") != 0)
			err++;
		if (ret_c == 1 && ft_strcmp(ln, "The second parameter is the address of a pointer to a character that will be used to save the line read from the file descriptor.") != 0)
			err++;
		if (ret_c == 2 && ft_strcmp(ln, "The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed, or if an error has happened respectively.") != 0)
			err++;
		if (ret_c == 3 && ft_strcmp(ln, "Your function get_next_line must return its result without new line.") != 0)
			err++;
		if (ret_c == 4 && ft_strcmp(ln, "Calling your function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.") != 0)
			err++;
		if (ret_c == 5 && ft_strcmp(ln, "Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection etc.") != 0)
			err++;
		ret_c++;
	}
	if (ret_c != 6)
		ft_putendl("Wrong number of '1' :(");
	if (err > 0)
		ft_putendl("Wrong output in line :(");
	if (ret_c == 6 && err == 0)
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
}

void	rly_big_file(char *file)
{
	char	*line;
	int		fd;
	int		ret_c;
	int		err;

	ret_c = 0;
	err = 0;
	ft_putendl("===Its a REALY BIG FILE.. 1000 lines, without new line");
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strcmp(line, ft_itoa(ret_c + 1)) != 0)
			err++;
		ret_c++;
	}
	if (ret_c != 1000)
		ft_putendl("Wrong number of '1' :(");
	if (err > 0)
		ft_putendl("Wrong output in line :(");
	if (ret_c == 1000 && err == 0)
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
}

void	long1(char *file)
{
	char	*line;
	int		fd;
	int		ret_c;
	int		err;

	ret_c = 0;
	err = 0;
	ft_putendl("===Very long file with new line");
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strcmp(line, "euiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuy") != 0)
			err++;
		ret_c++;
	}
	if (ret_c != 1)
		ft_putendl("Wrong number of '1' :(");
	if (err > 0)
		ft_putendl("Wrong output in line :(");
	if (ret_c == 1 && err == 0)
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
}

void	long2(char *file)
{
	char	*line;
	int		fd;
	int		ret_c;
	int		err;

	ret_c = 0;
	err = 0;
	ft_putendl("===..and without");
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strcmp(line, "euiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuyeuiycrtcencotnytqntcnynycenycnyinctincineruierueiurycentiurytcnieurytueicneurytcieurnctuerycntiurtyceiurnctiuerycntueirytcnuerctiuerytcnieurycntiuerycnieurctieurycnteucntuercntuercnuienrcteurctuirycintercnterctyiuerycntuiercntuierycntuiercnterucntuierytcneurycntueryntcnertciurutcneruceurncturtyueirtyuerytieuytueyrteuirtyeiuryteiuryteiurytieurytueiryteiuryteiuryteiurytieurytieuryteiuryteiurtyeiuryteiurytieruytiertiuyertiuyertiuyertiueyrtiueyrtiuyertiuyertiuyertiueyrtiuyertiuyertiuyertiueyrtiueyrtiuyertiueyrtiuyertiuyertiuyertiuyertiuyertiueyrtiuyertiuyertiueyrtiuerytiuertiuyertiueyrtiueyrtiuyertiuy") != 0)
			err++;
		ret_c++;
	}
	if (ret_c != 1)
		ft_putendl("Wrong number of '1' :(");
	if (err > 0)
		ft_putendl("Wrong output in line :(");
	if (ret_c == 1 && err == 0)
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
}

void	multiple(void)
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
	fd1 = open("./files/file", O_RDONLY);
	fd2 = open("./files/file2", O_RDONLY);
	fd3 = open("./files/file5", O_RDONLY);
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
	{
		df++;
		ft_putendl("OK :D");
	}	
	close(fd1);
	close(fd2);
	close(fd3);
}

int		main(void)
{
	char	*file = "./files/empty";
	char	*file1 = "./files/file";
	char	*file2 = "./files/file2";
	char	*file3 = "./files/file3";
	char	*file4 = "./files/file4";
	char	*file5 = "./files/file5";
	char	*file6 = "./files/file6";
	char	*file8 = "./files/big_file1";
	char	*file7 = "./files/file7";
	char	*line;
	int		fd;

	df = 0;
	ft_putendl("===invalid fd");
	if (get_next_line(-4, &line) != -1)
		ft_putendl("Where is -1, Billy?");
	else
	{
		df++;
		ft_putendl("OK :D");
	}
	ft_putendl("===another one");
	if (get_next_line(3, &line) != -1)
		ft_putendl("Where is -1, Billy?");
	else
	{
		df++;
		ft_putendl("OK :D");
	}
	ft_putendl("===NULL into argument. Keep away children and pregnants");
	fd = open(file1, O_RDONLY);
	if (get_next_line(fd, NULL) != -1)
		ft_putendl("Noooooooo");
	else
	{
		df++;
		ft_putendl("OK :D");
	}
	close(fd);
	seven(file);
	eight(file7);
	third(file3);
	second(file2);
	fourth(file4);
	first(file1);
	fifth(file5);
	sixth(file6);
	big_file(file8);
	rly_big_file("./files/rly_big_file");
	long1("./files/long_file1");
	long2("./files/long_file2");
	multiple();
	if (df == 16)
		ft_putendl("~~Kwak~~");
	else
	{
		ft_putchar('<');
		ft_putstr("Number of KO = ");
		ft_putnbr(16 - df);
		ft_putendl(">");
	}
	return (0);
}
