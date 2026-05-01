/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:02:00 by lstarek           #+#    #+#             */
/*   Updated: 2026/05/01 14:02:01 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

status_t ft_unset(t_command *cmd)
{
    return(printf("unset: %s\n", cmd->argv[1]));
}

status_t ft_env(t_command *cmd)
{
    return(printf("env: %s\n", cmd->argv[1]));
}

status_t ft_exit(t_command *cmd)
{
    status_t    status;
    char        *numberified;

    if (cmd->fd_in != 0 || cmd->fd_out != 1)
        return 1;
    if (cmd->ac == 0)
        exit(0);
    if (cmd->ac != 1)
    {
        ft_putstr_fd("exit: too many arguments\n", cmd->fd_out);
        exit(1);
    }
    status = (status_t)ft_atoi(cmd->argv[0]);
    numberified = ft_itoa(ft_atoi(cmd->argv[0]));
    if (ft_strcmp(numberified, cmd->argv[0]))
    {
        ft_putstr_fd("exit: ", cmd->fd_out);
        ft_putstr_fd(cmd->argv[0], cmd->fd_out);
        ft_putstr_fd(": numeric argument required\n", cmd->fd_out);
        status = 2;
    }
    free(numberified);
    exit(status);
}
