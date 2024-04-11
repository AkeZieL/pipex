/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:19:25 by mbilly            #+#    #+#             */
/*   Updated: 2023/03/30 10:49:14 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*command(char **arg, char **envp)
{
	char	**tmp;
	int		i;

	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	tmp = ft_split(*envp + 5, ':');
	i = 0;
	while (tmp[i])
	{
		tmp[i] = ft_strjoin(tmp[i], "/");
		if (access(ft_strjoin(tmp[i], arg[0]), 0) == 0)
			return (ft_strjoin(tmp[i], arg[0]));
		i++;
	}
	return (NULL);
}

static void	exec_cmd(t_pipex pipex, char **argv, char **envp)
{
	int		i;
	char	*cmd;
	char	**cmd_arg;

	cmd_arg = ft_split(argv[2 + pipex.iter + pipex.heredoc], ' ');
	cmd = command(cmd_arg, envp);
	if (cmd == NULL)
	{
		i = 0;
		while (cmd_arg[i])
			free(cmd_arg[i++]);
		free(cmd_arg);
		msg_error("Wrong command");
		exit(1);
	}
	execve(cmd, cmd_arg, envp);
}

void	pipe_chaine(t_pipex pipex, char **argv, char **envp)
{
	pipex.process = fork();
	if (pipex.process == 0)
	{
		if (pipex.iter == 0)
		{
			dup2(pipex.file1, 0);
			dup2(pipex.pipe[1], 1);
		}
		else if (pipex.iter == pipex.nb_cmd - 1)
		{
			dup2(pipex.pipe[2 * pipex.iter - 2], 0);
			dup2(pipex.file2, 1);
		}
		else
		{
			dup2(pipex.pipe[2 * pipex.iter - 2], 0);
			dup2(pipex.pipe[2 * pipex.iter + 1], 1);
		}
		close_pipes(&pipex);
		exec_cmd(pipex, argv, envp);
	}
}
