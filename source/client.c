/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:09:07 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 17:09:07 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_acknowledgment;

int	ft_check_pid(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	ft_handle_ack(int signal)
{
	if (signal == SIGUSR2)
		g_acknowledgment = 1;
	return ;
}

void	ft_send_byte(unsigned char c, pid_t pid)
{
	int	bit_mask;

	bit_mask = 128;
	while (bit_mask)
	{
		g_acknowledgment = 0;
		if ((c / bit_mask) % 2)
		{
			if (kill(pid, SIGUSR2) < 0)
				return (printf("Error: kill failed!\n"), exit(EXIT_FAILURE));
		}
		else
		{
			if (kill(pid, SIGUSR1) < 0)
				return (printf("Error: kill failed!\n"), exit(EXIT_FAILURE));
		}
		bit_mask /= 2;
		if (g_acknowledgment != 1)
			usleep(1337);
	}
	return ;
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;

	if (ac != 3)
	{
		ft_putstr_fd("Error: type->./client <server PID> <message>\n", 2);
		return (1);
	}
	pid = ft_atoi(*(av + 1));
	if (!ft_check_pid(*(av + 1)) || pid <= 0)
		return (ft_putstr_fd("Error: PID not valid!\n", 2), 1);
	signal(SIGUSR2, ft_handle_ack);
	message = *(av + 2);
	while (*message)
		ft_send_byte(*message++, pid);
	ft_send_byte('\0', pid);
	return (0);
}
