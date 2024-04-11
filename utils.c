/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:02:49 by mbilly            #+#    #+#             */
/*   Updated: 2023/03/30 10:52:48 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_file_heredoc(char *fd1, char **argv)
{
	int		tmp;
	char	*line;

	tmp = open(fd1, O_CREAT | O_TRUNC | O_WRONLY, \
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (tmp < 0)
		msg_error("Open failed file 1");
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (line == NULL)
			exit(1);
		if (ft_strncmp(argv[2], line, ft_strlen(argv[2])) == 0)
		{
			free(line);
			break ;
		}
		write(tmp, line, ft_strlen(line));
		write(tmp, "\n", 1);
		free(line);
	}
	close(tmp);
}

void	open_files_heredoc(t_pipex *pipex, char *fd1, char *fd2)
{
	pipex->file1 = open(fd1, O_RDONLY);
	if (pipex->file1 < 0)
	{
		unlink(fd1);
		msg_error("Open failed file 1");
	}
	pipex->file2 = open(fd2, O_WRONLY | O_CREAT | O_TRUNC, \
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (pipex->file2 < 0)
		msg_error("Open failed file 2");
}

void	open_files(t_pipex *pipex, char *fd1, char *fd2)
{
	pipex->file1 = open(fd1, O_RDONLY);
	if (pipex->file1 < 0)
		msg_error("Open failed file 1");
	pipex->file2 = open(fd2, O_WRONLY | O_CREAT | O_TRUNC, \
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (pipex->file2 < 0)
		msg_error("Open failed file 2");
}
