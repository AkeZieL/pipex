/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:10:14 by mbilly            #+#    #+#             */
/*   Updated: 2023/03/30 10:47:53 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

void	free_pipes(t_pipex *pipex)
{
	close(pipex->file1);
	close(pipex->file2);
	free(pipex->pipe);
}

void	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nb_cmd - 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
		{
			free_pipes(pipex);
			msg_error("Pipe failed");
		}
		i++;
	}
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < 2 * (pipex->nb_cmd - 1))
	{
		close(pipex->pipe[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
		{
			here_doc(argc, argv, envp);
			return (0);
		}
		open_files(&pipex, argv[1], argv[argc - 1]);
		pipex.nb_cmd = argc - 3;
		pipex.heredoc = 0;
		pipex.pipe = (int *)malloc(sizeof(int) * (2 * (pipex.nb_cmd - 1)));
		create_pipes(&pipex);
		pipex.iter = -1;
		while (++pipex.iter < pipex.nb_cmd)
			pipe_chaine(pipex, argv, envp);
		close_pipes(&pipex);
		waitpid(-1, NULL, 0);
		free_pipes(&pipex);
	}
	else
		msg_error("Wrong input");
}
