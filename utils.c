/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:02:27 by lstarek           #+#    #+#             */
/*   Updated: 2026/05/01 14:02:29 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}

char    *get_input(int fd)
{
    char    *input;
    char    *tmp;
    char    readbuf[BUFFER_SIZE + 1];
    int     br;
    int     i;

    input = malloc(BUFFER_SIZE + 1);
    br = read(fd, input, BUFFER_SIZE);
    input[br] = 0;
    while (br > 0)
    {
        tmp = malloc(ft_strlen(input) + 1);
        i = -1;
        while (input[++i])
            tmp[i] = input[i];
        tmp[i] = 0;
        br = read(fd, readbuf, BUFFER_SIZE);
        readbuf[br] = 0;
        free(input);
        input = ft_strjoin(tmp, readbuf);
        ft_bzero(readbuf, BUFFER_SIZE + 1);
        free(tmp);
    }
    return (input);
}
