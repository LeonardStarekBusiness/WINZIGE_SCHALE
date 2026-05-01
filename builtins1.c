/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:01:20 by lstarek           #+#    #+#             */
/*   Updated: 2026/05/01 14:01:25 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

status_t ft_echo(t_command *cmd)
{
    u16_t   flag_n;
    int     i;

    flag_n = 0;
    i = 0;
    if (cmd->argv && !ft_strcmp(cmd->argv[0], "-n"))
    {
        flag_n = 1;
        i++;
    }
    while (cmd->argv && i < cmd->ac)
    {
        ft_putstr_fd(cmd->argv[i], cmd->fd_out);
        if (i < (cmd->ac - 1))
            ft_putstr_fd(" ", cmd->fd_out);
        i++;
    }
    if (!flag_n)
        ft_putstr_fd("\n", cmd->fd_out);
    return (0);
}

status_t ft_cd(t_command *cmd)
{
    return(printf("cd 2: %s\n", cmd->argv[1]));
}

status_t ft_pwd(t_command *cmd)
{
    char    path[PATH_MAX];

    getcwd(path, PATH_MAX);
    ft_putstr_fd(path, cmd->fd_out);
    ft_putstr_fd("\n", cmd->fd_out);
    return (0);
}

status_t ft_export(t_command *cmd)
{
    return(printf("export: %s\n", cmd->argv[1]));
}

