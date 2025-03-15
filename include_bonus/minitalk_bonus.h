/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:06:21 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 22:56:51 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <../libft/libft.h>

void	ft_handle_signal(int signal, siginfo_t *info, void *context);
void	ft_send_byte(unsigned char c, pid_t pid);
void	ft_kill(pid_t pid, int signal);
void	ft_handle_ack(int signal);
int		ft_check_pid(char *str);

#endif
