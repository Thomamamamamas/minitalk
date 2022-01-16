/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:23:12 by tcasale           #+#    #+#             */
/*   Updated: 2022/01/16 15:23:27 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int	printer[2];

void	sig_handler(int sig_num)
{
	if (sig_num == SIGUSR1)
	{
		printer[1] = printer[1] + 1;
	}
	else
	{
		printer[0] = 1;
	}
}

int	main()
{
	struct sigaction	sig;

	sig.sa_handler = sig_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_putstr_fd("Le PID du server est : ", 1);
	ft_putnbr_fd((int)getpid(), 1);
	printer[0] = 0;
	printer[1] = 0;
	while (1)
	{
		if (printer[0] == 1)
		{
			printf("%d\n", printer[1]);
			ft_putchar_fd(printer[1], 1);
			printer[0] = 0;
			printer[1] = 0;
		}
	}
}
