/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:20:24 by mbilly            #+#    #+#             */
/*   Updated: 2023/03/30 10:46:03 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	create_file_heredoc(".heredoc", argv);
	open_files_heredoc(&pipex, ".heredoc", argv[argc - 1]);
	pipex.nb_cmd = argc - 4;
	pipex.heredoc = 1;
	pipex.pipe = (int *)malloc(sizeof(int) * (2 * (pipex.nb_cmd - 1)));
	create_pipes(&pipex);
	pipex.iter = -1;
	while (++pipex.iter < pipex.nb_cmd)
		pipe_chaine(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	unlink(".heredoc");
	free_pipes(&pipex);
}
