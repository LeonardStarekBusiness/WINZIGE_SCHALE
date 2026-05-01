/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:51:14 by lstarek           #+#    #+#             */
/*   Updated: 2026/01/22 15:51:29 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

typedef unsigned short	u16_t;
typedef unsigned char	status_t;

typedef struct s_command
{
	char				*command;
	int					ac;
	char				**argv;
	struct s_command	*pipe_output_to;
	int					fd_in;
	int					fd_out;
}						t_command;

int						ft_strcmp(const char *s1, const char *s2);

status_t				ft_echo(t_command *cmd);
status_t				ft_cd(t_command *cmd);
status_t				ft_pwd(t_command *cmd);
status_t				ft_export(t_command *cmd);
status_t				ft_unset(t_command *cmd);
status_t				ft_env(t_command *cmd);
status_t				ft_exit(t_command *cmd);

char					*get_input(int fd);

#endif