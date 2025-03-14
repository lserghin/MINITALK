#include "minitalk_bonus.h"

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
		g_acknowledgment = 2;
	else if (signal == SIGUSR1)
		g_acknowledgment = 1;
	return ;
}

void	ft_kill(pid_t pid, int signal)
{
	if (kill(pid, signal) < 0)
		return (ft_putstr_fd("Error: kill failed!\n", 2), exit(EXIT_FAILURE));
}

void	ft_send_byte(unsigned char c, pid_t pid)
{
	int	bit_mask;

	bit_mask = 128;
	while (bit_mask)
	{
		g_acknowledgment = 0;
		if ((c / bit_mask) % 2)
			ft_kill(pid, SIGUSR2);
		else
			ft_kill(pid, SIGUSR1);
		bit_mask /= 2;
		while (g_acknowledgment != 2)
		{
			if (g_acknowledgment == 1)
				return ;
			usleep(1337);
		}
	}
	return ;
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;

	if (ac != 3)
	{
		ft_putstr_fd("Error: type->./client_bonus <server PID> <message>\n", 2);
		return (1);
	}
	pid = ft_atoi(*(av + 1));
	if (!ft_check_pid(*(av + 1)) || pid <= 0)
		return (ft_putstr_fd("Error: PID not valid!\n", 2), 1);
	signal(SIGUSR2, ft_handle_ack);
	signal(SIGUSR1, ft_handle_ack);
	message = *(av + 2);
	while (*message)
	{
		ft_send_byte(*message, pid);
		message++;
	}
	ft_send_byte('\0', pid);
	if (g_acknowledgment == 1)
		ft_printf("Message has been sent succesfully!\n");
	return (0);
}
