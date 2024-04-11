/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:06:02 by mbilly            #+#    #+#             */
/*   Updated: 2023/03/30 10:54:26 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		file1;
	int		file2;
	int		iter;
	int		heredoc;
	int		nb_cmd;
	int		*pipe;
	pid_t	process;
}t_pipex;

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	open_files(t_pipex *pipex, char *fd1, char *fd2);
void	create_file_heredoc(char *fd1, char **argv);
void	here_doc(int argc, char **argv, char **envp);
void	open_files_heredoc(t_pipex *pipex, char *fd1, char *fd2);
void	free_pipes(t_pipex *pipex);
void	create_pipes(t_pipex *pipex);
void	msg_error(char *s);
void	close_pipes(t_pipex *pipex);
void	pipe_chaine(t_pipex pipex, char **argv, char **envp);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t size);

#endif
