/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:09:09 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/18 01:54:24 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handle_signal(int signal, siginfo_t *info, void *context)
{
	static char		c;
	static int		bit_read;
	static pid_t	client_pid;

	(void)context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		bit_read = 0;
		c = 0;
	}
	c = c * 2 + (signal == SIGUSR2);
	bit_read++;
	if (bit_read == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		bit_read = 0;
		c = 0;
	}
	if (kill(client_pid, SIGUSR2) < 0)
		return (ft_putstr_fd("Error: kill failed!\n", 2), exit(1));
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		return (ft_putstr_fd("Error: type->./server\n", 2), 1);
	pid = getpid();
	ft_printf("Server pid : %d\n", pid);
	sa.sa_sigaction = ft_handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) < 0
		|| sigaction(SIGUSR2, &sa, NULL) < 0)
		return (ft_putstr_fd("Error: sigaction failed!\n", 2), 1);
	while (1337)
		pause();
	return (0);
}
