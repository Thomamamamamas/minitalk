/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:54:24 by tcasale           #+#    #+#             */
/*   Updated: 2022/01/16 15:23:29 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, int c)
{
	int	n;

	n = 0;
	while (n < c)
	{
		kill(pid, SIGUSR1);
		n++;
	}
	kill(pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	n;
	size_t	len;

	if (argc < 3)
		return (1);
	pid = ft_atoi(argv[1]);
	n = 0;
	len = ft_strlen(argv[2]);
	while (n < len)
	{
		send_char(pid, argv[2][n]);
		n++;
	}
	return (0);
}
