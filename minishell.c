/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:49:41 by lstarek           #+#    #+#             */
/*   Updated: 2026/01/22 15:51:10 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

u16_t	connect_pipes(t_command *top_cmd)
{
	t_command	*cmd;
	int			pipe_pair[2];
	
	cmd = top_cmd;
	cmd->fd_in = 0;
	while(cmd->pipe_output_to)
	{
		if (pipe(pipe_pair) != 0)
			return 1;
		cmd->fd_out = pipe_pair[1];
		cmd->pipe_output_to->fd_in = pipe_pair[0];
		cmd = cmd->pipe_output_to;
	}
	cmd->fd_out = 1;
	return 0;
}

void	execute(t_command *cmd)
{
	if (!ft_strcmp(cmd->command, "echo"))
		ft_echo(cmd);
	else if (!ft_strcmp(cmd->command, "cd"))
		ft_cd(cmd);
	else if (!ft_strcmp(cmd->command, "pwd"))
		ft_pwd(cmd);
	else if (!ft_strcmp(cmd->command, "export"))
		ft_export(cmd);
	else if (!ft_strcmp(cmd->command, "unset"))
		ft_unset(cmd);
	else if (!ft_strcmp(cmd->command, "env"))
		ft_env(cmd);
	else if (!ft_strcmp(cmd->command, "exit"))
		ft_exit(cmd);
	if (cmd->pipe_output_to)
		execute(cmd->pipe_output_to);
}

int	main(void)
{
	char *argv[1] = {"164"};
	//t_command exit2 = {"exit", 0, NULL, NULL, 0, 1};
	t_command exit = {"exit", 1, argv, NULL, 0, 1};

	if (connect_pipes(&exit))
		return 1;
	execute(&exit);
	return (0);
}
